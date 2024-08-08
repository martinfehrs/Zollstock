#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>

#include <catch2/catch_all.hpp>


namespace dim = zollstock::dimensions;
using namespace zollstock::units;


TEST_CASE("angle-unit-constants", "[angle][unit][constants]")
{
    TEST_BASE_UNIT_CONSTANTS(ALL, rad , dim::_1)
    TEST_BASE_UNIT_CONSTANTS(ALL, gon , dim::_1)
    TEST_BASE_UNIT_CONSTANTS(ALL, asec, dim::_1)

    TEST_BASE_UNIT_CONSTANT(deg  , dim::_1, pi/180.0L )
    TEST_BASE_UNIT_CONSTANT(amin , dim::_1, pi/10.8e3L)
}
