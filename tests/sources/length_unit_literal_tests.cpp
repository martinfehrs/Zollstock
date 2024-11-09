#include <zollstock/units/length.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("length-unit-literals", "[length][unit][literals]")
{
    TEST_LITERALS(ALL, m)
}
