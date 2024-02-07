#include <catch2/catch_all.hpp>
#include <zollstock/length_unit_types.hpp>
#include <zollstock/tests/type_test_helpers.hpp>


using namespace zollstock;


TEST_CASE("length-unit-types", "[length][unit][types]")
{

    TEST_TYPES(ALL, length, meter, 1e0L, m)

}
