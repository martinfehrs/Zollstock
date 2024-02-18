#include <catch2/catch_all.hpp>
#include <zollstock/mass_unit_types.hpp>
#include <zollstock/tests/type_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("mass-unit-types", "[mass][unit][types]")
{

    TEST_TYPES(ALL, mass, gram, 1e0L, g)

}
