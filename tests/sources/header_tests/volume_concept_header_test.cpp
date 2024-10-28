#include <zollstock/volume_concept.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("volume-concept-header", "[headers][concept][volume]")
{

    STATIC_REQUIRE(includes_volume_concept());

}
