#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/angle_unit_literals.hpp>
#include <zollstock/tests/test_helpers.hpp>

using namespace zollstock;


TEST_CASE("angle-unit-literals", "[angle][unit][literals]")
{

    TEST_LITERALS(ALL       , rad )
    TEST_LITERALS(UNPREFIXED, deg )
    TEST_LITERALS(UNPREFIXED, amin)
    TEST_LITERALS(ALL       , asec)
    TEST_LITERALS(ALL       , gon )

}
