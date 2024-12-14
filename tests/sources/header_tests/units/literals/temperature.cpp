#include <zollstock/units/literals/temperature.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("temperature-unit-literals-header", "[headers][units][literals][temperature]")
{

    STATIC_REQUIRE(includes_temperature_literals());

}
