#include <catch2/catch_all.hpp>
#include <zollstock/time_unit_types.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("time-unit-types", "[time][unit][types]")
{

    ZOLLSTOCK_TESTS_TEST_SI_TYPES(time,, second, 1.0L, s)

    ZOLLSTOCK_TESTS_TEST_TYPE(time, minute, 60.0L, min)

    ZOLLSTOCK_TESTS_TEST_TYPE(time, hour, 3'600.0L, h)

    ZOLLSTOCK_TESTS_TEST_TYPE(time, day, 86'400.0L, d)

    ZOLLSTOCK_TESTS_TEST_TYPE(time, year, 31'536'000.0L, a)

}
