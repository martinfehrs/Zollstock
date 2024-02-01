#include <catch2/catch_all.hpp>
#include <zollstock/area_unit_constants.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("area-unit-constants", "[area][unit][constants]")
{

    ZOLLSTOCK_TESTS_TEST_RAISED_UNIT_CONSTANTS(ALL, m, 2)

}
