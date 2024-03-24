#include <catch2/catch_all.hpp>
#include <zollstock/time_unit_types.hpp>
#include <zollstock/tests/type_test_helpers.hpp>



TEST_CASE("time-unit-types", "[time][unit][types]")
{
    using namespace zollstock;

    TEST_BASE_TYPES(ALL       , second, quantity::time, "s"_us  , 1.0L         )
    TEST_BASE_TYPES(UNPREFIXED, minute, quantity::time, "min"_us, 60.0L        )
    TEST_BASE_TYPES(UNPREFIXED, hour  , quantity::time, "h"_us  , 3'600.0L     )
    TEST_BASE_TYPES(UNPREFIXED, day   , quantity::time, "d"_us  , 86'400.0L    )
    TEST_BASE_TYPES(UNPREFIXED, year  , quantity::time, "a"_us  , 31'536'000.0L)
}
