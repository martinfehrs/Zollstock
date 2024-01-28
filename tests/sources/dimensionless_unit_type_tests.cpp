#include <catch2/catch_all.hpp>
#include <zollstock/dimensionless_unit_types.hpp>
#include <zollstock/tests/test_helpers.hpp>

using namespace zollstock;


TEST_CASE("dimensionless-unit-types", "[dimensionless][unit][types]")
{

    REQUIRE(one::exponents == unit_exponents{ 0    , 0    , 0     });
    REQUIRE(one::factors   == unit_factors  { 0.0L , 0.0L , 0.0L  });
    REQUIRE(one::symbols   == unit_symbols  { ""_us, ""_us, ""_us });

}
