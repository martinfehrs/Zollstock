#include <zollstock/length_unit_constants.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("length-unit-constants", "[length][unit][constants]")
{
    TEST_BASE_UNIT_CONSTANTS(ALL, m, L)
}
