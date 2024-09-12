#include <zollstock/volume_units.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("volume-unit-literals", "[volume][unit][literals]")
{
    TEST_LITERALS(ALL, m3)
}
