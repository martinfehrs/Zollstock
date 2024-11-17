#include <zollstock/units/constants/area.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("area-unit-constants", "[area][unit][constants]")
{
    TEST_RAISED_UNIT_CONSTANTS(ALL, m, 2)
}
