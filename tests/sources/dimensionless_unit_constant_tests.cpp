#include <catch2/catch_all.hpp>
#include <zollstock/unit_concept.hpp>


using namespace zollstock;


TEST_CASE("dimensionless-unit-constants", "[dimensionless][unit][constants]")
{

    STATIC_REQUIRE(_1.factors == std::tuple{});
    STATIC_REQUIRE(_1.size == 0);


}
