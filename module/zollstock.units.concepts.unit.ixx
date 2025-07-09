module;

#include "zollstock/config.hpp"

#include <cstring>
#include <format>
#include <tuple>
#include <type_traits>
#include <concepts>
#include <string>
#include <utility>

export module zollstock:units.concepts.unit;

import :dimensions;
import :static_string;
import :tuple_utils;
import :units.concepts.prefix;

#include "zollstock/units/concepts/unit.hpp"
