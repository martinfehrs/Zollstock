#include <catch2/catch_all.hpp>
#include <zollstock/scalar.hpp>
#include <zollstock/dimensionless_unit.hpp>

#include <climits>


using namespace zollstock;
namespace zs = zollstock;

TEST_CASE("scalar", "[scalar]")
{

    REQUIRE_FALSE(int_t<>{ -1 } == unsigned_t<>{ UINT_MAX });
    REQUIRE(int_t<>{ -1 } != unsigned_t<>{ UINT_MAX });
    REQUIRE(int_t<>{ -1 } < unsigned_t<>{ 1 });
    REQUIRE(unsigned_t<>{ 1 } > int_t<>{ -1 });

}
