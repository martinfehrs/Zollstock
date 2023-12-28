#include <zollstock/area_units.hpp>


namespace zollstock
{

    static_assert(square_quektometer::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_quektometer::factors   == unit_factors  { 1e-30L   , 0.0L , 0.0L  });
    static_assert(square_quektometer::symbols   == unit_symbols  { "qm"_us  , ""_us, ""_us });

    static_assert(square_rontometer ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_rontometer ::factors   == unit_factors  { 1e-27L   , 0.0L , 0.0L  });
    static_assert(square_rontometer ::symbols   == unit_symbols  { "rm"_us  , ""_us, ""_us });

    static_assert(square_yoktometer ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_yoktometer ::factors   == unit_factors  { 1e-24L   , 0.0L , 0.0L  });
    static_assert(square_yoktometer ::symbols   == unit_symbols  { "ym"_us  , ""_us, ""_us });

    static_assert(square_zeptometer ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_zeptometer ::factors   == unit_factors  { 1e-21L   , 0.0L , 0.0L  });
    static_assert(square_zeptometer ::symbols   == unit_symbols  { "zm"_us  , ""_us, ""_us });

    static_assert(square_attometer  ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_attometer  ::factors   == unit_factors  { 1e-18L   , 0.0L , 0.0L  });
    static_assert(square_attometer  ::symbols   == unit_symbols  { "am"_us  , ""_us, ""_us });

    static_assert(square_femtometer ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_femtometer ::factors   == unit_factors  { 1e-15L   , 0.0L , 0.0L  });
    static_assert(square_femtometer ::symbols   == unit_symbols  { "fm"_us  , ""_us, ""_us });

    static_assert(square_picometer  ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_picometer  ::factors   == unit_factors  { 1e-12L   , 0.0L , 0.0L  });
    static_assert(square_picometer  ::symbols   == unit_symbols  { "pm"_us  , ""_us, ""_us });

    static_assert(square_nanometer  ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_nanometer  ::factors   == unit_factors  { 1e-9L    , 0.0L , 0.0L  });
    static_assert(square_nanometer  ::symbols   == unit_symbols  { "nm"_us  , ""_us, ""_us });

    static_assert(square_micrometer ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_micrometer ::factors   == unit_factors  { 1e-6L    , 0.0L , 0.0L  });
    static_assert(square_micrometer ::symbols   == unit_symbols  { "micm"_us, ""_us, ""_us });

    static_assert(square_millimeter ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_millimeter ::factors   == unit_factors  { 1e-3L    , 0.0L , 0.0L  });
    static_assert(square_millimeter ::symbols   == unit_symbols  { "mm"_us  , ""_us, ""_us });

    static_assert(square_centimeter ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_centimeter ::factors   == unit_factors  { 1e-2L    , 0.0L , 0.0L  });
    static_assert(square_centimeter ::symbols   == unit_symbols  { "cm"_us  , ""_us, ""_us });

    static_assert(square_decimeter  ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_decimeter  ::factors   == unit_factors  { 1e-1L    , 0.0L , 0.0L  });
    static_assert(square_decimeter  ::symbols   == unit_symbols  { "dm"_us  , ""_us, ""_us });

    static_assert(square_meter      ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_meter      ::factors   == unit_factors  { 1e0L     , 0.0L , 0.0L  });
    static_assert(square_meter      ::symbols   == unit_symbols  { "m"_us   , ""_us, ""_us });

    static_assert(square_decameter  ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_decameter  ::factors   == unit_factors  { 1e1L     , 0.0L , 0.0L  });
    static_assert(square_decameter  ::symbols   == unit_symbols  { "dam"_us , ""_us, ""_us });

    static_assert(square_hectometer ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_hectometer ::factors   == unit_factors  { 1e2L     , 0.0L , 0.0L  });
    static_assert(square_hectometer ::symbols   == unit_symbols  { "hm"_us  , ""_us, ""_us });

    static_assert(square_kilometer  ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_kilometer  ::factors   == unit_factors  { 1e3L     , 0.0L , 0.0L  });
    static_assert(square_kilometer  ::symbols   == unit_symbols  { "km"_us  , ""_us, ""_us });

    static_assert(square_megameter  ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_megameter  ::factors   == unit_factors  { 1e6L     , 0.0L , 0.0L  });
    static_assert(square_megameter  ::symbols   == unit_symbols  { "Mm"_us  , ""_us, ""_us });

    static_assert(square_gigameter  ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_gigameter  ::factors   == unit_factors  { 1e9L     , 0.0L , 0.0L  });
    static_assert(square_gigameter  ::symbols   == unit_symbols  { "Gm"_us  , ""_us, ""_us });

    static_assert(square_terameter  ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_terameter  ::factors   == unit_factors  { 1e12L    , 0.0L , 0.0L  });
    static_assert(square_terameter  ::symbols   == unit_symbols  { "Tm"_us  , ""_us, ""_us });

    static_assert(square_petameter  ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_petameter  ::factors   == unit_factors  { 1e15L    , 0.0L , 0.0L  });
    static_assert(square_petameter  ::symbols   == unit_symbols  { "Pm"_us  , ""_us, ""_us });

    static_assert(square_exameter   ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_exameter   ::factors   == unit_factors  { 1e18L    , 0.0L , 0.0L  });
    static_assert(square_exameter   ::symbols   == unit_symbols  { "Em"_us  , ""_us, ""_us });

