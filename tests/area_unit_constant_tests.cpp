#include <catch2/catch_all.hpp>
#include <zollstock/area_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>


using namespace zollstock;


TEST_CASE("area-unit-constants", "[area][unit][constants]")
{

    REQUIRE(qm2   == square_quektometer{});
    REQUIRE(rm2   == square_rontometer {});
    REQUIRE(ym2   == square_yoktometer {});
    REQUIRE(zm2   == square_zeptometer {});
    REQUIRE(am2   == square_attometer  {});
    REQUIRE(fm2   == square_femtometer {});
    REQUIRE(pm2   == square_picometer  {});
    REQUIRE(micm2 == square_micrometer {});
    REQUIRE(mm2   == square_millimeter {});
    REQUIRE(cm2   == square_centimeter {});
    REQUIRE(m2    == square_meter      {});
    REQUIRE(dam2  == square_decameter  {});
    REQUIRE(hm2   == square_hectometer {});
    REQUIRE(km2   == square_kilometer  {});
    REQUIRE(Mm2   == square_megameter  {});
    REQUIRE(Gm2   == square_gigameter  {});
    REQUIRE(Tm2   == square_terameter  {});
    REQUIRE(Pm2   == square_petameter  {});
    REQUIRE(Em2   == square_exameter   {});
    REQUIRE(Zm2   == square_zettameter {});
    REQUIRE(Ym2   == square_yottameter {});
    REQUIRE(Rm2   == square_ronnameter {});
    REQUIRE(Qm2   == square_quettameter{});

}
