#include <zollstock/all.hpp>
#include <iostream>
#include <cstdlib>
#include <format>
#include <numbers>

namespace zs = zollstock;

using namespace std::numbers;
using namespace zs::units;

[[noreturn]] void argument_error() noexcept
{
    std::cerr << "Invalid arguments\n"
              << "Usage: pcalc <wall thickness (mm)> <outer diameter (mm)> <length (m)>\n";

    std::exit(1);
}

[[nodiscard]] auto read_args(int argc, char** argv) noexcept
{
    if (argc != 4)
        argument_error();

    try
    {
        return std::tuple{
            zs::double_t<mm>{ std::stod(argv[1]) },
            zs::double_t<mm>{ std::stod(argv[2]) },
            zs::double_t<mm>{ zs::double_t<m>{ std::stod(argv[3]) } },
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
    const auto [wall_thickness, outer_diameter, pipe_length] = read_args(argc, argv);

    // Calculating mass of a copper pipe
    static constexpr zs::double_t<g/mm3> copper_density = 8.1_g/cm3;
    const auto outer_radius = outer_diameter / 2;
    const auto inner_radius = outer_radius - wall_thickness;
    const auto outer_area = pi * outer_radius * outer_radius;
    const auto inner_area = pi * inner_radius * inner_radius;
    const auto outer_volume = outer_area * pipe_length;
    const auto inner_volume = inner_area * pipe_length;
    const auto pipe_volume = outer_volume - inner_volume;
    const zs::double_t<kg> pipe_mass = pipe_volume * copper_density;

    std::cout << std::format("pipe mass (kg): {}\n", pipe_mass);

    return 0;
}
