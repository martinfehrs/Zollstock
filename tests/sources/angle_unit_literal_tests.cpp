#include <zollstock/planar_angle_units.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("angle-unit-literals", "[angle][unit][literals]")
{
    TEST_LITERALS(ALL       , rad )
    TEST_LITERALS(UNPREFIXED, deg )
    TEST_LITERALS(UNPREFIXED, amin)
    TEST_LITERALS(ALL       , asec)
    TEST_LITERALS(ALL       , gon )
}
