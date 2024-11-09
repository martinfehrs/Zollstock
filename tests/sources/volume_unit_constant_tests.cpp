#include <zollstock/constants/units/volume.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("volume-unit-constants", "[volume][unit][constants]")
{
    TEST_RAISED_UNIT_CONSTANTS(ALL, m, 3)
}
