#include <catch2/catch_all.hpp>
#include <zollstock/quantity.hpp>
#include <zollstock/dimensionless_unit_constants.hpp>

#include <climits>


using namespace zollstock;
namespace zs = zollstock;

TEST_CASE("quantity", "[quantity]")
{

    // Kein Verlust des Vorzeichens bei Vergleichen
    REQUIRE_FALSE(zs::int_t{ -1 } == zs::unsigned_t{ UINT_MAX });
    REQUIRE(zs::int_t{ -1 } != zs::unsigned_t{ UINT_MAX });
    REQUIRE(zs::int_t{ -1 } < zs::unsigned_t{ 1 });
    REQUIRE(zs::unsigned_t{ 1 } > zs::int_t{ -1 });

}
