#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_types.hpp>
#include <zollstock/tests/type_test_helpers.hpp>

using namespace zollstock;


TEST_CASE("angle-unit-types", "[angle][unit][types]")
{

    TEST_BASE_TYPES(ALL       , radian   , quantity::angle, "rad"_us   , 1e0L     )
    TEST_BASE_TYPES(UNPREFIXED, degree   , quantity::angle, "deg"_us   , pi/18e1L )
    TEST_BASE_TYPES(UNPREFIXED, arcminute, quantity::angle, "amin"_us  , pi/108e2L)
    TEST_BASE_TYPES(UNPREFIXED, arcsecond, quantity::angle, "arcsec"_us, pi/648e3L)
    TEST_BASE_TYPES(PREFIXED  , arcsecond, quantity::angle, "as"_us    , pi/648e3L)
    TEST_BASE_TYPES(ALL       , gradian  , quantity::angle, "gon"_us   , pi/2e2L  )

}