    static_assert(square_zettameter ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_zettameter ::factors   == unit_factors  { 1e21L    , 0.0L , 0.0L  });
    static_assert(square_zettameter ::symbols   == unit_symbols  { "Zm"_us  , ""_us, ""_us });

    static_assert(square_yottameter ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_yottameter ::factors   == unit_factors  { 1e24L    , 0.0L , 0.0L  });
    static_assert(square_yottameter ::symbols   == unit_symbols  { "Ym"_us  , ""_us, ""_us });

    static_assert(square_ronnameter ::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_ronnameter ::factors   == unit_factors  { 1e27L    , 0.0L , 0.0L  });
    static_assert(square_ronnameter ::symbols   == unit_symbols  { "Rm"_us  , ""_us, ""_us });

    static_assert(square_quettameter::exponents == unit_exponents{ 2        , 0    , 0     });
    static_assert(square_quettameter::factors   == unit_factors  { 1e30L    , 0.0L , 0.0L  });
    static_assert(square_quettameter::symbols   == unit_symbols  { "Qm"_us  , ""_us, ""_us });


    static_assert(qm2   == square_quektometer{});
    static_assert(rm2   == square_rontometer {});
    static_assert(ym2   == square_yoktometer {});
    static_assert(zm2   == square_zeptometer {});
    static_assert(am2   == square_attometer  {});
    static_assert(fm2   == square_femtometer {});
    static_assert(pm2   == square_picometer  {});
    static_assert(micm2 == square_micrometer {});
    static_assert(mm2   == square_millimeter {});
    static_assert(cm2   == square_centimeter {});
    static_assert(m2    == square_meter      {});
    static_assert(dam2  == square_decameter  {});
    static_assert(hm2   == square_hectometer {});
    static_assert(km2   == square_kilometer  {});
    static_assert(Mm2   == square_megameter  {});
    static_assert(Gm2   == square_gigameter  {});
    static_assert(Tm2   == square_terameter  {});
    static_assert(Pm2   == square_petameter  {});
    static_assert(Em2   == square_exameter   {});
    static_assert(Zm2   == square_zettameter {});
    static_assert(Ym2   == square_yottameter {});
    static_assert(Rm2   == square_ronnameter {});
    static_assert(Qm2   == square_quettameter{});


    static_assert(1.0_qm2   == 1.0 * qm2  );
    static_assert(1_qm2     == 1.0 * qm2  );

    static_assert(1.0_rm2   == 1.0 * rm2  );
    static_assert(1_rm2     == 1.0 * rm2  );

    static_assert(1.0_ym2   == 1.0 * ym2  );
    static_assert(1_ym2     == 1.0 * ym2  );

    static_assert(1.0_zm2   == 1.0 * zm2  );
    static_assert(1_zm2     == 1.0 * zm2  );

    static_assert(1.0_am2   == 1.0 * am2  );
    static_assert(1_am2     == 1.0 * am2  );

    static_assert(1.0_fm2   == 1.0 * fm2  );
    static_assert(1_fm2     == 1.0 * fm2  );

    static_assert(1.0_pm2   == 1.0 * pm2  );
    static_assert(1_pm2     == 1.0 * pm2  );

    static_assert(1.0_nm2   == 1.0 * nm2  );
    static_assert(1_nm2     == 1.0 * nm2  );

    static_assert(1.0_micm2 == 1.0 * micm2);
    static_assert(1_micm2   == 1.0 * micm2);

    static_assert(1.0_mm2   == 1.0 * mm2  );
    static_assert(1_mm2     == 1.0 * mm2  );

    static_assert(1.0_cm2   == 1.0 * cm2  );
    static_assert(1_cm2     == 1.0 * cm2  );

    static_assert(1.0_dm2   == 1.0 * dm2  );
    static_assert(1_dm2     == 1.0 * dm2  );

    static_assert(1.0_m2    == 1.0 * m2   );
    static_assert(1_m2      == 1.0 * m2   );

    static_assert(1.0_dam2  == 1.0 * dam2 );
    static_assert(1_dam2    == 1.0 * dam2 );

    static_assert(1.0_hm2   == 1.0 * hm2  );
    static_assert(1_hm2     == 1.0 * hm2  );

    static_assert(1.0_km2   == 1.0 * km2  );
    static_assert(1_km2     == 1.0 * km2  );

    static_assert(1.0_Mm2   == 1.0 * Mm2  );
    static_assert(1_Mm2     == 1.0 * Mm2  );

    static_assert(1.0_Gm2   == 1.0 * Gm2  );
    static_assert(1_Gm2     == 1.0 * Gm2  );

    static_assert(1.0_Tm2   == 1.0 * Tm2  );
    static_assert(1_Tm2     == 1.0 * Tm2  );

    static_assert(1.0_Pm2   == 1.0 * Pm2  );
    static_assert(1_Pm2     == 1.0 * Pm2  );

    static_assert(1.0_Em2   == 1.0 * Em2  );
    static_assert(1_Em2     == 1.0 * Em2  );

    static_assert(1.0_Zm2   == 1.0 * Zm2  );
    static_assert(1_Zm2     == 1.0 * Zm2  );

    static_assert(1.0_Ym2   == 1.0 * Ym2  );
    static_assert(1_Ym2     == 1.0 * Ym2  );

    static_assert(1.0_Rm2   == 1.0 * Rm2  );
    static_assert(1_Rm2     == 1.0 * Rm2  );

    static_assert(1.0_Qm2   == 1.0 * Qm2  );
    static_assert(1_Qm2     == 1.0 * Qm2  );

}
