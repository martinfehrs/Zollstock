#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/angle_unit_literals.hpp>
#include <zollstock/tests/test_helpers.hpp>

using namespace zollstock;


TEST_CASE("angle-unit-literals", "[angle][unit][literals]")
{

    ZOLLSTOCK_TESTS_TEST_SI_LITERALS(rad)

    ZOLLSTOCK_TESTS_TEST_LITERAL(deg)

    ZOLLSTOCK_TESTS_TEST_LITERAL(arcmin)

    ZOLLSTOCK_TESTS_TEST_LITERAL(arcsec)
    ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_LITERALS(as)

    ZOLLSTOCK_TESTS_TEST_SI_LITERALS(gon)

}
