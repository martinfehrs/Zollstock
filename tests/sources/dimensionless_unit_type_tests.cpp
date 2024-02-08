#include <catch2/catch_all.hpp>
#include <zollstock/dimensionless_unit_types.hpp>


using namespace zollstock;


TEST_CASE("dimensionless-unit-types", "[dimensionless][unit][types]")
{

    STATIC_REQUIRE(unit_length(one{}) == quantity_data{});
    STATIC_REQUIRE(unit_time  (one{}) == quantity_data{});
    STATIC_REQUIRE(unit_angle (one{}) == quantity_data{});

}
