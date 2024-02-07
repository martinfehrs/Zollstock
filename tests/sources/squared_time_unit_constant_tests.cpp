#include <catch2/catch_all.hpp>
#include <zollstock/squared_time_unit_constants.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("squared-time-unit-constants", "[squared-time][unit][constants]")
{

    TEST_RAISED_UNIT_CONSTANTS(ALL       , s  , 2)
    TEST_RAISED_UNIT_CONSTANTS(UNPREFIXED, min, 2)
    TEST_RAISED_UNIT_CONSTANTS(UNPREFIXED, h  , 2)
    TEST_RAISED_UNIT_CONSTANTS(UNPREFIXED, d  , 2)
    TEST_RAISED_UNIT_CONSTANTS(UNPREFIXED, a  , 2)

}
