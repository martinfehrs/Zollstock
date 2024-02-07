#include <catch2/catch_all.hpp>
#include <zollstock/time_unit_constants.hpp>
#include <zollstock/time_unit_literals.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("time-unit-literals", "[time][unit][literals]")
{

    TEST_LITERALS(ALL, s)

}
