#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("angle-unit-constants", "[angle][unit][constants]")
{

    TEST_BASE_UNIT_CONSTANTS(ALL       , radian   , rad )
    TEST_BASE_UNIT_CONSTANTS(UNPREFIXED, degree   , deg )
    TEST_BASE_UNIT_CONSTANTS(UNPREFIXED, arcminute, amin)
    TEST_BASE_UNIT_CONSTANTS(UNPREFIXED, arcsecond, asec)
    TEST_BASE_UNIT_CONSTANTS(ALL       , gradian  , gon )

}
