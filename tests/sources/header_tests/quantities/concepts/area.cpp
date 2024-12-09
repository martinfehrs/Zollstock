#include <zollstock/quantities/concepts/area.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("area-concept-header", "[headers][quantities][concepts][area]")
{

    STATIC_REQUIRE(includes_area_concept());

}
