#include <catch2/catch_all.hpp>
#include <zollstock/length_unit_constants.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("length-unit-constants", "[length][unit][constants]")
{

    TEST_BASE_UNIT_CONSTANTS(ALL, meter, m)

}
