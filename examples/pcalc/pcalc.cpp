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
            zs::stod<mm>(argv[1]),
            zs::stod<mm>(argv[2]),
            zs::in<mm>(zs::stod<m>(argv[3])),
        };
    }
    catch(const std::exception&)
    {
        argument_error();
    }
}

int main(int argc, char** argv)
{
    constexpr auto a =  zs::int_t<cm>{ 100 };
    constexpr auto x = zs::int_t<m >{ a }.value();

    // Checking arguments
    const auto [wall_thickness, outer_diameter, pipe_length] = read_args(argc, argv);

    // Calculating mass of a copper pipe
    static constexpr zs::double_t<g/mm3> copper_density = 8.1_g/cm3;
    const auto outer_radius = outer_diameter / 2;
    const auto inner_radius = outer_radius - wall_thickness;
    const auto outer_area = pi * outer_radius * outer_radius;
    const auto inner_area = pi * inner_radius * inner_radius;
    const auto ring_area = outer_area - inner_area;
    const auto pipe_volume = ring_area * pipe_length;
    const zs::double_t<kg> pipe_mass = pipe_volume * copper_density;

    std::cout << std::format("pipe mass: {}\n", pipe_mass);

    return 0;
}
