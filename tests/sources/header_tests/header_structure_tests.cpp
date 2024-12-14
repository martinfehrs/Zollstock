#include <catch2/catch_all.hpp>

#include <filesystem>
#include <regex>
#include <fstream>


namespace fs = std::filesystem;
namespace rng = std::ranges;


const std::regex snake_case{ "[a-z]+(_[a-z0-9]+)*" };


TEST_CASE("header-structure-tests", "[headers][structure]")
{

    const auto include_dir = fs::current_path()/"include";

    REQUIRE(fs::is_directory(include_dir));

    for(const auto& entry : fs::recursive_directory_iterator(include_dir))
    {
        REQUIRE((entry.is_regular_file() || entry.is_directory()));

        if (entry.is_regular_file())
        {
            const auto file_path = entry.path();
            const auto relative_file_path = fs::relative(file_path, include_dir);

            CAPTURE(relative_file_path);

            REQUIRE(file_path.extension() == ".hpp");
            REQUIRE(std::regex_match(file_path.stem().string(), snake_case));
        }
        else
        if (entry.is_directory())
        {
            const auto directory_path = entry.path();
            const auto relative_directory_path = fs::relative(directory_path, include_dir);

            CAPTURE(relative_directory_path);

            const auto directory_name = directory_path.stem().string();

            const auto directory_has_matching_header = rng::any_of(
                fs::directory_iterator(directory_path.parent_path()),
                [&include_dir, &directory_name](const auto& entry_2)
                {
                    const auto header_path = entry_2.path();
                    const auto relative_header_path = fs::relative(header_path, include_dir);

                    CAPTURE(relative_header_path);

                    const auto header_name = header_path.stem().string();

                    return entry_2.is_regular_file() && header_name == directory_name;
                }
            );

            REQUIRE(directory_has_matching_header);
        }
    }

}
