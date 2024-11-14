#include <zollstock/units/literals/temperature.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("temperature-unit-literals", "[temperature][unit][literals]")
{
    TEST_LITERALS(ALL, K)
}
