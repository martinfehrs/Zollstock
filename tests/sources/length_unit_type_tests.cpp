#include <catch2/catch_all.hpp>
#include <zollstock/length_unit_types.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("length-unit-types", "[length][unit][types]")
{

    ZOLLSTOCK_TESTS_TEST_SI_TYPES(LENGTH,, meter, 1e0L, m)

}
