#include <catch2/catch_all.hpp>
#include <zollstock/dimensionless_unit_types.hpp>
#include <zollstock/tests/test_helpers.hpp>

using namespace zollstock;


TEST_CASE("dimensionless-unit-types", "[dimensionless][unit][types]")
{

    STATIC_REQUIRE(unit_length_v<one> == unit_data{});
    STATIC_REQUIRE(unit_time_v  <one> == unit_data{});
    STATIC_REQUIRE(unit_angle_v <one> == unit_data{});

}
