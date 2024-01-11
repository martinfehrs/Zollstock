#include <catch2/catch_all.hpp>
#include <zollstock/length_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>


using namespace zollstock;


TEST_CASE("length-unit-constants", "[length][unit][constants]")
{

    REQUIRE(qm   == quektometer{});
    REQUIRE(rm   == rontometer {});
    REQUIRE(ym   == yoktometer {});
    REQUIRE(zm   == zeptometer {});
    REQUIRE(am   == attometer  {});
    REQUIRE(fm   == femtometer {});
    REQUIRE(pm   == picometer  {});
    REQUIRE(micm == micrometer {});
    REQUIRE(mm   == millimeter {});
    REQUIRE(cm   == centimeter {});
    REQUIRE(m    == meter      {});
    REQUIRE(dam  == decameter  {});
    REQUIRE(hm   == hectometer {});
    REQUIRE(km   == kilometer  {});
    REQUIRE(Mm   == megameter  {});
    REQUIRE(Gm   == gigameter  {});
    REQUIRE(Tm   == terameter  {});
    REQUIRE(Pm   == petameter  {});
    REQUIRE(Em   == exameter   {});
    REQUIRE(Zm   == zettameter {});
    REQUIRE(Ym   == yottameter {});
    REQUIRE(Rm   == ronnameter {});
    REQUIRE(Qm   == quettameter{});

}
