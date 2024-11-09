#include <zollstock/constants/units/squared_time.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("squared-time-unit-constants", "[squared-time][unit][constants]")
{
    TEST_RAISED_UNIT_CONSTANTS(ALL       , s  , 2)
    TEST_RAISED_UNIT_CONSTANTS(UNPREFIXED, min, 2)
    TEST_RAISED_UNIT_CONSTANTS(UNPREFIXED, h  , 2)
    TEST_RAISED_UNIT_CONSTANTS(UNPREFIXED, d  , 2)
    TEST_RAISED_UNIT_CONSTANTS(UNPREFIXED, a  , 2)
}
