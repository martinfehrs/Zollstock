module;

#define ZOLLSTOCK_USE_MODULES

#include "zollstock/config.hpp"

#include <concepts>

export module zollstock:quantities.concepts;

import :dimensions;
import :numbers;
import :units.concepts.unit;

#include "zollstock/quantities/concepts.hpp"
