#define ZOLLSTOCK_QUANTITY_PUBLIC_MEMBERS
#include <zollstock/math.hpp>

#include <catch2/catch_all.hpp>

#include <numbers>


namespace zs = zollstock;

using namespace zs::units;
using namespace Catch::Matchers;


TEST_CASE("trigonometric_functions", "[trigonometric_functions]")
{

    REQUIRE(zs::sin(0.0_rad     ).value_ == std::sin(0.0               ));
    REQUIRE(zs::sin(zs::pi_rad/2).value_ == std::sin(std::numbers::pi/2));

    REQUIRE(zs::cos(0.0_rad     ).value_ == std::cos(0.0     ));
    REQUIRE(zs::cos(zs::pi_rad/2).value_ == std::cos(std::numbers::pi/2));

    REQUIRE(zs::tan(0.0_rad     ).value_ == std::tan(0.0     ));
    REQUIRE(zs::tan(zs::pi_rad/2).value_ == std::tan(std::numbers::pi/2));

    REQUIRE(zs::asin(0.0_1).value_ == std::asin(0.0));
    REQUIRE(zs::asin(1.0_1).value_ == std::asin(1.0));

    REQUIRE(zs::acos(0.0_1).value_ == std::acos(0.0));
    REQUIRE(zs::acos(1.0_1).value_ == std::acos(1.0));

    REQUIRE(zs::atan(0.0_1).value_ == std::atan(0.0));
    REQUIRE(zs::atan(1.0_1).value_ == std::atan(1.0));

}
