#include <catch2/catch_all.hpp>
#include <zollstock/length_unit_constants.hpp>
#include <zollstock/length_unit_literals.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("length-unit-literals", "[length][unit][literals]")
{

    ZOLLSTOCK_TESTS_TEST_LITERALS(ALL, m)

}
