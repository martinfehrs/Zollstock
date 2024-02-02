#include <catch2/catch_all.hpp>
#include <zollstock/length_unit_constants.hpp>
#include <zollstock/squared_time_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("acceleration-unit-constants", "[acceleration][unit][constants]")
{

    ZOLLSTOCK_TESTS_TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, ALL       , m, s2  )
    ZOLLSTOCK_TESTS_TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, min2)
    ZOLLSTOCK_TESTS_TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, h2  )
    ZOLLSTOCK_TESTS_TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, d2  )
    ZOLLSTOCK_TESTS_TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, a2  )
}
