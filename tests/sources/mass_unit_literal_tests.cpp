#include <catch2/catch_all.hpp>
#include <zollstock/mass_unit_constants.hpp>
#include <zollstock/mass_unit_literals.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("mass-unit-literals", "[mass][unit][literals]")
{

    TEST_LITERALS(ALL, g)

}
