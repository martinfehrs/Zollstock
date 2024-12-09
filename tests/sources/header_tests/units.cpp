#include <zollstock/units.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("all-units-header", "[headers][units]")
{

    STATIC_REQUIRE(includes_units());
}
