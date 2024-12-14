#include <filesystem>

#include <catch2/catch_all.hpp>


namespace fs = std::filesystem;


[[nodiscard]] bool validate_headers(const fs::path& project_dir)
{
    const auto include_dir = fs::current_path()/include/zollstock;

    return fs::is_directory(include_dir);
}


TEST_CASE("header-check", "[headers]")
{

    validate_headers()

}
