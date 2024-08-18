#include <zollstock/scalar.hpp>
#include <zollstock/length_units.hpp>
#include <zollstock/angle_units.hpp>
#include <zollstock/math_constants.hpp>

#include <catch2/catch_all.hpp>

#include <climits>


namespace zs = zollstock;

using namespace zs::units;


template <zs::unit_c auto unit, zs::unit_c Unit, zs::number_c Number>
[[nodiscard]] consteval bool check_scalar(
    zs::scalar<unit, Number> s,
    Unit expected_unit,
    Number expected_value
) noexcept
{
    return unit == expected_unit && s.value() == expected_value;
}


TEST_CASE("scalar aliases", "[scalar]")
{
    STATIC_REQUIRE(std::same_as<zs::short_int_t    <>, zs::scalar<_1, short int     >>);
    STATIC_REQUIRE(std::same_as<zs::short_t        <>, zs::scalar<_1, short int     >>);
    STATIC_REQUIRE(std::same_as<zs::int_t          <>, zs::scalar<_1, int           >>);
    STATIC_REQUIRE(std::same_as<zs::long_int_t     <>, zs::scalar<_1, long int      >>);
    STATIC_REQUIRE(std::same_as<zs::long_t         <>, zs::scalar<_1, long int      >>);
    STATIC_REQUIRE(std::same_as<zs::long_long_int_t<>, zs::scalar<_1, long  long int>>);
    STATIC_REQUIRE(std::same_as<zs::long_long_t    <>, zs::scalar<_1, long  long int>>);
    STATIC_REQUIRE(std::same_as<zs::float_t        <>, zs::scalar<_1, float         >>);
    STATIC_REQUIRE(std::same_as<zs::double_t       <>, zs::scalar<_1, double        >>);
    STATIC_REQUIRE(std::same_as<zs::long_double_t  <>, zs::scalar<_1, long double   >>);
}

TEST_CASE("scalar type requirements", "[scalar]")
{
    STATIC_REQUIRE(std::regular<zs::int_t<>>);
    STATIC_REQUIRE(std::same_as<typename zs::int_t<>::value_type, int>);
    STATIC_REQUIRE(zs::int_t<>::unit() == _1);
}

TEST_CASE("scalar value access", "[scalar]")
{
    STATIC_REQUIRE(zs::int_t<>{ 1 }.value() == 1);

    STATIC_REQUIRE(std::add_const_t<zs::int_t<>>{ 1 }.value() == 1);
    STATIC_REQUIRE(zs::int_t<>{ 1 }.cvalue() == 1);
}

TEST_CASE("scalar value assignment", "[scalar]")
{
    zs::int_t<> s{ 0 };

    s.value() = 1;

    REQUIRE(s.value() == 1);
}

