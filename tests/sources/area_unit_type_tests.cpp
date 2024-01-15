#include <catch2/catch_all.hpp>
#include <zollstock/area_unit_types.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("area-unit-types", "[area][unit][types]")
{

    ZOLLSTOCK_TESTS_TEST_SI_TYPES(AREA, square_, meter, 1e0, m2)

}
