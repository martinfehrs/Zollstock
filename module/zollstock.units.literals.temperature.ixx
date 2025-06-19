module;

#define ZOLLSTOCK_USE_MODULES

#include "zollstock/config.hpp"
#include "zollstock/units/literals/definition_helpers.hpp"

#include <limits>

export module zollstock:units.literals.temperature;

import :numbers;
import :quantities.template_;
import :units.constants.temperature;

#include "zollstock/units/literals/temperature.hpp"
