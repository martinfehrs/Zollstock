#include <catch2/catch_all.hpp>
#include <zollstock/time_unit_constants.hpp>
#include <zollstock/time_unit_literals.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("time-unit-literals", "[time][unit][literals]")
{

    ZOLLSTOCK_TESTS_TEST_SI_LITERALS(s)

}