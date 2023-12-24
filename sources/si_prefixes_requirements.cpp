#include <zollstock/si_prefixes.hpp>


namespace zollstock
{

    static_assert(quekto    ::factor == 1e-30L);
    static_assert(ronto     ::factor == 1e-27L);
    static_assert(yokto     ::factor == 1e-24L);
    static_assert(zepto     ::factor == 1e-21L);
    static_assert(atto      ::factor == 1e-18L);
    static_assert(femto     ::factor == 1e-15L);
    static_assert(pico      ::factor == 1e-12L);
    static_assert(nano      ::factor == 1e-09L);
    static_assert(micro     ::factor == 1e-06L);
    static_assert(milli     ::factor == 1e-03L);
    static_assert(centi     ::factor == 1e-02L);
    static_assert(deci      ::factor == 1e-01L);
    static_assert(unprefixed::factor == 1e+00L);
    static_assert(deca      ::factor == 1e+01L);
    static_assert(hecto     ::factor == 1e+02L);
    static_assert(kilo      ::factor == 1e+03L);
    static_assert(mega      ::factor == 1e+06L);
    static_assert(giga      ::factor == 1e+09L);
    static_assert(tera      ::factor == 1e+12L);
    static_assert(peta      ::factor == 1e+15L);
    static_assert(exa       ::factor == 1e+18L);
    static_assert(zetta     ::factor == 1e+21L);
    static_assert(yotta     ::factor == 1e+24L);
    static_assert(ronna     ::factor == 1e+27L);
    static_assert(quetta    ::factor == 1e+30L);

    static_assert(quekto    ::symbol == "q"_us  );
    static_assert(ronto     ::symbol == "r"_us  );
    static_assert(yokto     ::symbol == "y"_us  );
    static_assert(zepto     ::symbol == "z"_us  );
    static_assert(atto      ::symbol == "a"_us  );
    static_assert(femto     ::symbol == "f"_us  );
    static_assert(pico      ::symbol == "p"_us  );
    static_assert(nano      ::symbol == "n"_us  );
    static_assert(micro     ::symbol == "mic"_us);
    static_assert(milli     ::symbol == "m"_us  );
    static_assert(centi     ::symbol == "c"_us  );
    static_assert(deci      ::symbol == "d"_us  );
    static_assert(unprefixed::symbol == ""_us   );
    static_assert(deca      ::symbol == "da"_us );
    static_assert(hecto     ::symbol == "h"_us  );
    static_assert(kilo      ::symbol == "k"_us  );
    static_assert(mega      ::symbol == "M"_us  );
    static_assert(giga      ::symbol == "G"_us  );
    static_assert(tera      ::symbol == "T"_us  );
    static_assert(peta      ::symbol == "P"_us  );
    static_assert(exa       ::symbol == "E"_us  );
    static_assert(zetta     ::symbol == "Z"_us  );
    static_assert(yotta     ::symbol == "Y"_us  );
    static_assert(ronna     ::symbol == "R"_us  );
    static_assert(quetta    ::symbol == "Q"_us  );

}
