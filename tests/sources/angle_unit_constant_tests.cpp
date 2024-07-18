#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("angle-unit-constants", "[angle][unit][constants]")
{

    TEST_BASE_UNIT_CONSTANTS(ALL, rad , dimensions::_1)
    TEST_BASE_UNIT_CONSTANTS(ALL, gon , dimensions::_1)
    TEST_BASE_UNIT_CONSTANTS(ALL, asec, dimensions::_1)

    TEST_BASE_UNIT_CONSTANT(deg  , dimensions::_1, pi/180.0L )
    TEST_BASE_UNIT_CONSTANT(amin , dimensions::_1, pi/10.8e3L)

}
