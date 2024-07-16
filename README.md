# Zollstock
A header-only type-safe zero overhead compile-time physical units C++20 library.

Zollstock is German for folding rule. It's a funny word, because it's a lie. Zoll means inch but the
so called Zollstock normaly shows centimeters these days.

The library is still in a very early development stage. So please be careful when using it in
production code.

## Supported SI base units

| prefix |    s   |   m   |   g  |    A   |    K   |  mol |    cd   |
|--------|:------:|:-----:|:----:|:------:|:------:|:----:|:-------:|
| Q      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| R      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| Y      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| Z      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| E      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| P      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| T      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| G      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| M      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| k      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| h      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| da     |    ✓   |   ✓   |   ✓  |        |        |      |         |
|        |    ✓   |   ✓   |   ✓  |        |        |      |         |
| d      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| c      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| m      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| μ      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| n      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| p      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| f      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| a      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| z      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| y      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| r      |    ✓   |   ✓   |   ✓  |        |        |      |         |
| q      |    ✓   |   ✓   |   ✓  |        |        |      |         |

## Supported SI named derived units

| prefix | rad | sr | Hz | N | Pa | J | W | C | V | F | Ω | S | Wb | T | H | °C | lm | lx | Bq | Gy | Sv | kat |
|--------|:---:|:--:|:--:|:-:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:-:|:-:|:--:|:--:|:--:|:--:|:--:|:--:|:---:|
| Q      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| R      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| Y      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| Z      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| E      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| P      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| T      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| G      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| M      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| k      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| h      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| da     |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
|        |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| d      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| c      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| m      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| μ      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| n      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| p      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| f      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| a      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| z      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| y      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| r      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |
| q      |  ✓  |    |    |   |    |   |   |   |   |   |   |   |    |   |   |    |    |    |    |    |    |     |

## SI unnamed derived units with special support

There is no finite set of unamed derived units. You can combine base units as you like. But there
are some unamed derived units with predefined symbols and literals. These symbols and literals
are not required. Their only purpose is to increase readability.

| prefix  | Q | R | Y | Z | E | P | T | G | M | k | h | da |   | d | c | m | μ | n | p | f | a | z | y | r | q |
|---------|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| m² (m2) | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |  ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| m³ (m3) | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |  ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| s² (s2) | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |  ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
