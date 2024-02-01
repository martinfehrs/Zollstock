#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("angle-unit-constants", "[angle][unit][constants]")
{

    ZOLLSTOCK_TESTS_TEST_BASE_UNIT_CONSTANTS(ALL, radian, rad)

    ZOLLSTOCK_TESTS_TEST_BASE_UNIT_CONSTANTS(UNPREFIXED, degree, deg)

    ZOLLSTOCK_TESTS_TEST_BASE_UNIT_CONSTANTS(UNPREFIXED, arcminute, arcmin)

    ZOLLSTOCK_TESTS_TEST_BASE_UNIT_CONSTANTS(UNPREFIXED, arcsecond, arcsec)
    ZOLLSTOCK_TESTS_TEST_BASE_UNIT_CONSTANTS(PREFIXED  , arcsecond, as    )

    ZOLLSTOCK_TESTS_TEST_BASE_UNIT_CONSTANTS(ALL, gradian, gon)

}
