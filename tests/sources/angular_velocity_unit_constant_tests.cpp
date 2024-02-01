#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/time_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("angular-velocity-unit-constants", "[angular-velocity][unit][constants]")
{

    ZOLLSTOCK_TESTS_TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, ALL       , rad, s  )
    ZOLLSTOCK_TESTS_TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, rad, min)
    ZOLLSTOCK_TESTS_TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, rad, h  )
    ZOLLSTOCK_TESTS_TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, rad, d  )
    ZOLLSTOCK_TESTS_TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, rad, a  )

}
