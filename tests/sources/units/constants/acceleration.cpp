#include <zollstock/units/constants/length.hpp>
#include <zollstock/units/constants/squared_time.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("acceleration-unit-constants", "[acceleration][unit][constants]")
{
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, ALL       , m, s2  )
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, min2)
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, h2  )
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, d2  )
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, a2  )
}
