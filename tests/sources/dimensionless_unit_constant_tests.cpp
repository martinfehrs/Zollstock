#include <catch2/catch_all.hpp>
#include <zollstock/dimensionless_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>


using namespace zollstock;


TEST_CASE("dimensionless-unit-constants", "[dimensionless][unit][constants]")
{

    STATIC_REQUIRE(_1 == one{});

}
