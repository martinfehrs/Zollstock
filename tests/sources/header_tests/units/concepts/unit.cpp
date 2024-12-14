#include <zollstock/units/concepts/unit.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("unit-concept-header", "[headers][units][concepts][unit]")
{

    STATIC_REQUIRE(includes_unit_concept());

}
