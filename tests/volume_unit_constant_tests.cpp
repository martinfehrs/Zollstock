#include <catch2/catch_all.hpp>
#include <zollstock/volume_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>


using namespace zollstock;


TEST_CASE("volume-unit-constants", "[volume][unit][constants]")
{

    REQUIRE(qm3   == cubic_quektometer{});
    REQUIRE(rm3   == cubic_rontometer {});
    REQUIRE(ym3   == cubic_yoktometer {});
    REQUIRE(zm3   == cubic_zeptometer {});
    REQUIRE(am3   == cubic_attometer  {});
    REQUIRE(fm3   == cubic_femtometer {});
    REQUIRE(pm3   == cubic_picometer  {});
    REQUIRE(micm3 == cubic_micrometer {});
    REQUIRE(mm3   == cubic_millimeter {});
    REQUIRE(cm3   == cubic_centimeter {});
    REQUIRE(m3    == cubic_meter      {});
    REQUIRE(dam3  == cubic_decameter  {});
    REQUIRE(hm3   == cubic_hectometer {});
    REQUIRE(km3   == cubic_kilometer  {});
    REQUIRE(Mm3   == cubic_megameter  {});
    REQUIRE(Gm3   == cubic_gigameter  {});
    REQUIRE(Tm3   == cubic_terameter  {});
    REQUIRE(Pm3   == cubic_petameter  {});
    REQUIRE(Em3   == cubic_exameter   {});
    REQUIRE(Zm3   == cubic_zettameter {});
    REQUIRE(Ym3   == cubic_yottameter {});
    REQUIRE(Rm3   == cubic_ronnameter {});
    REQUIRE(Qm3   == cubic_quettameter{});

}
