module;

#include "zollstock/config.hpp"

#include <algorithm>
#include <cmath>
#include <format>
// Warnung LNK4006 unter MSVC
// #include <ostream>
#include <string>
#include <utility>

// Fragmentname darf zumindest bei clang nicht template enthalten
export module zollstock:quantities.template_;

import :quantities.concepts;
import :units.constants.one;
import :units.concepts.unit;
import :numbers;

#include "zollstock/quantities/template.hpp"
