#include <catch2/catch_all.hpp>
#include <zollstock/time_unit_types.hpp>
#include <zollstock/tests/type_test_helpers.hpp>



TEST_CASE("time-unit-types", "[time][unit][types]")
{
    using namespace zollstock;

    TEST_BASE_TYPES(ALL       , second, quantity_t::time, "s"_us  , 1.0L         )
    TEST_BASE_TYPES(UNPREFIXED, minute, quantity_t::time, "min"_us, 60.0L        )
    TEST_BASE_TYPES(UNPREFIXED, hour  , quantity_t::time, "h"_us  , 3'600.0L     )
    TEST_BASE_TYPES(UNPREFIXED, day   , quantity_t::time, "d"_us  , 86'400.0L    )
    TEST_BASE_TYPES(UNPREFIXED, year  , quantity_t::time, "a"_us  , 31'536'000.0L)
}
