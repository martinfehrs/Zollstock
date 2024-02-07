#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_types.hpp>
#include <zollstock/tests/test_helpers.hpp>

using namespace zollstock;


TEST_CASE("angle-unit-types", "[angle][unit][types]")
{

    TEST_TYPES(ALL       , angle  , radian   , 1e0L     , rad   )
    TEST_TYPES(UNPREFIXED, angle  , degree   , pi/18e1L , deg   )
    TEST_TYPES(UNPREFIXED, angle  , arcminute, pi/108e2L, amin  )
    TEST_TYPES(UNPREFIXED, angle  , arcsecond, pi/648e3L, arcsec)
    TEST_TYPES(PREFIXED  , angle  , arcsecond, pi/648e3L, as    )
    TEST_TYPES(ALL       , angle  , gradian  , pi/2e2L  , gon   )

}
