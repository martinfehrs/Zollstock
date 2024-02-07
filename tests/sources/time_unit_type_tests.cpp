#include <catch2/catch_all.hpp>
#include <zollstock/time_unit_types.hpp>
#include <zollstock/tests/type_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("time-unit-types", "[time][unit][types]")
{

    TEST_TYPES(ALL       , time, second, 1.0L         , s  )
    TEST_TYPES(UNPREFIXED, time, minute, 60.0L        , min)
    TEST_TYPES(UNPREFIXED, time, hour  , 3'600.0L     , h  )
    TEST_TYPES(UNPREFIXED, time, day   , 86'400.0L    , d  )
    TEST_TYPES(UNPREFIXED, time, year  , 31'536'000.0L, a  )

}
