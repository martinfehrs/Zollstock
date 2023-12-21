#include <zollstock/length_units.hpp>


namespace zollstock
{

    static_assert(centimeter::exponents == unit_exponents{ 1       , 0      , 0     });
    static_assert(centimeter::factors   == unit_factors  { 1e-2L   , 0.0L   , 0.0L  });
    static_assert(centimeter::symbols   == unit_symbols  { "cm"_us , ""_us  , ""_us });

    static_assert(decimeter ::exponents == unit_exponents{ 1       , 0      , 0     });
    static_assert(decimeter ::factors   == unit_factors  { 1e-1L   , 0.0L   , 0.0L  });
    static_assert(decimeter ::symbols   == unit_symbols  { "dm"_us , ""_us  , ""_us });

    static_assert(meter     ::exponents == unit_exponents{ 1       , 0      , 0     });
    static_assert(meter     ::factors   == unit_factors  { 1e0L    , 0.0L   , 0.0L  });
    static_assert(meter     ::symbols   == unit_symbols  { "m"_us  , ""_us  , ""_us });

}
