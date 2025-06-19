module;

#define ZOLLSTOCK_USE_MODULES

#include "zollstock/config.hpp"
#include "zollstock/units/literals/definition_helpers.hpp"

#include <limits>

export module zollstock:units.literals.length;

import :numbers;
import :quantities.template_;
import :units.constants.length;

#include "zollstock/units/literals/length.hpp"
