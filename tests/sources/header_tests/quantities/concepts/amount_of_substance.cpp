#include <zollstock/quantities/concepts/amount_of_substance.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("amount-of-substance-concept-header", "[headers][concept][amount-of-substance]")
{

    STATIC_REQUIRE(includes_amount_of_substance_concept());

}
