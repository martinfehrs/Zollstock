#include <catch2/catch_all.hpp>
#include <zollstock/dimensionless_unit_types.hpp>


using namespace zollstock;


TEST_CASE("dimensionless-unit-types", "[dimensionless][unit][types]")
{

    STATIC_REQUIRE(unit_length(one{}) == unit_data{});
    STATIC_REQUIRE(unit_time  (one{}) == unit_data{});
    STATIC_REQUIRE(unit_angle (one{}) == unit_data{});

}
