#include <catch2/catch_all.hpp>
#include <zollstock/unit_concept.hpp>


using namespace zollstock;


TEST_CASE("dimensionless-unit-types", "[dimensionless][unit][types]")
{

    STATIC_REQUIRE(unit_data_for(quantity::length, one{}) == quantity_data{ quantity::length });
    STATIC_REQUIRE(unit_data_for(quantity::time  , one{}) == quantity_data{ quantity::time   });
    STATIC_REQUIRE(unit_data_for(quantity::angle , one{}) == quantity_data{ quantity::angle  });

}
