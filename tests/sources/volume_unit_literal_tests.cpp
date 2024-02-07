#include <catch2/catch_all.hpp>
#include <zollstock/volume_unit_literals.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>
#include <zollstock/unit_algorithms.hpp>


using namespace zollstock;


TEST_CASE("volume-unit-literals", "[volume][unit][literals]")
{

    TEST_LITERALS(ALL, m3)

}
