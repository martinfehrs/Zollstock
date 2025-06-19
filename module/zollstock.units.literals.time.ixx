module;

#define ZOLLSTOCK_USE_MODULES

#include "zollstock/config.hpp"
#include "zollstock/units/literals/definition_helpers.hpp"

#include <limits>

export module zollstock:units.literals.time;

import :numbers;
import :quantities.template_;
import :units.constants.time;

#include "zollstock/units/literals/time.hpp"
