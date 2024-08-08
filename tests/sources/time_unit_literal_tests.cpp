#include <zollstock/time_unit_constants.hpp>
#include <zollstock/time_unit_literals.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("time-unit-literals", "[time][unit][literals]")
{
    TEST_LITERALS(ALL, s)
}
