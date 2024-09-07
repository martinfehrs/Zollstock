#include <zollstock/temperature_units.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("temperature-units-headers", "[headers][temperature-units]")
{

    STATIC_REQUIRE(includes_temperature_units);
    STATIC_REQUIRE(includes_temperature_unit_constants);
    STATIC_REQUIRE(includes_temperature_unit_literals);

}
