#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("angle-unit-constants", "[angle][unit][constants]")
{

    TEST_BASE_UNIT_CONSTANTS(ALL, rad , angle)
    TEST_BASE_UNIT_CONSTANTS(ALL, gon , angle)
    TEST_BASE_UNIT_CONSTANTS(ALL, asec, angle)

    TEST_BASE_UNIT_CONSTANT(deg  , angle, pi/180.0L )
    TEST_BASE_UNIT_CONSTANT(amin , angle, pi/10.8e3L)


}
