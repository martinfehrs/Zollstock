#include <catch2/catch_all.hpp>
#include <zollstock/volume_unit_constants.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("volume-unit-constants", "[volume][unit][constants]")
{

    ZOLLSTOCK_TESTS_TEST_RAISED_UNIT_CONSTANTS(ALL, m, 3)

}