TEST_CASE("scalar arithmetic", "[scalar]")
{
    STATIC_REQUIRE(check_scalar(-zs::int_t<>{ 1 }, _1, -1));

    STATIC_REQUIRE(check_scalar(zs::int_t<>{ 0 } += zs::int_t<>{ 1 }, _1, 1));
    STATIC_REQUIRE(check_scalar(zs::int_t<>{ 0 } +  zs::int_t<>{ 1 }, _1, 1));

    STATIC_REQUIRE(check_scalar(zs::int_t<>{ 1 } -= zs::int_t<>{ 1 }, _1, 0));
    STATIC_REQUIRE(check_scalar(zs::int_t<>{ 1 } -  zs::int_t<>{ 1 }, _1, 0));

    STATIC_REQUIRE(check_scalar(zs::int_t<>{ 2 } *= 3, _1, 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<>{ 2 } *  3, _1, 6));

    STATIC_REQUIRE(check_scalar(zs::int_t<>{ 6 } /= 3, _1, 2));
    STATIC_REQUIRE(check_scalar(zs::int_t<>{ 6 } /  3, _1, 2));

    STATIC_REQUIRE(check_scalar(zs::int_t<                 >{ 2 } * zs::int_t<                 >{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<m                >{ 2 } * zs::int_t<                 >{ 3 }, m               , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<                 >{ 2 } * zs::int_t<m                >{ 3 }, m               , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<                 >{ 2 } * zs::int_t<zs::pow_v<_1,  0>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<                 >{ 2 } * zs::int_t<zs::pow_v<_1,  1>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<                 >{ 2 } * zs::int_t<zs::pow_v<_1, -1>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1,  0>>{ 2 } * zs::int_t<                 >{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1,  1>>{ 2 } * zs::int_t<                 >{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1, -1>>{ 2 } * zs::int_t<                 >{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1,  0>>{ 2 } * zs::int_t<zs::pow_v<_1,  0>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1,  0>>{ 2 } * zs::int_t<zs::pow_v<_1,  1>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1,  0>>{ 2 } * zs::int_t<zs::pow_v<_1, -1>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1,  1>>{ 2 } * zs::int_t<zs::pow_v<_1,  0>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1, -1>>{ 2 } * zs::int_t<zs::pow_v<_1, -0>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1,  1>>{ 2 } * zs::int_t<zs::pow_v<_1,  1>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1, -1>>{ 2 } * zs::int_t<zs::pow_v<_1, -1>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1, -1>>{ 2 } * zs::int_t<zs::pow_v<_1,  1>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1,  1>>{ 2 } * zs::int_t<zs::pow_v<_1, -1>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<m                >{ 2 } * zs::int_t<zs::pow_v<_1,  0>>{ 3 }, m               , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<_1,  0>>{ 2 } * zs::int_t<m                >{ 3 }, m               , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<m                >{ 2 } * zs::int_t<m                >{ 3 }, zs::pow_v<m,  2>, 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<m                >{ 2 } * zs::int_t<zs::pow_v<m ,  0>>{ 3 }, m               , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<m                >{ 2 } * zs::int_t<zs::pow_v<m ,  1>>{ 3 }, zs::pow_v<m,  2>, 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<m                >{ 2 } * zs::int_t<zs::pow_v<m , -1>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<m ,  0>>{ 2 } * zs::int_t<m                >{ 3 }, m               , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<m ,  1>>{ 2 } * zs::int_t<m                >{ 3 }, zs::pow_v<m,  2>, 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<m , -1>>{ 2 } * zs::int_t<m                >{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<m                >{ 2 } * zs::int_t<m                >{ 3 }, zs::pow_v<m,  2>, 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<m ,  1>>{ 2 } * zs::int_t<zs::pow_v<m ,  1>>{ 3 }, zs::pow_v<m,  2>, 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<m , -1>>{ 2 } * zs::int_t<zs::pow_v<m , -1>>{ 3 }, zs::pow_v<m, -2>, 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<m ,  1>>{ 2 } * zs::int_t<zs::pow_v<m , -1>>{ 3 }, _1              , 6));
    STATIC_REQUIRE(check_scalar(zs::int_t<zs::pow_v<m , -1>>{ 2 } * zs::int_t<zs::pow_v<m ,  1>>{ 3 }, _1              , 6));

    STATIC_REQUIRE(check_scalar(zs::int_t<  >{ 6 } / zs::int_t<  >{ 3 }, _1, 2));
    STATIC_REQUIRE(check_scalar(zs::int_t<m >{ 6 } / zs::int_t<_1>{ 3 }, m, 2));
    STATIC_REQUIRE(check_scalar(zs::int_t<_1>{ 6 } / zs::int_t<m >{ 3 }, zs::pow_v<m, -1>, 2));
    STATIC_REQUIRE(check_scalar(zs::int_t<m >{ 6 } / zs::int_t<m >{ 3 }, _1, 2));
}

TEST_CASE("scalar comparison", "[scalar]")
{
    STATIC_REQUIRE(zs::int_t<>{ 1 } == zs::int_t<>{ 1 });
    STATIC_REQUIRE(zs::int_t<>{ 0 } != zs::int_t<>{ 1 });
    STATIC_REQUIRE(zs::int_t<>{ 0 } <  zs::int_t<>{ 1 });
    STATIC_REQUIRE(zs::int_t<>{ 1 } >  zs::int_t<>{ 0 });
    STATIC_REQUIRE(zs::int_t<>{ 0 } <= zs::int_t<>{ 1 });
    STATIC_REQUIRE(zs::int_t<>{ 1 } <= zs::int_t<>{ 1 });
    STATIC_REQUIRE(zs::int_t<>{ 1 } >= zs::int_t<>{ 0 });
    STATIC_REQUIRE(zs::int_t<>{ 1 } >= zs::int_t<>{ 1 });

    STATIC_REQUIRE_FALSE(zs::int_t<>{ 1 } == zs::int_t<>{ 0 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 1 } != zs::int_t<>{ 1 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 1 } <  zs::int_t<>{ 0 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 1 } <  zs::int_t<>{ 1 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 0 } >  zs::int_t<>{ 1 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 1 } >  zs::int_t<>{ 1 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 1 } <= zs::int_t<>{ 0 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 0 } >= zs::int_t<>{ 1 });

    STATIC_REQUIRE(zs::int_t<>{ -1 } != zs::unsigned_t<>{ UINT_MAX });
    STATIC_REQUIRE(zs::int_t<>{ -1 } < zs::unsigned_t<>{ 1 });
    STATIC_REQUIRE(zs::unsigned_t<>{ 1 } > zs::int_t<>{ -1 });

    STATIC_REQUIRE_FALSE(zs::int_t<>{ -1 } == zs::unsigned_t<>{ UINT_MAX });
}

TEST_CASE("scalar conversions", "[scalar]")
{
    STATIC_REQUIRE(zs::int_t<m >{ zs::int_t<cm>{ 100 } }.value() ==   1);
    STATIC_REQUIRE(zs::int_t<cm>{ zs::int_t< m>{   1 } }.value() == 100);
    STATIC_REQUIRE(zs::double_t<rad>{ zs::int_t<deg>{ 180 } }.value() == zs::pi);
    STATIC_REQUIRE(zs::double_t<_1>{ zs::int_t<deg>{ 180 } }.value() == zs::pi);
}
