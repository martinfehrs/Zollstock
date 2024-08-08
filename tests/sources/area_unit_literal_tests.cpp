#include <catch2/catch_all.hpp>
#include <zollstock/area_unit_literals.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>


using namespace zollstock::units;


TEST_CASE("area-unit-literals", "[area][unit][literals]")
{
    TEST_LITERALS(ALL, m2)
}
