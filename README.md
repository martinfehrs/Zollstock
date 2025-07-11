# Zollstock
A header-only modularized type-safe zero overhead compile-time physical units C++20 library.

*Zollstock is German for folding rule. It's a funny word, because it's a lie. Zoll means inch but the
so called Zollstock normaly shows centimeters these days*

This library increases the type-safety of your application by providing scalars associated with physical units.
All additional checks are executed at compile-time, producing no overhead in your final application.
It comes in two flavours: modularized and as header-only, for those poor souls who got stuck in the past.
The library is SI-centric. All non-SI units are defined relative to their corresponding counterpart. All
built-in numeric types known in C++20 can be combined with units except `char` which isn't considered a number
but a character. You can use `signed char`, `unsigned char`, `std::int8_t` or
`std::uint8_t` instead. There is currently no support for C++23 fixed width floating-point types. But their support is
planed.

The library is still in a very early development stage. So please be careful when using it in
production code.


## Example

```cpp
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
        "pipe mass: {}\n",
        calculate_pipe_mass(wall_thickness, outer_diameter, pipe_length)
    );

    return 0;
}
```

## Supported SI base units

All seven SI base units **m**, **s**, **mol**, **A**, **K**, **cd** and **kg** are supported,
including all prefixed variants from **quetta** to **quecto**.

## Supported SI named derived units

| prefix        | Q | R | Y | Z | E | P | T | G | M | k | h | da |   | d | c | m | μ | n | p | f | a | z | y | r | q |
|---------------|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| rad           | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |  ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| sr            |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| Hz            |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| N             |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| Pa            |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| J             |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| W             |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| C             |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| V             |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| F             |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| Ω&nbsp;(ohm)  |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| S             |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| Wb            |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| T             |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| °C&nbsp;(degc)|   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| lm            |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| lx            |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| Bq            |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| Gy            |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| Sv            |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| kat           |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |

## SI unnamed derived units with special support

There is no finite set of unamed derived units. You can combine base units as you like. But there
are some unamed derived units with predefined symbols and literals. These symbols and literals
are not required. Their only purpose is to increase readability.

| prefix       | Q | R | Y | Z | E | P | T | G | M | k | h | da |   | d | c | m | μ | n | p | f | a | z | y | r | q |
|--------------|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| m²&nbsp;(m2) | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |  ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| m³&nbsp;(m3) | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |  ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| s²&nbsp;(s2) | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |  ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |


## Supported Non-SI units
| prefix       | Q | R | Y | Z | E | P | T | G | M | k | h | da |   | d | c | m | μ | n | p | f | a | z | y | r | q |
|--------------|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| asec         | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |  ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| gon          | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |  ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| °&nbsp;(deg) | — | — | — | — | — | — | — | — | — | — | — |  — | ✓ | — | — | — | — | — | — | — | — | — | — | — | — |
| amin         | — | — | — | — | — | — | — | — | — | — | — |  — | ✓ | — | — | — | — | — | — | — | — | — | — | — | — |
| min          | — | — | — | — | — | — | — | — | — | — | — |  — | ✓ | — | — | — | — | — | — | — | — | — | — | — | — |
| h            | — | — | — | — | — | — | — | — | — | — | — |  — | ✓ | — | — | — | — | — | — | — | — | — | — | — | — |
| d            | — | — | — | — | — | — | — | — | — | — | — |  — | ✓ | — | — | — | — | — | — | — | — | — | — | — | — |
| a            | — | — | — | — | — | — | — | — | — | — | — |  — | ✓ | — | — | — | — | — | — | — | — | — | — | — | — |
