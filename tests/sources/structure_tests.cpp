#include <catch2/catch_all.hpp>

#include <zollstock/tests/required_features.hpp>
#include <zollstock/tests/string_utils.hpp>
#include <zollstock/tests/stream_utils.hpp>
#include <zollstock/tests/config.hpp>

#include <algorithm>
#include <filesystem>
#include <ranges>
#include <regex>
#include <vector>
#include <string>
#include <fstream>


namespace fs = std::filesystem;
namespace rng = std::ranges;


using header_set = std::set<fs::path>;
using header_dependencies = std::vector<std::pair<fs::path, fs::path>>;


const std::string header_file_extension = ".hpp";
const std::regex snake_case{ "[a-z]+(_[a-z0-9]+)*" };
const std::regex header_include_prefix{ "^\\s*#\\s*include" };
const std::regex header_include{ "#include\\s<([^\\>]+)>" };


[[nodiscard]] bool is_header_include(const std::string& line)
{
    return std::regex_search(line, header_include_prefix);
}

[[nodiscard]] auto derive_include_guard_name(const fs::path& header_path)
{
    std::string include_guard = "__";

    for(const auto& part : header_path.parent_path())
    {
        include_guard += toupper(part.string());
        include_guard += "_";
    }

    include_guard += toupper(header_path.stem().string());
    include_guard += "_";
    include_guard += toupper(header_path.extension().string().substr(1));
    include_guard += "__";

    return include_guard;
}

[[nodiscard]] auto analyse_header_content(const fs::path& header_path, const fs::path& root_dir)
{
    CAPTURE(header_path);

    REQUIRE(root_dir.is_absolute());
    REQUIRE(header_path.is_absolute());
    REQUIRE(fs::is_regular_file(header_path));

    const auto relative_header_path = fs::relative(header_path, root_dir);

    CAPTURE(relative_header_path);

    REQUIRE(header_path.extension() == header_file_extension);
    REQUIRE(std::regex_match(header_path.stem().string(), snake_case));

    std::ifstream header_stream{ header_path };

    REQUIRE(header_stream.is_open());

    const auto include_guard_name = derive_include_guard_name(relative_header_path);
    const auto lines = read_lines(header_stream);

    header_stream.close();

    REQUIRE(lines[0] == "#ifndef " + include_guard_name);
    REQUIRE(lines[1] == "#define " + include_guard_name);
    REQUIRE(lines[2] == ""                             );
    REQUIRE(lines[3] == ""                             );

    header_set include_paths;

    for(std::size_t line_pos = 4; line_pos < lines.size() - 3; ++line_pos)
    {
        if (is_header_include(lines[line_pos]))
        {
            std::smatch matches;

            CAPTURE(line_pos);
            CAPTURE(lines[line_pos]);
            REQUIRE(std::regex_match(lines[line_pos], matches, header_include));

            REQUIRE(matches.size() == 2);
            include_paths.insert(fs::path{ matches.str(1) });
        }
    }

    REQUIRE(lines[lines.size() - 3] == ""                              );
    REQUIRE(lines[lines.size() - 2] == ""                              );
    REQUIRE(lines[lines.size() - 1] == "#endif //" + include_guard_name);

    return include_paths;
}

[[nodiscard]] auto header_includes_from_path(
    const fs::path& root_dir,
    const fs::path& header_path
)
{
    return analyse_header_content(header_path, root_dir)
        | rng::views::filter([](const auto& path){ return path.extension() == ".hpp"; })
        | rng::views::transform([&](fs::path include_path){
            return std::pair{
                fs::relative(header_path, root_dir),
                include_path.make_preferred()
            };
        });
}

[[nodiscard]] auto collect_direct_header_dependencies(fs::path root_dir)
{
    REQUIRE(fs::is_directory(root_dir));

    header_dependencies includes;

    rng::copy(
        fs::recursive_directory_iterator(root_dir)
            | rng::views::transform(std::mem_fn(&fs::directory_entry::path))
            | rng::views::filter([](const auto& path){ return fs::is_regular_file(path); })
            | rng::views::filter([](const auto& path){ return path.extension() == ".hpp"; })
            | rng::views::transform(std::bind_front(header_includes_from_path, root_dir))
            | rng::views::join
        , std::inserter(includes, std::end(includes))
    );

    rng::sort(includes);

    return includes;
}

[[nodiscard]] header_set follow_include(
    const header_dependencies& dependencies, const fs::path& header_path
)
{
    auto[first, last] = rng::equal_range(
        dependencies,
        header_path,
        rng::less{},
        &header_dependencies::value_type::first
    );

    auto direct_includes = rng::subrange(first, last) | std::views::values;

    const auto follow_indirect_include = [&dependencies](const auto& indirect_include)
    {
        return follow_include(dependencies, indirect_include);
    };

    auto indirect_includes = direct_includes
                           | rng::views::transform(follow_indirect_include)
                           | rng::views::join;

    header_set result;

    rng::copy(direct_includes  , std::inserter(result, rng::end(result)));
    rng::copy(indirect_includes, std::inserter(result, rng::end(result)));

    return result;
}

header_dependencies follow_includes(const header_dependencies& direct_dependencies)
{
    header_dependencies all_dependencies{ direct_dependencies };

    for (const auto&[header_path, include_path] : direct_dependencies)
    {
        for (const auto& include : follow_include(direct_dependencies, include_path))
        {
            all_dependencies.insert(
                std::end(all_dependencies),
                header_dependencies::value_type{ header_path, include }
            );
        }
    }

    return all_dependencies;
}

[[nodiscard]] std::string header_to_feature(fs::path header)
{
    std::string feature{ header.string() };

    std::ranges::replace(feature,  fs::path::preferred_separator, '.');

    auto suffix_start_pos = feature.find_last_of('.');

    return feature.substr(0, suffix_start_pos);
}

[[nodiscard]] std::pair<std::string, std::string> header_to_feature_entry(
    const std::pair<fs::path, fs::path>& entry
)
{
    return {
        header_to_feature(entry.first ),
        header_to_feature(entry.second)
    };
}

[[nodiscard]] feature_dependencies header_to_feature_deps(
    const header_dependencies& header_deps
)
{
    feature_dependencies feature_deps;

    feature_deps.reserve(rng::size(header_deps));

    rng::copy(
        header_deps | rng::views::transform(header_to_feature_entry),
        std::back_inserter(feature_deps)
    );

    rng::sort(feature_deps);

    return feature_deps;
}


TEST_CASE("structure-tests", "[structure]")
{

    const auto include_dir = source_dir/"include";

    REQUIRE(valid_feature_deps(features, additional_feature_deps));

    auto required_feature_deps = gen_feature_deps(features, additional_feature_deps);

    const auto existing_direct_header_deps = collect_direct_header_dependencies(include_dir);
    const auto existing_header_deps = follow_includes(existing_direct_header_deps);

    auto existing_feature_deps = header_to_feature_deps(existing_header_deps);

    feature_dependencies missing_feature_deps;

    std::ranges::set_difference(
        required_feature_deps,
        existing_feature_deps,
        std::back_inserter(missing_feature_deps)
    );

    for(const auto& [header, dependency] : missing_feature_deps)
        UNSCOPED_INFO(header << "\t-> " << dependency);

    REQUIRE(missing_feature_deps.size() == 0);
}
