# Zollstock
A header-only type-safe zero overhead compile-time physical units C++20 library.

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
            zs::double_t<cm>{ std::stod(argv[1]) },
            zs::double_t<cm>{ std::stod(argv[2]) },
            zs::double_t<cm>{ zs::double_t<m>{ std::stod(argv[3]) } },
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

    // Calculating mass of a copper pipe
    static constexpr auto copper_density = 8.1_g/cm3;
    const auto inner_radius = outer_radius - wall_thickness;
    const auto outer_area = pi * outer_radius * outer_radius;
    const auto inner_area = pi * inner_radius * inner_radius;
    const auto outer_volume = outer_area * pipe_length;
    const auto inner_volume = inner_area * pipe_length;
    const auto pipe_volume = outer_volume - inner_volume;
    const zs::double_t<kg> pipe_mass = pipe_volume * copper_density;

    std::cout << std::format("pipe mass (kg): {}\n", pipe_mass);

    return 0;
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
