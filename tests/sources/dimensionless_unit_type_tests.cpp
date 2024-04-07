#include <catch2/catch_all.hpp>
#include <zollstock/unit_concept.hpp>


using namespace zollstock;


TEST_CASE("dimensionless-unit-types", "[dimensionless][unit][types]")
{

    STATIC_REQUIRE(data_of(quantity::length, one{}) == quantity_data{});
    STATIC_REQUIRE(data_of(quantity::time  , one{}) == quantity_data{});
    STATIC_REQUIRE(data_of(quantity::angle , one{}) == quantity_data{});

}
