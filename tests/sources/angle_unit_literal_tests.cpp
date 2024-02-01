#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/angle_unit_literals.hpp>
#include <zollstock/tests/test_helpers.hpp>

using namespace zollstock;


TEST_CASE("angle-unit-literals", "[angle][unit][literals]")
{

    ZOLLSTOCK_TESTS_TEST_LITERALS(ALL, rad)

    ZOLLSTOCK_TESTS_TEST_LITERALS(UNPREFIXED, deg)

    ZOLLSTOCK_TESTS_TEST_LITERALS(UNPREFIXED, arcmin)

    ZOLLSTOCK_TESTS_TEST_LITERALS(ALL, asec)

    ZOLLSTOCK_TESTS_TEST_LITERALS(ALL, gon)

}
