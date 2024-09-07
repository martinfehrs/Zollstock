#include <zollstock/mass_units.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("mass-units-headers", "[headers][mass-units]")
{

    STATIC_REQUIRE(includes_mass_units);
    STATIC_REQUIRE(includes_mass_unit_constants);
    STATIC_REQUIRE(includes_mass_unit_literals);

}
