#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_types.hpp>
#include <zollstock/tests/test_helpers.hpp>

using namespace zollstock;


TEST_CASE("angle-unit-types", "[angle][unit][types]")
{

    ZOLLSTOCK_TESTS_TEST_SI_TYPES(angle,, radian, 1e0L, rad)

    ZOLLSTOCK_TESTS_TEST_TYPE(angle, degree, pi/18e1L, deg)

    ZOLLSTOCK_TESTS_TEST_TYPE(angle, arcminute, pi/108e2L, arcmin)

    ZOLLSTOCK_TESTS_TEST_TYPE(angle, arcsecond, pi/648e3L, arcsec)
    ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_TYPES(angle,, arcsecond, pi/648e3L, as)

    ZOLLSTOCK_TESTS_TEST_SI_TYPES(angle,, gradian, pi/2e2L, gon)

}
