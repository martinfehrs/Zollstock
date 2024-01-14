#include <catch2/catch_all.hpp>
#include <zollstock/si_prefixes.hpp>


using namespace zollstock;


TEST_CASE("si-prefixes", "[si-prefixes]")
{

    REQUIRE(quekto    ::factor == 1e-30L);
    REQUIRE(ronto     ::factor == 1e-27L);
    REQUIRE(yokto     ::factor == 1e-24L);
    REQUIRE(zepto     ::factor == 1e-21L);
    REQUIRE(atto      ::factor == 1e-18L);
    REQUIRE(femto     ::factor == 1e-15L);
    REQUIRE(pico      ::factor == 1e-12L);
    REQUIRE(nano      ::factor == 1e-09L);
    REQUIRE(micro     ::factor == 1e-06L);
    REQUIRE(milli     ::factor == 1e-03L);
    REQUIRE(centi     ::factor == 1e-02L);
    REQUIRE(deci      ::factor == 1e-01L);
    REQUIRE(unprefixed::factor == 1e+00L);
    REQUIRE(deca      ::factor == 1e+01L);
    REQUIRE(hecto     ::factor == 1e+02L);
    REQUIRE(kilo      ::factor == 1e+03L);
    REQUIRE(mega      ::factor == 1e+06L);
    REQUIRE(giga      ::factor == 1e+09L);
    REQUIRE(tera      ::factor == 1e+12L);
    REQUIRE(peta      ::factor == 1e+15L);
    REQUIRE(exa       ::factor == 1e+18L);
    REQUIRE(zetta     ::factor == 1e+21L);
    REQUIRE(yotta     ::factor == 1e+24L);
    REQUIRE(ronna     ::factor == 1e+27L);
    REQUIRE(quetta    ::factor == 1e+30L);

    REQUIRE(quekto    ::symbol == "q"_us  );
    REQUIRE(ronto     ::symbol == "r"_us  );
    REQUIRE(yokto     ::symbol == "y"_us  );
    REQUIRE(zepto     ::symbol == "z"_us  );
    REQUIRE(atto      ::symbol == "a"_us  );
    REQUIRE(femto     ::symbol == "f"_us  );
    REQUIRE(pico      ::symbol == "p"_us  );
    REQUIRE(nano      ::symbol == "n"_us  );
    REQUIRE(micro     ::symbol == "mic"_us);
    REQUIRE(milli     ::symbol == "m"_us  );
    REQUIRE(centi     ::symbol == "c"_us  );
    REQUIRE(deci      ::symbol == "d"_us  );
    REQUIRE(unprefixed::symbol == ""_us   );
    REQUIRE(deca      ::symbol == "da"_us );
    REQUIRE(hecto     ::symbol == "h"_us  );
    REQUIRE(kilo      ::symbol == "k"_us  );
    REQUIRE(mega      ::symbol == "M"_us  );
    REQUIRE(giga      ::symbol == "G"_us  );
    REQUIRE(tera      ::symbol == "T"_us  );
    REQUIRE(peta      ::symbol == "P"_us  );
    REQUIRE(exa       ::symbol == "E"_us  );
    REQUIRE(zetta     ::symbol == "Z"_us  );
    REQUIRE(yotta     ::symbol == "Y"_us  );
    REQUIRE(ronna     ::symbol == "R"_us  );
    REQUIRE(quetta    ::symbol == "Q"_us  );

}
