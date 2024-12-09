#include <zollstock/quantities/concepts/volume.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("volume-concept-header", "[headers][quantities][concepts][volume]")
{

    STATIC_REQUIRE(includes_volume_concept());

}
