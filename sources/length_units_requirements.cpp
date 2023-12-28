#include <zollstock/length_units.hpp>


namespace zollstock
{

    static_assert(quektometer::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(quektometer::factors   == quantity_factors  { 1e-30L   , 0.0L , 0.0L  });
    static_assert(quektometer::symbols   == quantity_symbols  { "qm"_us  , ""_us, ""_us });

    static_assert(rontometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(rontometer ::factors   == quantity_factors  { 1e-27L   , 0.0L , 0.0L  });
    static_assert(rontometer ::symbols   == quantity_symbols  { "rm"_us  , ""_us, ""_us });

    static_assert(yoktometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(yoktometer ::factors   == quantity_factors  { 1e-24L   , 0.0L , 0.0L  });
    static_assert(yoktometer ::symbols   == quantity_symbols  { "ym"_us  , ""_us, ""_us });

    static_assert(zeptometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(zeptometer ::factors   == quantity_factors  { 1e-21L   , 0.0L , 0.0L  });
    static_assert(zeptometer ::symbols   == quantity_symbols  { "zm"_us  , ""_us, ""_us });

    static_assert(attometer  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(attometer  ::factors   == quantity_factors  { 1e-18L   , 0.0L , 0.0L  });
    static_assert(attometer  ::symbols   == quantity_symbols  { "am"_us  , ""_us, ""_us });

    static_assert(femtometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(femtometer ::factors   == quantity_factors  { 1e-15L   , 0.0L , 0.0L  });
    static_assert(femtometer ::symbols   == quantity_symbols  { "fm"_us  , ""_us, ""_us });

    static_assert(picometer  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(picometer  ::factors   == quantity_factors  { 1e-12L   , 0.0L , 0.0L  });
    static_assert(picometer  ::symbols   == quantity_symbols  { "pm"_us  , ""_us, ""_us });

    static_assert(nanometer  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(nanometer  ::factors   == quantity_factors  { 1e-9L    , 0.0L , 0.0L  });
    static_assert(nanometer  ::symbols   == quantity_symbols  { "nm"_us  , ""_us, ""_us });

    static_assert(micrometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(micrometer ::factors   == quantity_factors  { 1e-6L    , 0.0L , 0.0L  });
    static_assert(micrometer ::symbols   == quantity_symbols  { "micm"_us, ""_us, ""_us });

    static_assert(millimeter ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(millimeter ::factors   == quantity_factors  { 1e-3L    , 0.0L , 0.0L  });
    static_assert(millimeter ::symbols   == quantity_symbols  { "mm"_us  , ""_us, ""_us });

    static_assert(centimeter ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(centimeter ::factors   == quantity_factors  { 1e-2L    , 0.0L , 0.0L  });
    static_assert(centimeter ::symbols   == quantity_symbols  { "cm"_us  , ""_us, ""_us });

    static_assert(decimeter  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(decimeter  ::factors   == quantity_factors  { 1e-1L    , 0.0L , 0.0L  });
    static_assert(decimeter  ::symbols   == quantity_symbols  { "dm"_us  , ""_us, ""_us });

    static_assert(meter      ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(meter      ::factors   == quantity_factors  { 1e0L     , 0.0L , 0.0L  });
    static_assert(meter      ::symbols   == quantity_symbols  { "m"_us   , ""_us, ""_us });

    static_assert(decameter  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(decameter  ::factors   == quantity_factors  { 1e1L     , 0.0L , 0.0L  });
    static_assert(decameter  ::symbols   == quantity_symbols  { "dam"_us , ""_us, ""_us });

    static_assert(hectometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(hectometer ::factors   == quantity_factors  { 1e2L     , 0.0L , 0.0L  });
    static_assert(hectometer ::symbols   == quantity_symbols  { "hm"_us  , ""_us, ""_us });

    static_assert(kilometer  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(kilometer  ::factors   == quantity_factors  { 1e3L     , 0.0L , 0.0L  });
    static_assert(kilometer  ::symbols   == quantity_symbols  { "km"_us  , ""_us, ""_us });

    static_assert(megameter  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(megameter  ::factors   == quantity_factors  { 1e6L     , 0.0L , 0.0L  });
    static_assert(megameter  ::symbols   == quantity_symbols  { "Mm"_us  , ""_us, ""_us });

    static_assert(gigameter  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(gigameter  ::factors   == quantity_factors  { 1e9L     , 0.0L , 0.0L  });
    static_assert(gigameter  ::symbols   == quantity_symbols  { "Gm"_us  , ""_us, ""_us });

    static_assert(terameter  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(terameter  ::factors   == quantity_factors  { 1e12L    , 0.0L , 0.0L  });
    static_assert(terameter  ::symbols   == quantity_symbols  { "Tm"_us  , ""_us, ""_us });

    static_assert(petameter  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(petameter  ::factors   == quantity_factors  { 1e15L    , 0.0L , 0.0L  });
    static_assert(petameter  ::symbols   == quantity_symbols  { "Pm"_us  , ""_us, ""_us });

    static_assert(exameter   ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(exameter   ::factors   == quantity_factors  { 1e18L    , 0.0L , 0.0L  });
    static_assert(exameter   ::symbols   == quantity_symbols  { "Em"_us  , ""_us, ""_us });

    static_assert(zettameter ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(zettameter ::factors   == quantity_factors  { 1e21L    , 0.0L , 0.0L  });
    static_assert(zettameter ::symbols   == quantity_symbols  { "Zm"_us  , ""_us, ""_us });

    static_assert(yottameter ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(yottameter ::factors   == quantity_factors  { 1e24L    , 0.0L , 0.0L  });
    static_assert(yottameter ::symbols   == quantity_symbols  { "Ym"_us  , ""_us, ""_us });

    static_assert(ronnameter ::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(ronnameter ::factors   == quantity_factors  { 1e27L    , 0.0L , 0.0L  });
    static_assert(ronnameter ::symbols   == quantity_symbols  { "Rm"_us  , ""_us, ""_us });

    static_assert(quettameter::exponents == quantity_exponents{ 1        , 0    , 0     });
    static_assert(quettameter::factors   == quantity_factors  { 1e30L    , 0.0L , 0.0L  });
    static_assert(quettameter::symbols   == quantity_symbols  { "Qm"_us  , ""_us, ""_us });


    static_assert(qm   == quektometer{});
    static_assert(rm   == rontometer {});
    static_assert(ym   == yoktometer {});
    static_assert(zm   == zeptometer {});
    static_assert(am   == attometer  {});
    static_assert(fm   == femtometer {});
    static_assert(pm   == picometer  {});
    static_assert(micm == micrometer {});
    static_assert(mm   == millimeter {});
    static_assert(cm   == centimeter {});
    static_assert(m    == meter      {});
    static_assert(dam  == decameter  {});
    static_assert(hm   == hectometer {});
    static_assert(km   == kilometer  {});
    static_assert(Mm   == megameter  {});
    static_assert(Gm   == gigameter  {});
    static_assert(Tm   == terameter  {});
    static_assert(Pm   == petameter  {});
    static_assert(Em   == exameter   {});
    static_assert(Zm   == zettameter {});
    static_assert(Ym   == yottameter {});
    static_assert(Rm   == ronnameter {});
    static_assert(Qm   == quettameter{});


    static_assert(1.0_qm   == 1.0 * qm  );
    static_assert(1_qm     == 1.0 * qm  );

    static_assert(1.0_rm   == 1.0 * rm  );
    static_assert(1_rm     == 1.0 * rm  );

    static_assert(1.0_ym   == 1.0 * ym  );
    static_assert(1_ym     == 1.0 * ym  );

    static_assert(1.0_zm   == 1.0 * zm  );
    static_assert(1_zm     == 1.0 * zm  );

    static_assert(1.0_am   == 1.0 * am  );
    static_assert(1_am     == 1.0 * am  );

    static_assert(1.0_fm   == 1.0 * fm  );
    static_assert(1_fm     == 1.0 * fm  );

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

    static_assert(1.0_Pm   == 1.0 * Pm  );
    static_assert(1_Pm     == 1.0 * Pm  );

    static_assert(1.0_Em   == 1.0 * Em  );
    static_assert(1_Em     == 1.0 * Em  );

    static_assert(1.0_Zm   == 1.0 * Zm  );
    static_assert(1_Zm     == 1.0 * Zm  );

    static_assert(1.0_Ym   == 1.0 * Ym  );
    static_assert(1_Ym     == 1.0 * Ym  );

    static_assert(1.0_Rm   == 1.0 * Rm  );
    static_assert(1_Rm     == 1.0 * Rm  );

    static_assert(1.0_Qm   == 1.0 * Qm  );
    static_assert(1_Qm     == 1.0 * Qm  );

}
