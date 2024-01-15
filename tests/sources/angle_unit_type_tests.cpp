#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_types.hpp>
#include <zollstock/tests/test_helpers.hpp>

using namespace zollstock;


TEST_CASE("angle-unit-types", "[angle][unit][types]")
{

    ZOLLSTOCK_TESTS_TEST_SI_TYPES(ANGLE,, radian, 1e0L, rad)

    ZOLLSTOCK_TESTS_TEST_TYPE(ANGLE, degree, pi/18e1L, deg)

    ZOLLSTOCK_TESTS_TEST_TYPE(ANGLE, arcminute, pi/108e2L, arcmin)

    ZOLLSTOCK_TESTS_TEST_TYPE(ANGLE, arcsecond, pi/648e3L, arcsec)
    ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_TYPES(ANGLE,, arcsecond, pi/648e3L, as)

    ZOLLSTOCK_TESTS_TEST_SI_TYPES(ANGLE,, gradian, pi/2e2L, gon)

}
