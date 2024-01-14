#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("angle-unit-constants", "[angle][unit][constants]")
{

    ZOLLSTOCK_TESTS_TEST_SI_CONSTANTS(, radian, rad)

    REQUIRE(deg            == degree{});

    REQUIRE(arcsec == arcsecond{});
    ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_CONSTANTS(, arcsecond, as)

    ZOLLSTOCK_TESTS_TEST_SI_CONSTANTS(, gradian, gon)

}
