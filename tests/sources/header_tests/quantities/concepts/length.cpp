#include <zollstock/quantities/concepts/length.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("length-concept-header", "[headers][concept][length]")
{

    STATIC_REQUIRE(includes_length_concept());

}