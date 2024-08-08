#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("angle-unit-constants", "[angle][unit][constants]")
{
    TEST_BASE_UNIT_CONSTANTS(ALL, rad , _1)
    TEST_BASE_UNIT_CONSTANTS(ALL, gon , _1)
    TEST_BASE_UNIT_CONSTANTS(ALL, asec, _1)

    TEST_BASE_UNIT_CONSTANT(deg  , _1, pi/180.0L )
    TEST_BASE_UNIT_CONSTANT(amin , _1, pi/10.8e3L)
}
