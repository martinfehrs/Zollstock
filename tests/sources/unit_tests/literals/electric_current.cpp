#include <zollstock/units/literals/electric_current.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("electric-current-unit-literals", "[electriccurrent][unit][literals]")
{
    TEST_LITERALS(ALL, A)
}
