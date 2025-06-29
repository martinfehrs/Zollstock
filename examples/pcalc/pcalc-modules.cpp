import zollstock;

#include <iostream>
#include <cstdlib>
#include <format>

namespace zs = zollstock;

using namespace zs::quantities::constants;
using namespace zs::units;
using namespace zs::dimensions;

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

[[nodiscard]] zs::of_dimension_c<M> auto calculate_pipe_mass(
    zs::of_dimension_c<L> auto wall_thickness,
    zs::of_dimension_c<L> auto outer_diameter,
    zs::of_dimension_c<L> auto pipe_length
)
{
    static constexpr auto copper_density = zs::in<g/mm3>(8.1_g/cm3);

    const auto outer_radius = outer_diameter / 2;
    const auto inner_radius = outer_radius - wall_thickness;
    const auto outer_area = pi * outer_radius * outer_radius;
    const auto inner_area = pi * inner_radius * inner_radius;
    const auto ring_area = outer_area - inner_area;
    const auto pipe_volume = ring_area * pipe_length;

    return  zs::in<kg>(pipe_volume * copper_density);

}

int main(int argc, char** argv)
{
    // Checking arguments
    const auto [wall_thickness, outer_diameter, pipe_length] = read_args(argc, argv);

    // Calculating mass of a copper pipe

    std::cout << std::format(
        "pipe mass: {:.2f}\n",
        calculate_pipe_mass(wall_thickness, outer_diameter, pipe_length)
    );

    return 0;
}
