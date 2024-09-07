#include <zollstock/all.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("all-headers", "[headers][all]")
{

    STATIC_REQUIRE(includes_all());
}
