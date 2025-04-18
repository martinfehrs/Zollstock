#define ZOLLSTOCK_QUANTITY_PUBLIC_MEMBERS
#include <zollstock/quantities/template.hpp>

#include <catch2/catch_all.hpp>

#include <climits>


namespace zs = zollstock;

using namespace zs::units;


TEST_CASE("quantity construction", "[quantity]")
{
    STATIC_REQUIRE(zs::int_t<>{}.value_ == 0);
    STATIC_REQUIRE(zs::int_t<>{ 1 }.value_ == 1);
    STATIC_REQUIRE(zs::int_t<>{ zs::int_t<>{ 1 } }.value_ == 1);
    STATIC_REQUIRE(zs::int_t<>{ zs::long_long_int_t<>{ 1 } }.value_ == 1);
    REQUIRE_THROWS(zs::int_t<>{ zs::long_long_int_t<>{ LLONG_MAX } });
    STATIC_REQUIRE(zs::int_t<>{ zs::unsigned_int_t<>{ 1 } }.value_ == 1);
    REQUIRE_THROWS(zs::int_t<>{ zs::unsigned_int_t<>{ UINT_MAX } });
}
