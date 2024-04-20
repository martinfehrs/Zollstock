#include <catch2/catch_all.hpp>
#include <zollstock/unit_concept.hpp>


using namespace zollstock;


TEST_CASE("dimensionless-unit-types", "[dimensionless][unit][types]")
{

    STATIC_REQUIRE(unit_data_for(quantity_t::length, one{}) == quantity_data{ quantity_t::length });
    STATIC_REQUIRE(unit_data_for(quantity_t::time  , one{}) == quantity_data{ quantity_t::time   });
    STATIC_REQUIRE(unit_data_for(quantity_t::angle , one{}) == quantity_data{ quantity_t::angle  });

}
