#include <zollstock/volume_units.hpp>


namespace zollstock
{

    static_assert(cubic_quektometer::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_quektometer::factors   == quantity_factors  { 1e-30L   , 0.0L , 0.0L  });
    static_assert(cubic_quektometer::symbols   == quantity_symbols  { "qm"_us  , ""_us, ""_us });

    static_assert(cubic_rontometer ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_rontometer ::factors   == quantity_factors  { 1e-27L   , 0.0L , 0.0L  });
    static_assert(cubic_rontometer ::symbols   == quantity_symbols  { "rm"_us  , ""_us, ""_us });

    static_assert(cubic_yoktometer ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_yoktometer ::factors   == quantity_factors  { 1e-24L   , 0.0L , 0.0L  });
    static_assert(cubic_yoktometer ::symbols   == quantity_symbols  { "ym"_us  , ""_us, ""_us });

    static_assert(cubic_zeptometer ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_zeptometer ::factors   == quantity_factors  { 1e-21L   , 0.0L , 0.0L  });
    static_assert(cubic_zeptometer ::symbols   == quantity_symbols  { "zm"_us  , ""_us, ""_us });

    static_assert(cubic_attometer  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_attometer  ::factors   == quantity_factors  { 1e-18L   , 0.0L , 0.0L  });
    static_assert(cubic_attometer  ::symbols   == quantity_symbols  { "am"_us  , ""_us, ""_us });

    static_assert(cubic_femtometer ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_femtometer ::factors   == quantity_factors  { 1e-15L   , 0.0L , 0.0L  });
    static_assert(cubic_femtometer ::symbols   == quantity_symbols  { "fm"_us  , ""_us, ""_us });

    static_assert(cubic_picometer  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_picometer  ::factors   == quantity_factors  { 1e-12L   , 0.0L , 0.0L  });
    static_assert(cubic_picometer  ::symbols   == quantity_symbols  { "pm"_us  , ""_us, ""_us });

    static_assert(cubic_nanometer  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_nanometer  ::factors   == quantity_factors  { 1e-9L    , 0.0L , 0.0L  });
    static_assert(cubic_nanometer  ::symbols   == quantity_symbols  { "nm"_us  , ""_us, ""_us });

    static_assert(cubic_micrometer ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_micrometer ::factors   == quantity_factors  { 1e-6L    , 0.0L , 0.0L  });
    static_assert(cubic_micrometer ::symbols   == quantity_symbols  { "micm"_us, ""_us, ""_us });

    static_assert(cubic_millimeter ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_millimeter ::factors   == quantity_factors  { 1e-3L    , 0.0L , 0.0L  });
    static_assert(cubic_millimeter ::symbols   == quantity_symbols  { "mm"_us  , ""_us, ""_us });

    static_assert(cubic_centimeter ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_centimeter ::factors   == quantity_factors  { 1e-2L    , 0.0L , 0.0L  });
    static_assert(cubic_centimeter ::symbols   == quantity_symbols  { "cm"_us  , ""_us, ""_us });

    static_assert(cubic_decimeter  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_decimeter  ::factors   == quantity_factors  { 1e-1L    , 0.0L , 0.0L  });
    static_assert(cubic_decimeter  ::symbols   == quantity_symbols  { "dm"_us  , ""_us, ""_us });

    static_assert(cubic_meter      ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_meter      ::factors   == quantity_factors  { 1e0L     , 0.0L , 0.0L  });
    static_assert(cubic_meter      ::symbols   == quantity_symbols  { "m"_us   , ""_us, ""_us });

    static_assert(cubic_decameter  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_decameter  ::factors   == quantity_factors  { 1e1L     , 0.0L , 0.0L  });
    static_assert(cubic_decameter  ::symbols   == quantity_symbols  { "dam"_us , ""_us, ""_us });

    static_assert(cubic_hectometer ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_hectometer ::factors   == quantity_factors  { 1e2L     , 0.0L , 0.0L  });
    static_assert(cubic_hectometer ::symbols   == quantity_symbols  { "hm"_us  , ""_us, ""_us });

    static_assert(cubic_kilometer  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_kilometer  ::factors   == quantity_factors  { 1e3L     , 0.0L , 0.0L  });
    static_assert(cubic_kilometer  ::symbols   == quantity_symbols  { "km"_us  , ""_us, ""_us });

    static_assert(cubic_megameter  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_megameter  ::factors   == quantity_factors  { 1e6L     , 0.0L , 0.0L  });
    static_assert(cubic_megameter  ::symbols   == quantity_symbols  { "Mm"_us  , ""_us, ""_us });

    static_assert(cubic_gigameter  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_gigameter  ::factors   == quantity_factors  { 1e9L     , 0.0L , 0.0L  });
    static_assert(cubic_gigameter  ::symbols   == quantity_symbols  { "Gm"_us  , ""_us, ""_us });

    static_assert(cubic_terameter  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_terameter  ::factors   == quantity_factors  { 1e12L    , 0.0L , 0.0L  });
    static_assert(cubic_terameter  ::symbols   == quantity_symbols  { "Tm"_us  , ""_us, ""_us });

    static_assert(cubic_petameter  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_petameter  ::factors   == quantity_factors  { 1e15L    , 0.0L , 0.0L  });
    static_assert(cubic_petameter  ::symbols   == quantity_symbols  { "Pm"_us  , ""_us, ""_us });

    static_assert(cubic_exameter   ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_exameter   ::factors   == quantity_factors  { 1e18L    , 0.0L , 0.0L  });
    static_assert(cubic_exameter   ::symbols   == quantity_symbols  { "Em"_us  , ""_us, ""_us });

