#include <catch2/catch_all.hpp>
#include <zollstock/si_prefixes.hpp>


using namespace zollstock;


TEST_CASE("si-prefixes", "[si-prefixes]")
{

    STATIC_REQUIRE(si_prefixes::q  .factor == 1e-30L);
    STATIC_REQUIRE(si_prefixes::r  .factor == 1e-27L);
    STATIC_REQUIRE(si_prefixes::y  .factor == 1e-24L);
    STATIC_REQUIRE(si_prefixes::z  .factor == 1e-21L);
    STATIC_REQUIRE(si_prefixes::a  .factor == 1e-18L);
    STATIC_REQUIRE(si_prefixes::f  .factor == 1e-15L);
    STATIC_REQUIRE(si_prefixes::p  .factor == 1e-12L);
    STATIC_REQUIRE(si_prefixes::n  .factor == 1e-09L);
    STATIC_REQUIRE(si_prefixes::mic.factor == 1e-06L);
    STATIC_REQUIRE(si_prefixes::m  .factor == 1e-03L);
    STATIC_REQUIRE(si_prefixes::c  .factor == 1e-02L);
    STATIC_REQUIRE(si_prefixes::d  .factor == 1e-01L);
    STATIC_REQUIRE(si_prefixes::da .factor == 1e+01L);
    STATIC_REQUIRE(si_prefixes::h  .factor == 1e+02L);
    STATIC_REQUIRE(si_prefixes::k  .factor == 1e+03L);
    STATIC_REQUIRE(si_prefixes::M  .factor == 1e+06L);
    STATIC_REQUIRE(si_prefixes::G  .factor == 1e+09L);
    STATIC_REQUIRE(si_prefixes::T  .factor == 1e+12L);
    STATIC_REQUIRE(si_prefixes::P  .factor == 1e+15L);
    STATIC_REQUIRE(si_prefixes::E  .factor == 1e+18L);
    STATIC_REQUIRE(si_prefixes::Z  .factor == 1e+21L);
    STATIC_REQUIRE(si_prefixes::Y  .factor == 1e+24L);
    STATIC_REQUIRE(si_prefixes::R  .factor == 1e+27L);
    STATIC_REQUIRE(si_prefixes::Q  .factor == 1e+30L);

    STATIC_REQUIRE(si_prefixes::q  .symbol == "q"  );
    STATIC_REQUIRE(si_prefixes::r  .symbol == "r"  );
    STATIC_REQUIRE(si_prefixes::y  .symbol == "y"  );
    STATIC_REQUIRE(si_prefixes::z  .symbol == "z"  );
    STATIC_REQUIRE(si_prefixes::a  .symbol == "a"  );
    STATIC_REQUIRE(si_prefixes::f  .symbol == "f"  );
    STATIC_REQUIRE(si_prefixes::p  .symbol == "p"  );
    STATIC_REQUIRE(si_prefixes::n  .symbol == "n"  );
    STATIC_REQUIRE(si_prefixes::mic.symbol == "mic");
    STATIC_REQUIRE(si_prefixes::m  .symbol == "m"  );
    STATIC_REQUIRE(si_prefixes::c  .symbol == "c"  );
    STATIC_REQUIRE(si_prefixes::d  .symbol == "d"  );
    STATIC_REQUIRE(si_prefixes::da .symbol == "da" );
    STATIC_REQUIRE(si_prefixes::h  .symbol == "h"  );
    STATIC_REQUIRE(si_prefixes::k  .symbol == "k"  );
    STATIC_REQUIRE(si_prefixes::M  .symbol == "M"  );
    STATIC_REQUIRE(si_prefixes::G  .symbol == "G"  );
    STATIC_REQUIRE(si_prefixes::T  .symbol == "T"  );
    STATIC_REQUIRE(si_prefixes::P  .symbol == "P"  );
    STATIC_REQUIRE(si_prefixes::E  .symbol == "E"  );
    STATIC_REQUIRE(si_prefixes::Z  .symbol == "Z"  );
    STATIC_REQUIRE(si_prefixes::Y  .symbol == "Y"  );
    STATIC_REQUIRE(si_prefixes::R  .symbol == "R"  );
    STATIC_REQUIRE(si_prefixes::Q  .symbol == "Q"  );

}
