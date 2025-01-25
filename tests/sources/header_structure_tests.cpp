#include <catch2/catch_all.hpp>

#include <zollstock/tests/header_dependencies.hpp>
#include <zollstock/tests/required_header_dependencies.hpp>

#include <algorithm>
#include <filesystem>
#include <ranges>
#include <regex>
#include <vector>
#include <string>
#include <fstream>


namespace fs = std::filesystem;
namespace rng = std::ranges;


const std::string header_file_extension = ".hpp";
const std::regex snake_case{ "[a-z]+(_[a-z0-9]+)*" };
const std::regex header_include_prefix{ "^\\s*#\\s*include" };
const std::regex header_include{ "#include\\s<([^\\>]+)>" };


[[nodiscard]] bool is_header_include(const std::string& line)
{
    return std::regex_search(line, header_include_prefix);
}

[[nodiscard]] auto toupper(const std::string& text)
{
    std::string uppercase_text;

    rng::transform(
        text,
        std::back_inserter(uppercase_text),
        [](char c){ return std::toupper(c); }
    );

    return uppercase_text;
}

[[nodiscard]] auto derive_include_guard_name(const fs::path& header_path)
{
    std::string include_guard = "__";

    for(const auto& part : header_path.parent_path())
    {
        include_guard += toupper(part);
        include_guard += "_";
    }

    include_guard += toupper(header_path.stem());
    include_guard += "_";
    include_guard += toupper(header_path.extension().string().substr(1));
    include_guard += "__";

    return include_guard;
}

[[nodiscard]] auto read_lines(std::ifstream& ifs)
{
    std::vector<std::string> lines;

    std::string line;

    while(std::getline(ifs, line))
        lines.push_back(std::move(line));

    return lines;
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

[[nodiscard]] header_dependencies::value_type header_includes_from_path(
    const fs::path& root_dir,
    const fs::path& header_path
)
{
    return {
        fs::relative(header_path, root_dir),
        analyse_header_content(header_path, root_dir),
    };
}

[[nodiscard]] auto collect_header_includes(fs::path root_dir)
{
    REQUIRE(fs::is_directory(root_dir));

    header_dependencies includes;

    rng::copy(
        fs::recursive_directory_iterator(root_dir)
            | rng::views::transform(std::mem_fn(&fs::directory_entry::path))
            | rng::views::filter([](const auto& path){ return fs::is_regular_file(path); })
            | rng::views::filter([](const auto& path){ return path.extension() == ".hpp"; })
            | rng::views::transform(std::bind_front(header_includes_from_path, root_dir))
        , std::inserter(includes, std::end(includes))
    );

    return includes;
}

header_set follow_include(const header_dependencies& dependencies, const fs::path& include)
{
    header_set includes;

    const auto it = dependencies.find(include);

    if (it != rng::end(dependencies))
    {
        rng::copy(it->second, std::inserter(includes, std::end(includes)));

        for(const fs::path& dependency : it->second)
            rng::copy(
                follow_include(dependencies, dependency),
                std::inserter(includes, std::end(includes))
            );
    }

    return includes;
}

void resolve_dependencies(header_dependencies& dependencies)
{
    for(auto&[include, include_dependencies] : dependencies)
    {
        header_set resolved_dependencies = include_dependencies;

        for(const fs::path& include_dependency : include_dependencies)
            rng::copy(
                follow_include(dependencies, include_dependency),
                std::inserter(resolved_dependencies, std::end(resolved_dependencies))
            );

        std::swap(include_dependencies, resolved_dependencies);
    }
}

[[nodiscard]] header_set header_set_difference(const header_set& set_1, const header_set& set_2)
{
    header_set difference;

    rng::set_difference(
        std::make_move_iterator(std::begin(set_1)), std::make_move_iterator(std::end(set_1)),
        std::cbegin(set_2), std::cend(set_2),
        std::inserter(difference, std::end(difference))
    );

    return difference;
}

TEST_CASE("header-structure-tests", "[headers][structure]")
{

    const auto include_dir = fs::current_path()/"include";

    auto existing_dependencies = collect_header_includes(include_dir);

    resolve_dependencies(existing_dependencies);

    header_dependencies missing_dependencies;

    for(const auto& [header, dependencies] : required_header_dependencies)
    {
        header_set dependency_difference;

        const auto it = existing_dependencies.find(header);

        if (it == rng::cend(existing_dependencies))
            dependency_difference = std::move(dependencies);
        else
            dependency_difference = header_set_difference(dependencies, it->second);

        if (dependency_difference.size() > 0)
            missing_dependencies.emplace(std::move(header), std::move(dependency_difference));
    }

    for(const auto& [header, dependencies] : missing_dependencies)
    {
        UNSCOPED_INFO(header);

        for(const auto& dependency : dependencies)
            UNSCOPED_INFO("\t-> " << dependency);
    }

    REQUIRE(missing_dependencies.size() == 0);
}
