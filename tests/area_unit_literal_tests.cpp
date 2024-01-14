#include <catch2/catch_all.hpp>
#include <zollstock/area_unit_constants.hpp>
#include <zollstock/area_unit_literals.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("area-unit-literals", "[area][unit][literals]")
{

    ZOLLSTOCK_TESTS_TEST_SI_LITERALS(m2)

}
