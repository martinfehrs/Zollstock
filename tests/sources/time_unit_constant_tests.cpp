#include <catch2/catch_all.hpp>
#include <zollstock/time_unit_constants.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("time-unit-constants", "[time][unit][constants]")
{

    TEST_BASE_UNIT_CONSTANTS(ALL, s, time)

}
