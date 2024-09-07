#include <zollstock/length_units.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("length-units-headers", "[headers][length-units]")
{

    STATIC_REQUIRE(includes_length_units);
    STATIC_REQUIRE(includes_length_unit_constants);
    STATIC_REQUIRE(includes_length_unit_literals);

}
