#include <zollstock/constants/units/mass.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("mass-unit-constants", "[mass][unit][constants]")
{
    TEST_BASE_UNIT_CONSTANTS(ALL, g, M)
}
