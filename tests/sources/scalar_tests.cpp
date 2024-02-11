#include <catch2/catch_all.hpp>
#include <zollstock/scalar.hpp>

#include <climits>


namespace zs = zollstock;

using namespace zs::units;


TEST_CASE("scalar", "[scalar]")
{

    STATIC_REQUIRE(std::regular<zs::short_int_t             <>>);
    STATIC_REQUIRE(std::regular<zs::short_t                 <>>);
    STATIC_REQUIRE(std::regular<zs::int_t                   <>>);
    STATIC_REQUIRE(std::regular<zs::long_int_t              <>>);
    STATIC_REQUIRE(std::regular<zs::long_t                  <>>);
    STATIC_REQUIRE(std::regular<zs::long_long_int_t         <>>);
    STATIC_REQUIRE(std::regular<zs::long_long_t             <>>);
    STATIC_REQUIRE(std::regular<zs::unsigned_short_int_t    <>>);
    STATIC_REQUIRE(std::regular<zs::unsigned_int_t          <>>);
    STATIC_REQUIRE(std::regular<zs::unsigned_long_int_t     <>>);
    STATIC_REQUIRE(std::regular<zs::unsigned_long_long_int_t<>>);
    STATIC_REQUIRE(std::regular<zs::float_t                 <>>);
    STATIC_REQUIRE(std::regular<zs::double_t                <>>);
    STATIC_REQUIRE(std::regular<zs::long_double_t           <>>);

    STATIC_REQUIRE(std::same_as<zs::short_int_t    <>::value_type, short int    >);
    STATIC_REQUIRE(std::same_as<zs::short_t        <>::value_type, short        >);
    STATIC_REQUIRE(std::same_as<zs::int_t          <>::value_type, int          >);
    STATIC_REQUIRE(std::same_as<zs::long_int_t     <>::value_type, long int     >);
    STATIC_REQUIRE(std::same_as<zs::long_t         <>::value_type, long         >);
    STATIC_REQUIRE(std::same_as<zs::long_long_int_t<>::value_type, long long int>);
    STATIC_REQUIRE(std::same_as<zs::long_long_t    <>::value_type, long long    >);
    STATIC_REQUIRE(std::same_as<zs::float_t        <>::value_type, float        >);
    STATIC_REQUIRE(std::same_as<zs::double_t       <>::value_type, double       >);
    STATIC_REQUIRE(std::same_as<zs::long_double_t  <>::value_type, long double  >);

    STATIC_REQUIRE(std::same_as<zs::short_int_t    <>::unit_type, one>);
    STATIC_REQUIRE(std::same_as<zs::short_t        <>::unit_type, one>);
    STATIC_REQUIRE(std::same_as<zs::int_t          <>::unit_type, one>);
    STATIC_REQUIRE(std::same_as<zs::long_int_t     <>::unit_type, one>);
    STATIC_REQUIRE(std::same_as<zs::long_t         <>::unit_type, one>);
    STATIC_REQUIRE(std::same_as<zs::long_long_int_t<>::unit_type, one>);
    STATIC_REQUIRE(std::same_as<zs::long_long_t    <>::unit_type, one>);
    STATIC_REQUIRE(std::same_as<zs::float_t        <>::unit_type, one>);
    STATIC_REQUIRE(std::same_as<zs::double_t       <>::unit_type, one>);
    STATIC_REQUIRE(std::same_as<zs::long_double_t  <>::unit_type, one>);

    STATIC_REQUIRE(zs::short_int_t    <>::unit() == _1);
    STATIC_REQUIRE(zs::short_t        <>::unit() == _1);
    STATIC_REQUIRE(zs::int_t          <>::unit() == _1);
    STATIC_REQUIRE(zs::long_int_t     <>::unit() == _1);
    STATIC_REQUIRE(zs::long_t         <>::unit() == _1);
    STATIC_REQUIRE(zs::long_long_int_t<>::unit() == _1);
    STATIC_REQUIRE(zs::long_long_t    <>::unit() == _1);
    STATIC_REQUIRE(zs::float_t        <>::unit() == _1);
    STATIC_REQUIRE(zs::double_t       <>::unit() == _1);
    STATIC_REQUIRE(zs::long_double_t  <>::unit() == _1);

    STATIC_REQUIRE_FALSE(zs::int_t<>{ -1 } == zs::unsigned_t<>{ UINT_MAX });

    STATIC_REQUIRE(zs::int_t<>{ -1 } != zs::unsigned_t<>{ UINT_MAX });
    STATIC_REQUIRE(zs::int_t<>{ -1 } < zs::unsigned_t<>{ 1 });
    STATIC_REQUIRE(zs::unsigned_t<>{ 1 } > zs::int_t<>{ -1 });

}
