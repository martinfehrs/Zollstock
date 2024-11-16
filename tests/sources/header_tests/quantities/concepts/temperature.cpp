#include <zollstock/quantities/concepts/temperature.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("temperature-concept-header", "[headers][concept][temperature]")
{

    STATIC_REQUIRE(includes_temperature_concept());

}
