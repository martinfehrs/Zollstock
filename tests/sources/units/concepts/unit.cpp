#include <zollstock/units/concepts/unit.hpp>
#include <catch2/catch_all.hpp>


using namespace zollstock;
using namespace zollstock::dimensions;


TEST_CASE("unit-arithmetic", "[units][concepts][unit]")
{
    static constexpr auto m  = unit_v<L, "m",   1.0L,  "">;
    static constexpr auto cm = unit_v<L, "m", 100.0L, "c">;
    static constexpr auto s  = unit_v<T, "s",   1.0L,  "">;

    SECTION("homogeneous multiplication")
    {
        {
            static constexpr auto unit = m * m;

            STATIC_REQUIRE(unit.size == 1);
            STATIC_REQUIRE(std::get<0>(unit.factors).exponent == 2);
        }

        {
            static constexpr auto unit = (m * m) * m;

            STATIC_REQUIRE(unit.size == 1);
            STATIC_REQUIRE(std::get<0>(unit.factors).exponent == 3);
        }

        {
            static constexpr auto unit = m * (m * m);

            STATIC_REQUIRE(unit.size == 1);
            STATIC_REQUIRE(std::get<0>(unit.factors).exponent == 3);
        }
    }

    SECTION("homogeneous division")
    {
        {
            static constexpr auto unit = m/m;

            STATIC_REQUIRE(unit.size == 0);
        }

        {
            static constexpr auto unit = (m/m)/m;

            STATIC_REQUIRE(unit.size == 1);
            STATIC_REQUIRE(std::get<0>(unit.factors).exponent == -1);
        }

        {
            static constexpr auto unit = m/(m/m);

            STATIC_REQUIRE(unit.size == 1);
            STATIC_REQUIRE(std::get<0>(unit.factors).exponent == 1);
        }
    }

    SECTION("heterogeneous multiplication")
    {
        {
            static constexpr auto unit = m*s;

            STATIC_REQUIRE(unit.size == 2);
            STATIC_REQUIRE(std::get<0>(unit.factors).exponent == 1);
            STATIC_REQUIRE(std::get<0>(unit.factors).symbol == "s");
            STATIC_REQUIRE(std::get<1>(unit.factors).exponent == 1);
            STATIC_REQUIRE(std::get<1>(unit.factors).symbol == "m");
        }

        {
            static constexpr auto unit = s*m;

            STATIC_REQUIRE(unit.size == 2);
            STATIC_REQUIRE(std::get<0>(unit.factors).exponent == 1);
            STATIC_REQUIRE(std::get<0>(unit.factors).symbol == "s");
            STATIC_REQUIRE(std::get<1>(unit.factors).exponent == 1);
            STATIC_REQUIRE(std::get<1>(unit.factors).symbol == "m");
        }

        {
            static constexpr auto unit = m*m*s;

            STATIC_REQUIRE(unit.size == 2);
            STATIC_REQUIRE(std::get<0>(unit.factors).exponent == 1);
            STATIC_REQUIRE(std::get<0>(unit.factors).symbol == "s");
            STATIC_REQUIRE(std::get<1>(unit.factors).exponent == 2);
            STATIC_REQUIRE(std::get<1>(unit.factors).symbol == "m");
        }

        {
            static constexpr auto unit = m*s*m;

            STATIC_REQUIRE(unit.size == 2);
            STATIC_REQUIRE(std::get<0>(unit.factors).exponent == 1);
            STATIC_REQUIRE(std::get<0>(unit.factors).symbol == "s");
            STATIC_REQUIRE(std::get<1>(unit.factors).exponent == 2);
            STATIC_REQUIRE(std::get<1>(unit.factors).symbol == "m");
        }

        {
            static constexpr auto unit = m*m*s;

            STATIC_REQUIRE(unit.size == 2);
            STATIC_REQUIRE(std::get<0>(unit.factors).exponent == 1);
            STATIC_REQUIRE(std::get<0>(unit.factors).symbol == "s");
            STATIC_REQUIRE(std::get<1>(unit.factors).exponent == 2);
            STATIC_REQUIRE(std::get<1>(unit.factors).symbol == "m");
        }
    }
}
