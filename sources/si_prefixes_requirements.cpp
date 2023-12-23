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

}
