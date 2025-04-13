#include <zollstock/units/literals/area.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("area-unit-literals", "[area][unit][literals]")
{
    TEST_LITERALS(ALL, m2, m2)
}
