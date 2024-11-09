#include <zollstock/units/temperature.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("temperature-units-header", "[headers][temperature-units]")
{

    STATIC_REQUIRE(includes_temperature_units());

}
