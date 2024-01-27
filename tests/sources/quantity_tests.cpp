#include <catch2/catch_all.hpp>
#include <zollstock/quantity.hpp>
#include <zollstock/dimensionless_unit.hpp>

#include <climits>


using namespace zollstock;
namespace zs = zollstock;

TEST_CASE("quantity", "[quantity]")
{

    REQUIRE_FALSE(int_t<>{ -1 } == unsigned_t<>{ UINT_MAX });
    REQUIRE(int_t<>{ -1 } != unsigned_t<>{ UINT_MAX });
    REQUIRE(int_t<>{ -1 } < unsigned_t<>{ 1 });
    REQUIRE(unsigned_t<>{ 1 } > int_t<>{ -1 });

}
