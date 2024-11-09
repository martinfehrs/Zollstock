#include <zollstock/constants/units/length.hpp>
#include <zollstock/constants/units/time.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("velocity-unit-constants", "[velocity][unit][constants]")
{
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, ALL       , m, s  )
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, min)
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, h  )
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, d  )
    TEST_MIXED_DIVISION_UNIT_CONSTANTS(ALL, UNPREFIXED, m, a  )
}
