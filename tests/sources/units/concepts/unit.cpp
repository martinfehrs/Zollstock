#include <zollstock/units/concepts/unit.hpp>
#include <catch2/catch_all.hpp>


using namespace zollstock;
using namespace zollstock::detail;
using namespace zollstock::dimensions;


using m_t  = unit_factor<L, "m", 1.0L,  "", 1>;
using cm_t = unit_factor<L, "m", 1.0L, "c", 1>;
using s_t  = unit_factor<T, "s", 1.0L,  "", 1>;

static constexpr unit_product<    > u1{};
static constexpr unit_product< m_t>  m{};
static constexpr unit_product<cm_t> cm{};
static constexpr unit_product< s_t>  s{};


TEST_CASE("unit-concatenation", "[units][concepts][unit]")
{
    STATIC_REQUIRE(unit_product_concat(u1, u1) == u1);
    STATIC_REQUIRE(unit_product_concat( m, u1) ==  m);
    STATIC_REQUIRE(unit_product_concat(u1,  m) ==  m);

    static constexpr auto mixed_product_1 = unit_product_concat(m,  s);

    STATIC_REQUIRE(mixed_product_1.size == 2);
    STATIC_REQUIRE(std::get<0>(mixed_product_1.factors) == std::get<0>(m.factors));
    STATIC_REQUIRE(std::get<1>(mixed_product_1.factors) == std::get<0>(s.factors));

    static constexpr auto mixed_product_2 = unit_product_concat(mixed_product_1, cm);

    STATIC_REQUIRE(mixed_product_2.size == 3);
    STATIC_REQUIRE(std::get<0>(mixed_product_2.factors) == std::get<0>(m.factors));
    STATIC_REQUIRE(std::get<1>(mixed_product_2.factors) == std::get<0>(s.factors));
    STATIC_REQUIRE(std::get<2>(mixed_product_2.factors) == std::get<0>(cm.factors));
}

TEST_CASE("unit-iteration", "[units][concepts][unit]")
{
    STATIC_REQUIRE(unit_product_head(s) ==  s);
    STATIC_REQUIRE(unit_product_tail(s) == u1);

    static constexpr unit_product<m_t, s_t, cm_t> mixed_product{};

    STATIC_REQUIRE(unit_product_head(mixed_product) == m);

    static constexpr auto tail_1 = unit_product_tail(mixed_product);

    STATIC_REQUIRE(unit_product_head(tail_1) == s);
    STATIC_REQUIRE(tail_1 == unit_product<s_t, cm_t>{});

    static constexpr auto tail_2 = unit_product_tail(tail_1);

    STATIC_REQUIRE(unit_product_head(tail_2) == cm);
    STATIC_REQUIRE(tail_2 == cm);

    static constexpr auto tail_3 = unit_product_tail(tail_2);

    // Gewollter Kompiliertungsfehler. Einheitenprodukt tail_3 hat keinen Kopf.
    //STATIC_REQUIRE(unit_product_head(tail_3) == ?);
    STATIC_REQUIRE(tail_3 == u1);

    // Gewollter Kompiliertungsfehler. Einheitenprodukt tail_3 hat keinen Schwanz.
    //static constexpr auto tail_4 = unit_product_tail(tail_3);
}


TEST_CASE("unit-arithmetic", "[units][concepts][unit]")
{
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
