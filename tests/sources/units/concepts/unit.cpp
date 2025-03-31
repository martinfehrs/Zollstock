#include <zollstock/units/concepts/unit.hpp>
#include <catch2/catch_all.hpp>


using namespace zollstock;
using namespace zollstock::dimensions;


TEST_CASE("unit-concept", "[units][concepts][unit]")
{
    static constexpr auto m = unit_v<L, "m", 1.0L>;

    STATIC_REQUIRE(m.size == 1);
    STATIC_REQUIRE(std::get<0>(m.factors).exponent == 1);

    static constexpr auto m2 = m * m;

    STATIC_REQUIRE(m2.size == 1);
    STATIC_REQUIRE(std::get<0>(m2.factors).exponent == 2);

    static constexpr auto m3 = m2 * m;

    //STATIC_REQUIRE(m2.size == 1);
    //STATIC_REQUIRE(std::get<0>(m2.factors).exponent == 3);
}
