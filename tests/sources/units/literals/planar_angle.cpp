#include <zollstock/units/literals/planar_angle.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("angle-unit-literals", "[angle][unit][literals]")
{
    TEST_LITERALS(ALL       , rad , rad )
    TEST_LITERALS(UNPREFIXED, deg , deg )
    TEST_LITERALS(UNPREFIXED, amin, amin)
    TEST_LITERALS(ALL       , asec, asec)
    TEST_LITERALS(ALL       , gon , gon )
}
