#include <zollstock/angle_units.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("angle-units-headers", "[headers][angle-units]")
{

    STATIC_REQUIRE(includes_angle_units);
    STATIC_REQUIRE(includes_angle_unit_constants);
    STATIC_REQUIRE(includes_angle_unit_literals);

}
