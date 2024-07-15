# Zollstock
A header-only type-safe zero overhead compile-time physical units C++20 library.

Zollstock is German for folding rule. It's a funny word, because it's a lie. Zoll means inch but the
so called Zollstock normaly shows centimeters these days.

The library is still in a very early development stage. So please be careful when using it in
production code.

## Supported SI base units

| prefix | second | meter | gram | ampere | kelvin | mole | candela |
|--------|:------:|:-----:|:----:|:------:|:------:|:----:|:-------:|
| quetta |    X   |   X   |   X  |        |        |      |         |
| ronna  |    X   |   X   |   X  |        |        |      |         |
| yotta  |    X   |   X   |   X  |        |        |      |         |
| zetta  |    X   |   X   |   X  |        |        |      |         |
| exa    |    X   |   X   |   X  |        |        |      |         |
| peta   |    X   |   X   |   X  |        |        |      |         |
| tera   |    X   |   X   |   X  |        |        |      |         |
| giga   |    X   |   X   |   X  |        |        |      |         |
| mega   |    X   |   X   |   X  |        |        |      |         |
| kilo   |    X   |   X   |   X  |        |        |      |         |
| hecto  |    X   |   X   |   X  |        |        |      |         |
| deca   |    X   |   X   |   X  |        |        |      |         |
|        |    X   |   X   |   X  |        |        |      |         |
| deci   |    X   |   X   |   X  |        |        |      |         |
| centi  |    X   |   X   |   X  |        |        |      |         |
| milli  |    X   |   X   |   X  |        |        |      |         |
| micro  |    X   |   X   |   X  |        |        |      |         |
| nano   |    X   |   X   |   X  |        |        |      |         |
| pico   |    X   |   X   |   X  |        |        |      |         |
| femto  |    X   |   X   |   X  |        |        |      |         |
| atto   |    X   |   X   |   X  |        |        |      |         |
| zepto  |    X   |   X   |   X  |        |        |      |         |
| yocto  |    X   |   X   |   X  |        |        |      |         |
| ronto  |    X   |   X   |   X  |        |        |      |         |
| quecto |    X   |   X   |   X  |        |        |      |         |

## Supported SI named derived units

| prefix | rad | sr | Hz | N | Pa | J | W | C | V | F | Ω | S | Wb | T | H | °C | lm | lx | Bq | Gy | Sv | kat |
|--------|:---:|:--:|:--:|:-:|:--:|:-:|:-:|:-:|:-:|: :|: :|: :|:  :|: :|: :|:  :|:  :|:  :|:  :|:  :|:  :|:   :|
| quetta |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| ronna  |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| yotta  |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| zetta  |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| exa    |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| peta   |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| tera   |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| giga   |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| mega   |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| kilo   |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| hecto  |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| deca   |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
|        |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| deci   |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| centi  |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| milli  |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| micro  |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| nano   |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| pico   |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| femto  |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| atto   |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| zepto  |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| yocto  |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| ronto  |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| quecto |  X  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |

## SI unnamed derived units with special support

There is no finite set of unamed derived units. You can combine base units as you like. But there
are some unamed derived units with predefined symbols and literals. These symbols and literals
are not required. Their only purpose is to increase readability.

| prefix | square metre | cubic metre | square second |
|--------|:------------:|:-----------:|:-------------:|
| quetta |       X      |      X      |       X       |
| ronna  |       X      |      X      |       X       |
| yotta  |       X      |      X      |       X       |
| zetta  |       X      |      X      |       X       |
| exa    |       X      |      X      |       X       |
| peta   |       X      |      X      |       X       |
| tera   |       X      |      X      |       X       |
| giga   |       X      |      X      |       X       |
| mega   |       X      |      X      |       X       |
| kilo   |       X      |      X      |       X       |
| hecto  |       X      |      X      |       X       |
| deca   |       X      |      X      |       X       |
|        |       X      |      X      |       X       |
| deci   |       X      |      X      |       X       |
| centi  |       X      |      X      |       X       |
| milli  |       X      |      X      |       X       |
| micro  |       X      |      X      |       X       |
| nano   |       X      |      X      |       X       |
| pico   |       X      |      X      |       X       |
| femto  |       X      |      X      |       X       |
| atto   |       X      |      X      |       X       |
| zepto  |       X      |      X      |       X       |
| yocto  |       X      |      X      |       X       |
| ronto  |       X      |      X      |       X       |
| quecto |       X      |      X      |       X       |
