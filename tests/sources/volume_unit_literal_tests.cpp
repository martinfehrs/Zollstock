#include <catch2/catch_all.hpp>
#include <zollstock/volume_unit_literals.hpp>
#include <zollstock/tests/test_helpers.hpp>
#include <zollstock/unit_algorithms.hpp>


using namespace zollstock;


TEST_CASE("volume-unit-literals", "[volume][unit][literals]")
{

    ZOLLSTOCK_TESTS_TEST_SI_LITERALS(m3)


}
