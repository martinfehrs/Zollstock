#include <zollstock/all_units.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("all-units-header", "[headers][all-units]")
{

    STATIC_REQUIRE(includes_all_units());
}
