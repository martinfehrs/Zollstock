# Zollstock
A header-only type-safe zero overhead compile-time physical units C++20 library.

Zollstock is German for folding rule. It's a funny word, because it's a lie. Zoll means inch but the
so called Zollstock normaly shows centimeters these days.

The library is still in a very early development stage. So please be careful when using it in
production code.

## Supported SI base units

| prefix | second | meter | gram | ampere | kelvin | mole | candela |
|--------|:------:|:-----:|:----:|:------:|:------:|:----:|:-------:|
| quetta |    ✓   |   ✓   |   ✓  |        |        |      |         |
| ronna  |    ✓   |   ✓   |   ✓  |        |        |      |         |
| yotta  |    ✓   |   ✓   |   ✓  |        |        |      |         |
| zetta  |    ✓   |   ✓   |   ✓  |        |        |      |         |
| exa    |    ✓   |   ✓   |   ✓  |        |        |      |         |
| peta   |    ✓   |   ✓   |   ✓  |        |        |      |         |
| tera   |    ✓   |   ✓   |   ✓  |        |        |      |         |
| giga   |    ✓   |   ✓   |   ✓  |        |        |      |         |
| mega   |    ✓   |   ✓   |   ✓  |        |        |      |         |
| kilo   |    ✓   |   ✓   |   ✓  |        |        |      |         |
| hecto  |    ✓   |   ✓   |   ✓  |        |        |      |         |
| deca   |    ✓   |   ✓   |   ✓  |        |        |      |         |
|        |    ✓   |   ✓   |   ✓  |        |        |      |         |
| deci   |    ✓   |   ✓   |   ✓  |        |        |      |         |
| centi  |    ✓   |   ✓   |   ✓  |        |        |      |         |
| milli  |    ✓   |   ✓   |   ✓  |        |        |      |         |
| micro  |    ✓   |   ✓   |   ✓  |        |        |      |         |
| nano   |    ✓   |   ✓   |   ✓  |        |        |      |         |
| pico   |    ✓   |   ✓   |   ✓  |        |        |      |         |
| femto  |    ✓   |   ✓   |   ✓  |        |        |      |         |
| atto   |    ✓   |   ✓   |   ✓  |        |        |      |         |
| zepto  |    ✓   |   ✓   |   ✓  |        |        |      |         |
| yocto  |    ✓   |   ✓   |   ✓  |        |        |      |         |
| ronto  |    ✓   |   ✓   |   ✓  |        |        |      |         |
| quecto |    ✓   |   ✓   |   ✓  |        |        |      |         |

## Supported SI named derived units

| prefix | rad | sr | Hz | N | Pa | J | W | C | V | F | Ω | S | Wb | T | H | °C | lm | lx | Bq | Gy | Sv | kat |
|--------|:---:|:--:|:--:|:-:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:-:|:-:|:--:|:--:|:--:|:--:|:--:|:--:|:---:|
| quetta |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| ronna  |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| yotta  |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| zetta  |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| exa    |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| peta   |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| tera   |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| giga   |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| mega   |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| kilo   |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| hecto  |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| deca   |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
|        |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| deci   |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| centi  |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| milli  |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| micro  |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| nano   |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| pico   |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| femto  |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| atto   |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| zepto  |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| yocto  |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| ronto  |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| quecto |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |

## SI unnamed derived units with special support

There is no finite set of unamed derived units. You can combine base units as you like. But there
are some unamed derived units with predefined symbols and literals. These symbols and literals
are not required. Their only purpose is to increase readability.

| prefix | square metre | cubic metre | square second |
|--------|:------------:|:-----------:|:-------------:|
| quetta |       ✓      |      ✓      |       ✓       |
| ronna  |       ✓      |      ✓      |       ✓       |
| yotta  |       ✓      |      ✓      |       ✓       |
| zetta  |       ✓      |      ✓      |       ✓       |
| exa    |       ✓      |      ✓      |       ✓       |
| peta   |       ✓      |      ✓      |       ✓       |
| tera   |       ✓      |      ✓      |       ✓       |
| giga   |       ✓      |      ✓      |       ✓       |
| mega   |       ✓      |      ✓      |       ✓       |
| kilo   |       ✓      |      ✓      |       ✓       |
| hecto  |       ✓      |      ✓      |       ✓       |
| deca   |       ✓      |      ✓      |       ✓       |
|        |       ✓      |      ✓      |       ✓       |
| deci   |       ✓      |      ✓      |       ✓       |
| centi  |       ✓      |      ✓      |       ✓       |
| milli  |       ✓      |      ✓      |       ✓       |
| micro  |       ✓      |      ✓      |       ✓       |
| nano   |       ✓      |      ✓      |       ✓       |
| pico   |       ✓      |      ✓      |       ✓       |
| femto  |       ✓      |      ✓      |       ✓       |
| atto   |       ✓      |      ✓      |       ✓       |
| zepto  |       ✓      |      ✓      |       ✓       |
| yocto  |       ✓      |      ✓      |       ✓       |
| ronto  |       ✓      |      ✓      |       ✓       |
| quecto |       ✓      |      ✓      |       ✓       |
