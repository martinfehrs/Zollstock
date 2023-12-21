#include <zollstock/length_units.hpp>


namespace zollstock
{

    static_assert(micrometer::exponents == unit_exponents{ 1         , 0      , 0     });
    static_assert(micrometer::factors   == unit_factors  { 1e-6L     , 0.0L   , 0.0L  });
    static_assert(micrometer::symbols   == unit_symbols  { "micm"_us , ""_us  , ""_us });

    static_assert(millimeter::exponents == unit_exponents{ 1         , 0      , 0     });
    static_assert(millimeter::factors   == unit_factors  { 1e-3L     , 0.0L   , 0.0L  });
    static_assert(millimeter::symbols   == unit_symbols  { "mm"_us   , ""_us  , ""_us });

    static_assert(centimeter::exponents == unit_exponents{ 1         , 0      , 0     });
    static_assert(centimeter::factors   == unit_factors  { 1e-2L     , 0.0L   , 0.0L  });
    static_assert(centimeter::symbols   == unit_symbols  { "cm"_us   , ""_us  , ""_us });

    static_assert(decimeter ::exponents == unit_exponents{ 1         , 0      , 0     });
    static_assert(decimeter ::factors   == unit_factors  { 1e-1L     , 0.0L   , 0.0L  });
    static_assert(decimeter ::symbols   == unit_symbols  { "dm"_us   , ""_us  , ""_us });

    static_assert(meter     ::exponents == unit_exponents{ 1         , 0      , 0     });
    static_assert(meter     ::factors   == unit_factors  { 1e0L      , 0.0L   , 0.0L  });
    static_assert(meter     ::symbols   == unit_symbols  { "m"_us    , ""_us  , ""_us });

    static_assert(micm == micrometer{});
    static_assert(mm   == millimeter{});
    static_assert(cm   == centimeter{});
    static_assert(m    == meter     {});
    static_assert(dam  == decameter {});
    static_assert(hm   == hectometer{});
    static_assert(km   == kilometer {});

}
