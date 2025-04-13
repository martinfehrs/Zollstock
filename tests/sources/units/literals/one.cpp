#include <zollstock/units/literals/one.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("dimensionless-unit-literals", "[dimensionless][unit][literals]")
{
    TEST_LITERALS(UNPREFIXED, 1 , _1)
}
