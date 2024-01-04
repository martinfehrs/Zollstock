#include <zollstock/angle_units.hpp>


namespace zollstock
{

    static_assert(picoradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(picoradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-12L           });
    static_assert(picoradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "prad"_us        });

    static_assert(nanoradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(nanoradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-9L            });
    static_assert(nanoradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "nrad"_us        });

    static_assert(microradian ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(microradian ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-6L            });
    static_assert(microradian ::symbols   == quantity_symbols  { ""_us , ""_us, "micrad"_us      });

    static_assert(milliradian ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(milliradian ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-3L            });
    static_assert(milliradian ::symbols   == quantity_symbols  { ""_us , ""_us, "mrad"_us        });

    static_assert(centiradian ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(centiradian ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-2L            });
    static_assert(centiradian ::symbols   == quantity_symbols  { ""_us , ""_us, "crad"_us        });

    static_assert(deciradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(deciradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-1L            });
    static_assert(deciradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "drad"_us        });

    static_assert(radian      ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(radian      ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e0L             });
    static_assert(radian      ::symbols   == quantity_symbols  { ""_us , ""_us, "rad"_us         });

    static_assert(decaradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(decaradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e1L             });
    static_assert(decaradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "darad"_us       });

    static_assert(hectoradian ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(hectoradian ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e2L             });
    static_assert(hectoradian ::symbols   == quantity_symbols  { ""_us , ""_us, "hrad"_us        });

    static_assert(kiloradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(kiloradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e3L             });
    static_assert(kiloradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "krad"_us        });

    static_assert(megaradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(megaradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e6L             });
    static_assert(megaradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "Mrad"_us        });

    static_assert(gigaradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(gigaradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e9L             });
    static_assert(gigaradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "Grad"_us        });

    static_assert(teraradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(teraradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e12L            });
    static_assert(teraradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "Trad"_us        });

    static_assert(petaradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(petaradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e15L            });
    static_assert(petaradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "Prad"_us        });

    static_assert(exaradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(exaradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e18L            });
    static_assert(exaradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "Erad"_us        });

    static_assert(zettaradian ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(zettaradian ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e21L            });
    static_assert(zettaradian ::symbols   == quantity_symbols  { ""_us , ""_us, "Zrad"_us        });

    static_assert(yottaradian ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(yottaradian ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e24L            });
    static_assert(yottaradian ::symbols   == quantity_symbols  { ""_us , ""_us, "Yrad"_us        });

    static_assert(ronnaradian ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(ronnaradian ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e27L            });
    static_assert(ronnaradian ::symbols   == quantity_symbols  { ""_us , ""_us, "Rrad"_us        });

    static_assert(quettaradian::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(quettaradian::factors   == quantity_factors  { 0.0L  , 0.0L , 1e30L            });
    static_assert(quettaradian::symbols   == quantity_symbols  { ""_us , ""_us, "Qrad"_us        });

    static_assert(degree     ::exponents == quantity_exponents{ 0     , 0    , 1                 });
    static_assert(degree     ::factors   == quantity_factors  { 0.0L  , 0.0L , pi/180.0L         });
    static_assert(degree     ::symbols   == quantity_symbols  { ""_us , ""_us, "deg"_us          });


    static_assert(prad   == picoradian  {});
    static_assert(micrad == microradian {});
    static_assert(mrad   == milliradian {});
    static_assert(crad   == centiradian {});
    static_assert(rad    == radian      {});
    static_assert(darad  == decaradian  {});
    static_assert(hrad   == hectoradian {});
    static_assert(krad   == kiloradian  {});
    static_assert(Mrad   == megaradian  {});
    static_assert(Grad   == gigaradian  {});
    static_assert(Trad   == teraradian  {});
    static_assert(Prad   == petaradian  {});
    static_assert(Erad   == exaradian   {});
    static_assert(Zrad   == zettaradian {});
    static_assert(Yrad   == yottaradian {});
    static_assert(Rrad   == ronnaradian {});
    static_assert(Qrad   == quettaradian{});
    static_assert(deg    == degree      {});

    static_assert(1.0_prad   == 1.0 * prad  );
    static_assert(1_prad     == 1.0 * prad  );

    static_assert(1.0_nrad   == 1.0 * nrad  );
    static_assert(1_nrad     == 1.0 * nrad  );

    static_assert(1.0_micrad == 1.0 * micrad);
    static_assert(1_micrad   == 1.0 * micrad);

    static_assert(1.0_mrad   == 1.0 * mrad  );
    static_assert(1_mrad     == 1.0 * mrad  );

    static_assert(1.0_crad   == 1.0 * crad  );
    static_assert(1_crad     == 1.0 * crad  );

    static_assert(1.0_drad   == 1.0 * drad  );
    static_assert(1_drad     == 1.0 * drad  );

    static_assert(1.0_rad    == 1.0 * rad   );
    static_assert(1_rad      == 1.0 * rad   );

    static_assert(1.0_darad  == 1.0 * darad );
    static_assert(1_darad    == 1.0 * darad );

    static_assert(1.0_hrad   == 1.0 * hrad  );
    static_assert(1_hrad     == 1.0 * hrad  );

    static_assert(1.0_krad   == 1.0 * krad  );
    static_assert(1_krad     == 1.0 * krad  );

    static_assert(1.0_Mrad   == 1.0 * Mrad  );
    static_assert(1_Mrad     == 1.0 * Mrad  );

    static_assert(1.0_Grad   == 1.0 * Grad  );
    static_assert(1_Grad     == 1.0 * Grad  );

    static_assert(1.0_Trad   == 1.0 * Trad  );
    static_assert(1_Trad     == 1.0 * Trad  );

    static_assert(1.0_Prad   == 1.0 * Prad  );
    static_assert(1_Prad     == 1.0 * Prad  );

    static_assert(1.0_Erad   == 1.0 * Erad  );
    static_assert(1_Erad     == 1.0 * Erad  );

    static_assert(1.0_Zrad   == 1.0 * Zrad  );
    static_assert(1_Zrad     == 1.0 * Zrad  );

    static_assert(1.0_Yrad   == 1.0 * Yrad  );
    static_assert(1_Yrad     == 1.0 * Yrad  );

    static_assert(1.0_Rrad   == 1.0 * Rrad  );
    static_assert(1_Rrad     == 1.0 * Rrad  );

    static_assert(1.0_Qrad   == 1.0 * Qrad  );
    static_assert(1_Qrad     == 1.0 * Qrad  );

    static_assert(1.0_deg    == 1.0 * deg   );
    static_assert(1_deg      == 1.0 * deg   );

}
