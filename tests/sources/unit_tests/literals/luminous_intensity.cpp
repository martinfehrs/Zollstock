#include <zollstock/units/literals/luminous_intensity.hpp>
#include <zollstock/tests/literal_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("luminous-intensity-unit-literals", "[luminous-intensity][unit][literals]")
{
    TEST_LITERALS(ALL, cd)
}
