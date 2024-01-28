#include <catch2/catch_all.hpp>
#include <zollstock/dimensionless_unit_constants.hpp>
#include <zollstock/dimensionless_unit_literals.hpp>
#include <zollstock/tests/test_helpers.hpp>

using namespace zollstock;


TEST_CASE("dimensionless-unit-literals", "[dimensionless][unit][literals]")
{

    REQUIRE(1.0_1   == 1.0 * _1);
    REQUIRE(1_1     == 1   * _1);

}
