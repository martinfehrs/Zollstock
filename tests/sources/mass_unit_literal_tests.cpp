#include <zollstock/units/literals/mass.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("mass-unit-literals", "[mass][unit][literals]")
{
    TEST_LITERALS(ALL, g)
}
