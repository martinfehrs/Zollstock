#include <catch2/catch_all.hpp>
#include <zollstock/volume_unit_types.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("volume-unit-types", "[volume][unit][types]")
{

    ZOLLSTOCK_TESTS_TEST_SI_TYPES(VOLUME, cubic_, meter, 1e0, m3)

}
