#include <catch2/catch_all.hpp>
#include <zollstock/length_unit_types.hpp>
#include <zollstock/tests/type_test_helpers.hpp>



TEST_CASE("length-unit-types", "[length][unit][types]")
{
    using namespace zollstock;

    TEST_BASE_TYPES(ALL, meter, quantity_t::length, "m"_us, 1e0L)
}
