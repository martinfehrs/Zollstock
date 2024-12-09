#include <zollstock/units/base.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("base-units-header", "[headers][units][base]")
{

    STATIC_REQUIRE(includes_base_units());

}
