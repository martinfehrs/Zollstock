#include <catch2/catch_all.hpp>
#include <zollstock/time_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>


using namespace zollstock;


TEST_CASE("time-unit-constants", "[time][unit][constants]")
{

    REQUIRE(qs   == quektosecond{});
    REQUIRE(rs   == rontosecond {});
    REQUIRE(ys   == yoktosecond {});
    REQUIRE(zs   == zeptosecond {});
    REQUIRE(as   == attosecond  {});
    REQUIRE(fs   == femtosecond {});
    REQUIRE(ps   == picosecond  {});
    REQUIRE(mics == microsecond {});
    REQUIRE(ms   == millisecond {});
    REQUIRE(cs   == centisecond {});
    REQUIRE(s    == second      {});
    REQUIRE(das  == decasecond  {});
    REQUIRE(hs   == hectosecond {});
    REQUIRE(ks   == kilosecond  {});
    REQUIRE(Ms   == megasecond  {});
    REQUIRE(Gs   == gigasecond  {});
    REQUIRE(Ts   == terasecond  {});
    REQUIRE(Ps   == petasecond  {});
    REQUIRE(Es   == exasecond   {});
    REQUIRE(Zs   == zettasecond {});
    REQUIRE(Ys   == yottasecond {});
    REQUIRE(Rs   == ronnasecond {});
    REQUIRE(Qs   == quettasecond{});

}
