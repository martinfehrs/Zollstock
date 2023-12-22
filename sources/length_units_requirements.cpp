#include <zollstock/length_units.hpp>


namespace zollstock
{

    static_assert(picometer::exponents == unit_exponents { 1         , 0      , 0     });
    static_assert(picometer::factors   == unit_factors   { 1e-12L    , 0.0L   , 0.0L  });
    static_assert(picometer::symbols   == unit_symbols   { "pm"_us   , ""_us  , ""_us });

    static_assert(nanometer::exponents == unit_exponents { 1         , 0      , 0     });
    static_assert(nanometer::factors   == unit_factors   { 1e-9L     , 0.0L   , 0.0L  });
    static_assert(nanometer::symbols   == unit_symbols   { "nm"_us   , ""_us  , ""_us });

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

    static_assert(decameter::exponents == unit_exponents { 1         , 0      , 0     });
    static_assert(decameter::factors   == unit_factors   { 1e1L      , 0.0L   , 0.0L  });
    static_assert(decameter::symbols   == unit_symbols   { "dam"_us  , ""_us  , ""_us });

    static_assert(hectometer::exponents == unit_exponents { 1        , 0      , 0     });
    static_assert(hectometer::factors   == unit_factors   { 1e2L     , 0.0L   , 0.0L  });
    static_assert(hectometer::symbols   == unit_symbols   { "hm"_us  , ""_us  , ""_us });

    static_assert(kilometer::exponents == unit_exponents { 1         , 0      , 0     });
    static_assert(kilometer::factors   == unit_factors   { 1e3L      , 0.0L   , 0.0L  });
    static_assert(kilometer::symbols   == unit_symbols   { "km"_us   , ""_us  , ""_us });

    static_assert(megameter::exponents == unit_exponents { 1         , 0      , 0     });
    static_assert(megameter::factors   == unit_factors   { 1e6L      , 0.0L   , 0.0L  });
    static_assert(megameter::symbols   == unit_symbols   { "Mm"_us   , ""_us  , ""_us });

    static_assert(gigameter::exponents == unit_exponents { 1         , 0      , 0     });
    static_assert(gigameter::factors   == unit_factors   { 1e9L      , 0.0L   , 0.0L  });
    static_assert(gigameter::symbols   == unit_symbols   { "Gm"_us   , ""_us  , ""_us });

    static_assert(terameter::exponents == unit_exponents { 1         , 0      , 0     });
    static_assert(terameter::factors   == unit_factors   { 1e12L     , 0.0L   , 0.0L  });
    static_assert(terameter::symbols   == unit_symbols   { "Tm"_us   , ""_us  , ""_us });

    static_assert(pm   == picometer {});
    static_assert(micm == micrometer{});
    static_assert(mm   == millimeter{});
    static_assert(cm   == centimeter{});
    static_assert(m    == meter     {});
    static_assert(dam  == decameter {});
    static_assert(hm   == hectometer{});
    static_assert(km   == kilometer {});
    static_assert(Mm   == megameter {});
    static_assert(Gm   == gigameter {});
    static_assert(Tm   == terameter {});

    static_assert(1.0_pm   == 1.0 * pm  );
    static_assert(1_pm     == 1.0 * pm  );
    static_assert(1.0_nm   == 1.0 * nm  );
    static_assert(1_nm     == 1.0 * nm  );
    static_assert(1.0_micm == 1.0 * micm);
    static_assert(1_micm   == 1.0 * micm);
    static_assert(1.0_mm   == 1.0 * mm  );
    static_assert(1_mm     == 1.0 * mm  );
    static_assert(1.0_cm   == 1.0 * cm  );
    static_assert(1_cm     == 1.0 * cm  );
    static_assert(1.0_dm   == 1.0 * dm  );
    static_assert(1_dm     == 1.0 * dm  );
    static_assert(1.0_m    == 1.0 * m   );
    static_assert(1_m      == 1.0 * m   );
    static_assert(1.0_dam  == 1.0 * dam );
    static_assert(1_dam    == 1.0 * dam );
    static_assert(1.0_hm   == 1.0 * hm  );
    static_assert(1_hm     == 1.0 * hm  );
    static_assert(1.0_km   == 1.0 * km  );
    static_assert(1_km     == 1.0 * km  );
    static_assert(1.0_Mm   == 1.0 * Mm  );
    static_assert(1_Mm     == 1.0 * Mm  );
    static_assert(1.0_Gm   == 1.0 * Gm  );
    static_assert(1_Gm     == 1.0 * Gm  );
    static_assert(1.0_Tm   == 1.0 * Tm  );
    static_assert(1_Tm     == 1.0 * Tm  );

}
