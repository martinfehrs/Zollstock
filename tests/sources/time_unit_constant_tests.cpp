#include <catch2/catch_all.hpp>
#include <zollstock/time_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("time-unit-constants", "[time][unit][constants]")
{

    ZOLLSTOCK_TESTS_TEST_SI_CONSTANTS(, second, s)

}
