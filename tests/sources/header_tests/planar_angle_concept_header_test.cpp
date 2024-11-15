#include <zollstock/quantities/concepts/planar_angle.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("planar-angle-concept-header", "[headers][concept][planar-angle]")
{

    STATIC_REQUIRE(includes_planar_angle_concept());

}
