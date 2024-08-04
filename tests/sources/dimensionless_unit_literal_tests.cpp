#include <catch2/catch_all.hpp>
#include <zollstock/scalar.hpp>


using namespace zollstock::units;


TEST_CASE("dimensionless-unit-literals", "[dimensionless][unit][literals]")
{

    STATIC_REQUIRE(1.0_1   == 1.0 * _1);
    STATIC_REQUIRE(1_1     == 1   * _1);

}
