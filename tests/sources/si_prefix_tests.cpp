#include <catch2/catch_all.hpp>
#include <zollstock/si_prefixes.hpp>


using namespace zollstock;


TEST_CASE("si-prefixes", "[si-prefixes]")
{

    REQUIRE(si_prefixes::q  .factor == 1e-30L);
    REQUIRE(si_prefixes::r  .factor == 1e-27L);
    REQUIRE(si_prefixes::y  .factor == 1e-24L);
    REQUIRE(si_prefixes::z  .factor == 1e-21L);
    REQUIRE(si_prefixes::a  .factor == 1e-18L);
    REQUIRE(si_prefixes::f  .factor == 1e-15L);
    REQUIRE(si_prefixes::p  .factor == 1e-12L);
    REQUIRE(si_prefixes::n  .factor == 1e-09L);
    REQUIRE(si_prefixes::mic.factor == 1e-06L);
    REQUIRE(si_prefixes::m  .factor == 1e-03L);
    REQUIRE(si_prefixes::c  .factor == 1e-02L);
    REQUIRE(si_prefixes::d  .factor == 1e-01L);
    REQUIRE(si_prefixes::da .factor == 1e+01L);
    REQUIRE(si_prefixes::h  .factor == 1e+02L);
    REQUIRE(si_prefixes::k  .factor == 1e+03L);
    REQUIRE(si_prefixes::M  .factor == 1e+06L);
    REQUIRE(si_prefixes::G  .factor == 1e+09L);
    REQUIRE(si_prefixes::T  .factor == 1e+12L);
    REQUIRE(si_prefixes::P  .factor == 1e+15L);
    REQUIRE(si_prefixes::E  .factor == 1e+18L);
    REQUIRE(si_prefixes::Z  .factor == 1e+21L);
    REQUIRE(si_prefixes::Y  .factor == 1e+24L);
    REQUIRE(si_prefixes::R  .factor == 1e+27L);
    REQUIRE(si_prefixes::Q  .factor == 1e+30L);

    REQUIRE(si_prefixes::q  .symbol == "q"_us  );
    REQUIRE(si_prefixes::r  .symbol == "r"_us  );
    REQUIRE(si_prefixes::y  .symbol == "y"_us  );
    REQUIRE(si_prefixes::z  .symbol == "z"_us  );
    REQUIRE(si_prefixes::a  .symbol == "a"_us  );
    REQUIRE(si_prefixes::f  .symbol == "f"_us  );
    REQUIRE(si_prefixes::p  .symbol == "p"_us  );
    REQUIRE(si_prefixes::n  .symbol == "n"_us  );
    REQUIRE(si_prefixes::mic.symbol == "mic"_us);
    REQUIRE(si_prefixes::m  .symbol == "m"_us  );
    REQUIRE(si_prefixes::c  .symbol == "c"_us  );
    REQUIRE(si_prefixes::d  .symbol == "d"_us  );
    REQUIRE(si_prefixes::da .symbol == "da"_us );
    REQUIRE(si_prefixes::h  .symbol == "h"_us  );
    REQUIRE(si_prefixes::k  .symbol == "k"_us  );
    REQUIRE(si_prefixes::M  .symbol == "M"_us  );
    REQUIRE(si_prefixes::G  .symbol == "G"_us  );
    REQUIRE(si_prefixes::T  .symbol == "T"_us  );
    REQUIRE(si_prefixes::P  .symbol == "P"_us  );
    REQUIRE(si_prefixes::E  .symbol == "E"_us  );
    REQUIRE(si_prefixes::Z  .symbol == "Z"_us  );
    REQUIRE(si_prefixes::Y  .symbol == "Y"_us  );
    REQUIRE(si_prefixes::R  .symbol == "R"_us  );
    REQUIRE(si_prefixes::Q  .symbol == "Q"_us  );

}