    static_assert(cubic_zettameter ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_zettameter ::factors   == quantity_factors  { 1e21L    , 0.0L , 0.0L  });
    static_assert(cubic_zettameter ::symbols   == quantity_symbols  { "Zm"_us  , ""_us, ""_us });

    static_assert(cubic_yottameter ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_yottameter ::factors   == quantity_factors  { 1e24L    , 0.0L , 0.0L  });
    static_assert(cubic_yottameter ::symbols   == quantity_symbols  { "Ym"_us  , ""_us, ""_us });

    static_assert(cubic_ronnameter ::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_ronnameter ::factors   == quantity_factors  { 1e27L    , 0.0L , 0.0L  });
    static_assert(cubic_ronnameter ::symbols   == quantity_symbols  { "Rm"_us  , ""_us, ""_us });

    static_assert(cubic_quettameter::exponents == quantity_exponents{ 3        , 0    , 0     });
    static_assert(cubic_quettameter::factors   == quantity_factors  { 1e30L    , 0.0L , 0.0L  });
    static_assert(cubic_quettameter::symbols   == quantity_symbols  { "Qm"_us  , ""_us, ""_us });


    static_assert(qm3   == cubic_quektometer{});
    static_assert(rm3   == cubic_rontometer {});
    static_assert(ym3   == cubic_yoktometer {});
    static_assert(zm3   == cubic_zeptometer {});
    static_assert(am3   == cubic_attometer  {});
    static_assert(fm3   == cubic_femtometer {});
    static_assert(pm3   == cubic_picometer  {});
    static_assert(micm3 == cubic_micrometer {});
    static_assert(mm3   == cubic_millimeter {});
    static_assert(cm3   == cubic_centimeter {});
    static_assert(m3    == cubic_meter      {});
    static_assert(dam3  == cubic_decameter  {});
    static_assert(hm3   == cubic_hectometer {});
    static_assert(km3   == cubic_kilometer  {});
    static_assert(Mm3   == cubic_megameter  {});
    static_assert(Gm3   == cubic_gigameter  {});
    static_assert(Tm3   == cubic_terameter  {});
    static_assert(Pm3   == cubic_petameter  {});
    static_assert(Em3   == cubic_exameter   {});
    static_assert(Zm3   == cubic_zettameter {});
    static_assert(Ym3   == cubic_yottameter {});
    static_assert(Rm3   == cubic_ronnameter {});
    static_assert(Qm3   == cubic_quettameter{});


    static_assert(1.0_qm3   == 1.0 * qm3  );
    static_assert(1_qm3     == 1.0 * qm3  );

    static_assert(1.0_rm3   == 1.0 * rm3  );
    static_assert(1_rm3     == 1.0 * rm3  );

    static_assert(1.0_ym3   == 1.0 * ym3  );
    static_assert(1_ym3     == 1.0 * ym3  );

    static_assert(1.0_zm3   == 1.0 * zm3  );
    static_assert(1_zm3     == 1.0 * zm3  );

    static_assert(1.0_am3   == 1.0 * am3  );
    static_assert(1_am3     == 1.0 * am3  );

    static_assert(1.0_fm3   == 1.0 * fm3  );
    static_assert(1_fm3     == 1.0 * fm3  );

    static_assert(1.0_pm3   == 1.0 * pm3  );
    static_assert(1_pm3     == 1.0 * pm3  );

    static_assert(1.0_nm3   == 1.0 * nm3  );
    static_assert(1_nm3     == 1.0 * nm3  );

    static_assert(1.0_micm3 == 1.0 * micm3);
    static_assert(1_micm3   == 1.0 * micm3);

    static_assert(1.0_mm3   == 1.0 * mm3  );
    static_assert(1_mm3     == 1.0 * mm3  );

    static_assert(1.0_cm3   == 1.0 * cm3  );
    static_assert(1_cm3     == 1.0 * cm3  );

    static_assert(1.0_dm3   == 1.0 * dm3  );
    static_assert(1_dm3     == 1.0 * dm3  );

    static_assert(1.0_m3    == 1.0 * m3   );
    static_assert(1_m3      == 1.0 * m3   );

    static_assert(1.0_dam3  == 1.0 * dam3 );
    static_assert(1_dam3    == 1.0 * dam3 );

    static_assert(1.0_hm3   == 1.0 * hm3  );
    static_assert(1_hm3     == 1.0 * hm3  );

    static_assert(1.0_km3   == 1.0 * km3  );
    static_assert(1_km3     == 1.0 * km3  );

    static_assert(1.0_Mm3   == 1.0 * Mm3  );
    static_assert(1_Mm3     == 1.0 * Mm3  );

    static_assert(1.0_Gm3   == 1.0 * Gm3  );
    static_assert(1_Gm3     == 1.0 * Gm3  );

    static_assert(1.0_Tm3   == 1.0 * Tm3  );
    static_assert(1_Tm3     == 1.0 * Tm3  );

    static_assert(1.0_Pm3   == 1.0 * Pm3  );
    static_assert(1_Pm3     == 1.0 * Pm3  );

    static_assert(1.0_Em3   == 1.0 * Em3  );
    static_assert(1_Em3     == 1.0 * Em3  );

    static_assert(1.0_Zm3   == 1.0 * Zm3  );
    static_assert(1_Zm3     == 1.0 * Zm3  );

    static_assert(1.0_Ym3   == 1.0 * Ym3  );
    static_assert(1_Ym3     == 1.0 * Ym3  );

    static_assert(1.0_Rm3   == 1.0 * Rm3  );
    static_assert(1_Rm3     == 1.0 * Rm3  );

    static_assert(1.0_Qm3   == 1.0 * Qm3  );
    static_assert(1_Qm3     == 1.0 * Qm3  );

}
