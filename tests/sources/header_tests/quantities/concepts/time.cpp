#include <zollstock/quantities/concepts/time.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("time-concept-header", "[headers][quantities][concepts][time]")
{

    STATIC_REQUIRE(includes_time_concept());

}
