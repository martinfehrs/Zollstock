#include <zollstock/units/constants/luminous_intensity.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("luminous-intensity-unit-constants", "[luminous-intensity][unit][constants]")
{
    TEST_BASE_UNIT_CONSTANTS(ALL, cd, J)
}
