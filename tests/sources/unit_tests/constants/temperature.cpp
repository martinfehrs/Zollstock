#include <zollstock/units/constants/temperature.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("temperature-unit-constants", "[temperature][unit][constants]")
{
    TEST_BASE_UNIT_CONSTANTS(ALL, K, Theta)
}
