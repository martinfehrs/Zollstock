#include <zollstock/concepts/time.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("time-concept-header", "[headers][concept][time]")
{

    STATIC_REQUIRE(includes_time_concept());

}
