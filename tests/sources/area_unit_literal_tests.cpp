#include <catch2/catch_all.hpp>
#include <zollstock/area_unit_literals.hpp>
#include <zollstock/tests/test_helpers.hpp>
#include <zollstock/unit_algorithms.hpp>


using namespace zollstock;


TEST_CASE("area-unit-literals", "[area][unit][literals]")
{

    TEST_LITERALS(ALL, m2)

}
