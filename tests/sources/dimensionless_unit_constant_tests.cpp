#include <catch2/catch_all.hpp>
#include <zollstock/dimensionless_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("dimensionless-unit-constants", "[dimensionless][unit][constants]")
{

    REQUIRE(_1 == one{});

}
