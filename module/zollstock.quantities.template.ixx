module;

#define ZOLLSTOCK_USE_MODULES

#include "zollstock/config.hpp"

#include <cmath>
#include <format>
#include <algorithm>
#include <sstream>
#include <utility>

// Fragmentname darf zumindest bei clang nicht template enthalten
export module zollstock:quantities.template_;

import :quantities.concepts;
import :units.constants.one;
import :units.concepts.unit;
import :numbers;

#include "zollstock/quantities/template.hpp"
