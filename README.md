# Zollstock
A header-only type-safe zero overhead compile-time physical units C++20 library.

This library increases the type-safety of your application by providing scalars associated with physical units.
Furthermore, there are unit-constants and unit-literals, simplifying their usage and increasing readability.
All additional checks are executed at compile-time, producing no overhead in your final application.

Zollstock is German for folding rule. It's a funny word, because it's a lie. Zoll means inch but the
so called Zollstock normaly shows centimeters these days.

The library is still in a very early development stage. So please be careful when using it in
production code.

## Example

```cpp
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
```

## Supported SI base units

| prefix | Q | R | Y | Z | E | P | T | G | M | k | h | da |   | d | c | m | μ | n | p | f | a | z | y | r | q |
|--------|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| s      | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |  ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| m      | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |  ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| g      | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |  ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| A      |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| K      |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| mol    |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| cd     |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |

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
