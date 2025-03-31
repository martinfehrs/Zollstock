#include <zollstock/dimensions.hpp>
#include <catch2/catch_all.hpp>


using namespace zollstock::dimensions;


TEST_CASE("dimensions", "[dimensions]")
{
    static constexpr dimensions_t dimensions_1{ 0, 0, 0,  0, 0, 0, 0 };
    static constexpr dimensions_t dimensions_2{ 0, 0, 0,  1, 0, 0, 0 };
    static constexpr dimensions_t dimensions_3{ 0, 0, 0,  2, 0, 0, 0 };
    static constexpr dimensions_t dimensions_4{ 0, 0, 0, -1, 0, 0, 0 };
    static constexpr dimensions_t dimensions_5{ 0, 0, 1,  1, 0, 0, 0 };

    STATIC_REQUIRE(!dimensions_1.base());
    STATIC_REQUIRE( dimensions_2.base());
    STATIC_REQUIRE(!dimensions_3.base());
    STATIC_REQUIRE(!dimensions_4.base());
    STATIC_REQUIRE(!dimensions_5.base());

    STATIC_REQUIRE( dimensions_1.derived());
    STATIC_REQUIRE(!dimensions_2.derived());
    STATIC_REQUIRE( dimensions_3.derived());
    STATIC_REQUIRE( dimensions_4.derived());
    STATIC_REQUIRE( dimensions_5.derived());

    STATIC_REQUIRE(!dimensions_1.homogeneous());
    STATIC_REQUIRE( dimensions_2.homogeneous());
    STATIC_REQUIRE( dimensions_3.homogeneous());
    STATIC_REQUIRE( dimensions_4.homogeneous());
    STATIC_REQUIRE(!dimensions_5.homogeneous());
}
