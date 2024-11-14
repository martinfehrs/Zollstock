#include <zollstock/prefixes.hpp>

#include <catch2/catch_all.hpp>


using namespace zollstock;


TEST_CASE("si-prefixes", "[si-prefixes]")
{
    STATIC_REQUIRE(prefixes::q  .factor == 1e-30L);
    STATIC_REQUIRE(prefixes::r  .factor == 1e-27L);
    STATIC_REQUIRE(prefixes::y  .factor == 1e-24L);
    STATIC_REQUIRE(prefixes::z  .factor == 1e-21L);
    STATIC_REQUIRE(prefixes::a  .factor == 1e-18L);
    STATIC_REQUIRE(prefixes::f  .factor == 1e-15L);
    STATIC_REQUIRE(prefixes::p  .factor == 1e-12L);
    STATIC_REQUIRE(prefixes::n  .factor == 1e-09L);
    STATIC_REQUIRE(prefixes::mic.factor == 1e-06L);
    STATIC_REQUIRE(prefixes::m  .factor == 1e-03L);
    STATIC_REQUIRE(prefixes::c  .factor == 1e-02L);
    STATIC_REQUIRE(prefixes::d  .factor == 1e-01L);
    STATIC_REQUIRE(prefixes::da .factor == 1e+01L);
    STATIC_REQUIRE(prefixes::h  .factor == 1e+02L);
    STATIC_REQUIRE(prefixes::k  .factor == 1e+03L);
    STATIC_REQUIRE(prefixes::M  .factor == 1e+06L);
    STATIC_REQUIRE(prefixes::G  .factor == 1e+09L);
    STATIC_REQUIRE(prefixes::T  .factor == 1e+12L);
    STATIC_REQUIRE(prefixes::P  .factor == 1e+15L);
    STATIC_REQUIRE(prefixes::E  .factor == 1e+18L);
    STATIC_REQUIRE(prefixes::Z  .factor == 1e+21L);
    STATIC_REQUIRE(prefixes::Y  .factor == 1e+24L);
    STATIC_REQUIRE(prefixes::R  .factor == 1e+27L);
    STATIC_REQUIRE(prefixes::Q  .factor == 1e+30L);

    STATIC_REQUIRE(prefixes::q  .symbol == "q"  );
    STATIC_REQUIRE(prefixes::r  .symbol == "r"  );
    STATIC_REQUIRE(prefixes::y  .symbol == "y"  );
    STATIC_REQUIRE(prefixes::z  .symbol == "z"  );
    STATIC_REQUIRE(prefixes::a  .symbol == "a"  );
    STATIC_REQUIRE(prefixes::f  .symbol == "f"  );
    STATIC_REQUIRE(prefixes::p  .symbol == "p"  );
    STATIC_REQUIRE(prefixes::n  .symbol == "n"  );
    STATIC_REQUIRE(prefixes::mic.symbol == "mic");
    STATIC_REQUIRE(prefixes::m  .symbol == "m"  );
    STATIC_REQUIRE(prefixes::c  .symbol == "c"  );
    STATIC_REQUIRE(prefixes::d  .symbol == "d"  );
    STATIC_REQUIRE(prefixes::da .symbol == "da" );
    STATIC_REQUIRE(prefixes::h  .symbol == "h"  );
    STATIC_REQUIRE(prefixes::k  .symbol == "k"  );
    STATIC_REQUIRE(prefixes::M  .symbol == "M"  );
    STATIC_REQUIRE(prefixes::G  .symbol == "G"  );
    STATIC_REQUIRE(prefixes::T  .symbol == "T"  );
    STATIC_REQUIRE(prefixes::P  .symbol == "P"  );
    STATIC_REQUIRE(prefixes::E  .symbol == "E"  );
    STATIC_REQUIRE(prefixes::Z  .symbol == "Z"  );
    STATIC_REQUIRE(prefixes::Y  .symbol == "Y"  );
    STATIC_REQUIRE(prefixes::R  .symbol == "R"  );
    STATIC_REQUIRE(prefixes::Q  .symbol == "Q"  );
}
