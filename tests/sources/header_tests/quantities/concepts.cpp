#include <zollstock/quantities/concepts.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("quantity-concepts-header", "[headers][quantities][concepts]")
{

    STATIC_REQUIRE(includes_quantity_concepts());

}
