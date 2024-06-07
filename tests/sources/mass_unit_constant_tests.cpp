#include <catch2/catch_all.hpp>
#include <zollstock/mass_unit_constants.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("mass-unit-constants", "[mass][unit][constants]")
{

    TEST_BASE_UNIT_CONSTANTS(ALL, g, mass)

}
