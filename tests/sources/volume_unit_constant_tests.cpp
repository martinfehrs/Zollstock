#include <catch2/catch_all.hpp>
#include <zollstock/volume_unit_constants.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>


using namespace zollstock::units;


TEST_CASE("volume-unit-constants", "[volume][unit][constants]")
{

    TEST_RAISED_UNIT_CONSTANTS(ALL, m, 3)

}
