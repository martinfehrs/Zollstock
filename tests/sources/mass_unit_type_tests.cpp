#include <catch2/catch_all.hpp>
#include <zollstock/mass_unit_types.hpp>
#include <zollstock/tests/type_test_helpers.hpp>



TEST_CASE("mass-unit-types", "[mass][unit][types]")
{
    using namespace zollstock;

    TEST_BASE_TYPES(ALL, gram, quantity::mass, "g"_us, 1e0L);
}
