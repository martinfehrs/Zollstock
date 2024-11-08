#include <zollstock/concepts/unit.hpp>
#include <zollstock/unit_one_constant.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("dimensionless-unit-constants", "[dimensionless][unit][constants]")
{
    STATIC_REQUIRE(_1.factors == std::tuple{});
    STATIC_REQUIRE(_1.size == 0);
}
