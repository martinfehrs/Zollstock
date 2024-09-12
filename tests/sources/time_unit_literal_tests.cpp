#include <zollstock/time_units.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("time-unit-literals", "[time][unit][literals]")
{
    TEST_LITERALS(ALL, s)
}
