#include <catch2/catch_all.hpp>
#include <zollstock/area_unit_constants.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("area-unit-constants", "[area][unit][constants]")
{

    TEST_RAISED_UNIT_CONSTANTS(ALL, m, 2)

}
