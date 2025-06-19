module;

#define ZOLLSTOCK_USE_MODULES

#include "zollstock/config.hpp"
#include "zollstock/units/literals/definition_helpers.hpp"

#include <limits>

export module zollstock:units.literals.amount_of_substance;

import :numbers;
import :quantities.template_;
import :units.constants.amount_of_substance;

#include "zollstock/units/literals/amount_of_substance.hpp"
