# Zollstock
A header-only type-safe zero overhead compile-time physical units C++17 library.

Zollstock is German for folding rule. It's a funny word, because it's a lie. Zoll means inch but the so called Zollstock normaly shows centimeters these days.

The library is still in a very early development stage. So please be careful when using it in production code.

these units for the following quantities are currently supported:

Dimensionless:
  - Type for unit 1
  - Constant for unit 1
  - Literal for unit 1

Length:
  - Types for meter and all prefixed variants
  - Constants for meter and all prefixed variants
  - Literals for meter and all prefixed variants

Area:
  - Types for square meter and all prefixed variants
  - Constants for square meter and all prefixed variants
  - Literals for square meter abs all prefixed variants

Volume:
  - Types for cubic meter and all prefixed variants
  - Constants for cubic meter and all prefixed variants
  - Literals for cubic meter and all prefixed variants

Time:
  - Types for second and all prefixed variants
  - Contants for second and all prefixed variants
  - Literals for second and all prefixed variants
  - Type for minute
  - Constant for minute
  - Literal for minute
  - Type for hour
  - Constant for hour
  - Literal for hour
  - Type for day
  - Constant for day
  - Literal for day

Angle:
  - Types for radian and all prefixed variants
  - Constants for radian and all prefixed variants
  - Literals for radian and all prefixed variants
  - Types for gradian and all prefixed variants
  - Constants for gradian and all prefixed variants
  - Literals for gradian and all prefixedd variants
  - Type for degree
  - Constant for degree
  - Literal for degree
  - Type for arcsecond
  - Constant for arcsecond
  - Literal for arcsecond
  - Type for arcminute
  - Constant for arcminute
  - Literal for arcminute
  - Type for milliarcsecond
  - Constant for milliarcsecond
  - Literal for milliarcsecond
  - Type for microarcsecond
  - Constant for microarcsecond
  - Literal for microarcsecond

Furthermore you can combine all units as needed to represent all derived units but without any special support.
Arithmetic whould work as expected.
