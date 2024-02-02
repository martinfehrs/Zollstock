#include <catch2/catch_all.hpp>
#include <zollstock/length_unit_constants.hpp>
#include <zollstock/time_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("velocity-unit-constants", "[velocity][unit][constants]")
{

    ZOLLSTOCK_TESTS_TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, ALL, m, s)

}