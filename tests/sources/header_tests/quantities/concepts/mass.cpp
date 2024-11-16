#include <zollstock/quantities/concepts/mass.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("mass-concept-header", "[headers][concept][mass]")
{

    STATIC_REQUIRE(includes_mass_concept());

}
