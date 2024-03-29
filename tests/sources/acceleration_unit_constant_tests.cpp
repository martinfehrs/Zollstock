#include <catch2/catch_all.hpp>
#include <zollstock/length_unit_constants.hpp>
#include <zollstock/squared_time_unit_constants.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("acceleration-unit-constants", "[acceleration][unit][constants]")
{

    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, ALL       , m, s2  )
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, min2)
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, h2  )
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, d2  )
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, a2  )

}
