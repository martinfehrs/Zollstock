#include <catch2/catch_all.hpp>
#include <zollstock/dimensionless_unit_types.hpp>
#include <zollstock/tests/test_helpers.hpp>

using namespace zollstock;


TEST_CASE("dimensionless-unit-types", "[dimensionless][unit][types]")
{

    REQUIRE(unit_length(one{}) == unit_data{});
    REQUIRE(unit_time  (one{}) == unit_data{});
    REQUIRE(unit_angle (one{}) == unit_data{});

}
