#include <zollstock/units/concepts/prefix.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("prefix-concept-header", "[headers][units][concepts][prefix]")
{

    STATIC_REQUIRE(includes_prefix_concept());

}
