#include <zollstock/zollstock.hpp>
#include <iostream>
#include <cstdlib>
#include <format>

namespace zs = zollstock;

[[noreturn]] void argument_error() noexcept
{
    std::cerr << "Invalid arguments\n"
              << "Usage: pcalc <wall thickness (cm)> <outer radius (cm)> <pipe length (m)>\n";

    std::exit(1);
}

[[nodiscard]] auto read_args(int argc, char** argv) noexcept
{
    if (argc != 4)
        argument_error();

    try
    {
        return std::tuple{
            zs::double_t<zs::cm>{ std::stod(argv[1]) },
            zs::double_t<zs::cm>{ std::stod(argv[2]) },
            zs::double_t<zs::cm>{ std::stod(argv[3]) },
        };
    }
    catch(const std::exception& e)
    {
        argument_error();
    }
}

int main(int argc, char** argv)
{
    // Checking arguments
    const auto [wall_thickness, outer_radius, pipe_length] = read_args(argc, argv);

    // Calculation of a pipes material volume
    const auto inner_radius = outer_radius - wall_thickness;
    const auto outer_area = zs::pi * outer_radius * outer_radius;
    const auto inner_area = zs::pi * inner_radius * inner_radius;
    const auto outer_volume = outer_area * pipe_length;
    const auto inner_volume = inner_area * pipe_length;
    const zs::double_t<zs::dm3> pipe_volume = outer_volume - inner_volume;

    std::cout << std::format("pipe volume: {}\n", pipe_volume);

    return 0;
}
