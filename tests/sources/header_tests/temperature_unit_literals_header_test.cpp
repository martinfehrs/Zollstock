#include <zollstock/temperature_unit_literals.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("temperature-unit-literals-header", "[headers][temperature-units]")
{

    STATIC_REQUIRE(includes_temperature_unit_literals());

}
