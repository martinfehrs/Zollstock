#include <catch2/catch_all.hpp>
#include <zollstock/squared_time_unit_constants.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("squared-time-unit-constants", "[squared-time][unit][constants]")
{

    ZOLLSTOCK_TESTS_TEST_SI_RAISED_UNIT_CONSTANTS(s, 2)

    ZOLLSTOCK_TESTS_TEST_RAISED_UNIT_CONSTANT(min, 2)
    ZOLLSTOCK_TESTS_TEST_RAISED_UNIT_CONSTANT(h  , 2)
    ZOLLSTOCK_TESTS_TEST_RAISED_UNIT_CONSTANT(d  , 2)
    ZOLLSTOCK_TESTS_TEST_RAISED_UNIT_CONSTANT(a  , 2)

}
