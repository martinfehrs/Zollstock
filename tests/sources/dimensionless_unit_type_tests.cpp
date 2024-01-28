#include <catch2/catch_all.hpp>
#include <zollstock/dimensionless_unit_types.hpp>
#include <zollstock/tests/test_helpers.hpp>

using namespace zollstock;


TEST_CASE("dimensionless-unit-types", "[dimensionless][unit][types]")
{

    REQUIRE(one::length == unit_data{});
    REQUIRE(one::time   == unit_data{});
    REQUIRE(one::angle  == unit_data{});

}
