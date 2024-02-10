#include <catch2/catch_all.hpp>
#include <zollstock/unit_concept.hpp>


using namespace zollstock;


TEST_CASE("dimensionless-unit-types", "[dimensionless][unit][types]")
{

    STATIC_REQUIRE(length_of(one{}) == quantity_data{});
    STATIC_REQUIRE(time_of  (one{}) == quantity_data{});
    STATIC_REQUIRE(angle_of (one{}) == quantity_data{});

}
