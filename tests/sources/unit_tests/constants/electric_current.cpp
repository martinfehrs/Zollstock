#include <zollstock/units/constants/electric_current.hpp>
#include <zollstock/tests/constant_test_helpers.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock::units;


TEST_CASE("electric_current-unit-constants", "[electric-current][unit][constants]")
{
    TEST_BASE_UNIT_CONSTANTS(ALL, A, I)
}
