#include <zollstock/area_units.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("area-units-headers", "[headers][area-units]")
{

    STATIC_REQUIRE(includes_area_units);
    STATIC_REQUIRE(includes_area_unit_constants);
    STATIC_REQUIRE(includes_area_unit_literals);

}
