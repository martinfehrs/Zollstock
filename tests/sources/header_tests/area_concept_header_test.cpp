#include <zollstock/concepts/area.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("area-concept-header", "[headers][concept][area]")
{

    STATIC_REQUIRE(includes_area_concept());

}
