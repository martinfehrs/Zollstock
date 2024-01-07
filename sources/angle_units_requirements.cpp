#include <zollstock/angle_units.hpp>


namespace zollstock
{

    static_assert(picoradian    ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(picoradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-12L           });
    static_assert(picoradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "prad"_us        });

    static_assert(nanoradian    ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(nanoradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-9L            });
    static_assert(nanoradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "nrad"_us        });

    static_assert(microradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(microradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-6L            });
    static_assert(microradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "micrad"_us      });

    static_assert(milliradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(milliradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-3L            });
    static_assert(milliradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "mrad"_us        });

    static_assert(centiradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(centiradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-2L            });
    static_assert(centiradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "crad"_us        });

    static_assert(deciradian    ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(deciradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-1L            });
    static_assert(deciradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "drad"_us        });

    static_assert(radian        ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(radian        ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e0L             });
    static_assert(radian        ::symbols   == quantity_symbols  { ""_us , ""_us, "rad"_us         });

    static_assert(decaradian    ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(decaradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e1L             });
    static_assert(decaradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "darad"_us       });

    static_assert(hectoradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(hectoradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e2L             });
    static_assert(hectoradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "hrad"_us        });

    static_assert(kiloradian    ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(kiloradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e3L             });
    static_assert(kiloradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "krad"_us        });

    static_assert(megaradian    ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(megaradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e6L             });
    static_assert(megaradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "Mrad"_us        });

    static_assert(gigaradian    ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(gigaradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e9L             });
    static_assert(gigaradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "Grad"_us        });

    static_assert(teraradian    ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(teraradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e12L            });
    static_assert(teraradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "Trad"_us        });

    static_assert(petaradian    ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(petaradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e15L            });
    static_assert(petaradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "Prad"_us        });

    static_assert(exaradian     ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(exaradian     ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e18L            });
    static_assert(exaradian     ::symbols   == quantity_symbols  { ""_us , ""_us, "Erad"_us        });

    static_assert(zettaradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(zettaradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e21L            });
    static_assert(zettaradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "Zrad"_us        });

    static_assert(yottaradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(yottaradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e24L            });
    static_assert(yottaradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "Yrad"_us        });

    static_assert(ronnaradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(ronnaradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e27L            });
    static_assert(ronnaradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "Rrad"_us        });

    static_assert(quettaradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(quettaradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e30L            });
    static_assert(quettaradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "Qrad"_us        });


    static_assert(degree        ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(degree        ::factors   == quantity_factors  { 0.0L  , 0.0L , pi/18e1L         });
    static_assert(degree        ::symbols   == quantity_symbols  { ""_us , ""_us, "deg"_us         });


    static_assert(arcminute     ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(arcminute     ::factors   == quantity_factors  { 0.0L  , 0.0L , pi/108e2L        });
    static_assert(arcminute     ::symbols   == quantity_symbols  { ""_us , ""_us, "arcmin"_us      });


    static_assert(arcsecond     ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(arcsecond     ::factors   == quantity_factors  { 0.0L  , 0.0L , pi/648e3L        });
    static_assert(arcsecond     ::symbols   == quantity_symbols  { ""_us , ""_us, "arcsec"_us      });

    static_assert(milliarcsecond::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(milliarcsecond::factors   == quantity_factors  { 0.0L  , 0.0L , pi/648e6L        });
    static_assert(milliarcsecond::symbols   == quantity_symbols  { ""_us , ""_us, "mas"_us         });

    static_assert(microarcsecond::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(microarcsecond::factors   == quantity_factors  { 0.0L  , 0.0L , pi/648e9L        });
    static_assert(microarcsecond::symbols   == quantity_symbols  { ""_us , ""_us, "micas"_us       });


    static_assert(quektogradian ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(quektogradian ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-30L * pi/2e2L });
    static_assert(quektogradian ::symbols   == quantity_symbols  { ""_us , ""_us, "qgon"_us        });

    static_assert(rontogradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(rontogradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-27L * pi/2e2L });
    static_assert(rontogradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "rgon"_us        });

    static_assert(yoktogradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(yoktogradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-24L * pi/2e2L });
    static_assert(yoktogradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "ygon"_us        });

    static_assert(zeptogradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(zeptogradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-21L * pi/2e2L });
    static_assert(zeptogradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "zgon"_us        });

    static_assert(attogradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(attogradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-18L * pi/2e2L });
    static_assert(attogradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "agon"_us        });

    static_assert(femtogradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(femtogradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-15L * pi/2e2L });
    static_assert(femtogradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "fgon"_us        });

    static_assert(picogradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(picogradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-12L * pi/2e2L });
    static_assert(picogradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "pgon"_us        });

    static_assert(nanogradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(nanogradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-9L * pi/2e2L  });
    static_assert(nanogradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "ngon"_us        });

    static_assert(microgradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(microgradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-6L * pi/2e2L  });
    static_assert(microgradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "micgon"_us      });

    static_assert(milligradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(milligradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-3L * pi/2e2L  });
    static_assert(milligradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "mgon"_us        });

    static_assert(centigradian  ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(centigradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-2L * pi/2e2L  });
    static_assert(centigradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "cgon"_us        });

    static_assert(decigradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(decigradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-1L * pi/2e2L  });
    static_assert(decigradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "dgon"_us        });

    static_assert(gradian       ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(gradian       ::factors   == quantity_factors  { 0.0L  , 0.0L , pi/2e2L          });
    static_assert(gradian       ::symbols   == quantity_symbols  { ""_us , ""_us, "gon"_us         });

    static_assert(decagradian   ::exponents == quantity_exponents{ 0     , 0    , 1                });
    static_assert(decagradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e1L * pi/2e2L   });
    static_assert(decagradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "dagon"_us       });

    static_assert(hectogradian  ::exponents == quantity_exponents{ 0     , 0    , 1               });
    static_assert(hectogradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e2L * pi/2e2L  });
    static_assert(hectogradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "hgon"_us       });

    static_assert(kilogradian   ::exponents == quantity_exponents{ 0     , 0    , 1               });
    static_assert(kilogradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e3L * pi/2e2L  });
    static_assert(kilogradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "kgon"_us       });

    static_assert(megagradian   ::exponents == quantity_exponents{ 0     , 0    , 1               });
    static_assert(megagradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e6L * pi/2e2L  });
    static_assert(megagradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "Mgon"_us       });

    static_assert(gigagradian   ::exponents == quantity_exponents{ 0     , 0    , 1               });
    static_assert(gigagradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e9L * pi/2e2L  });
    static_assert(gigagradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "Ggon"_us       });

    static_assert(teragradian   ::exponents == quantity_exponents{ 0     , 0    , 1               });
    static_assert(teragradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e12L * pi/2e2L });
    static_assert(teragradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "Tgon"_us       });

    static_assert(petagradian   ::exponents == quantity_exponents{ 0     , 0    , 1               });
    static_assert(petagradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e15L * pi/2e2L });
    static_assert(petagradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "Pgon"_us       });

    static_assert(exagradian    ::exponents == quantity_exponents{ 0     , 0    , 1               });
    static_assert(exagradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e18L * pi/2e2L });
    static_assert(exagradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "Egon"_us       });

    static_assert(zettagradian  ::exponents == quantity_exponents{ 0     , 0    , 1               });
    static_assert(zettagradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e21L * pi/2e2L });
    static_assert(zettagradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "Zgon"_us       });

    static_assert(yottagradian  ::exponents == quantity_exponents{ 0     , 0    , 1               });
    static_assert(yottagradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e24L * pi/2e2L });
    static_assert(yottagradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "Ygon"_us       });

    static_assert(ronnagradian  ::exponents == quantity_exponents{ 0     , 0    , 1               });
    static_assert(ronnagradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e27L * pi/2e2L });
    static_assert(ronnagradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "Rgon"_us       });

    static_assert(quettagradian ::exponents == quantity_exponents{ 0     , 0    , 1               });
    static_assert(quettagradian ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e30L * pi/2e2L });
    static_assert(quettagradian ::symbols   == quantity_symbols  { ""_us , ""_us, "Qgon"_us       });



    static_assert(prad           == picoradian    {});
    static_assert(micrad         == microradian   {});
    static_assert(mrad           == milliradian   {});
    static_assert(crad           == centiradian   {});
    static_assert(rad            == radian        {});
    static_assert(darad          == decaradian    {});
    static_assert(hrad           == hectoradian   {});
    static_assert(krad           == kiloradian    {});
    static_assert(Mrad           == megaradian    {});
    static_assert(Grad           == gigaradian    {});
    static_assert(Trad           == teraradian    {});
    static_assert(Prad           == petaradian    {});
    static_assert(Erad           == exaradian     {});
    static_assert(Zrad           == zettaradian   {});
    static_assert(Yrad           == yottaradian   {});
    static_assert(Rrad           == ronnaradian   {});
    static_assert(Qrad           == quettaradian  {});

    static_assert(deg            == degree        {});

    static_assert(arcmin         == arcminute     {});
    static_assert(arcsec         == arcsecond     {});
    static_assert(mas            == milliarcsecond{});
    static_assert(micas          == microarcsecond{});

    static_assert(qgon           == quektogradian {});
    static_assert(rgon           == rontogradian  {});
    static_assert(ygon           == yoktogradian  {});
    static_assert(zgon           == zeptogradian  {});
    static_assert(agon           == attogradian   {});
    static_assert(fgon           == femtogradian  {});
    static_assert(pgon           == picogradian   {});
    static_assert(ngon           == nanogradian   {});
    static_assert(micgon         == microgradian  {});
    static_assert(mgon           == milligradian  {});
    static_assert(cgon           == centigradian  {});
    static_assert(dgon           == decigradian   {});
    static_assert(gon            == gradian       {});
    static_assert(dagon          == decagradian   {});
    static_assert(hgon           == hectogradian  {});
    static_assert(kgon           == kilogradian   {});
    static_assert(Mgon           == megagradian   {});
    static_assert(Ggon           == gigagradian   {});
    static_assert(Tgon           == teragradian   {});
    static_assert(Pgon           == petagradian   {});
    static_assert(Egon           == exagradian    {});
    static_assert(Zgon           == zettagradian  {});
    static_assert(Ygon           == yottagradian  {});
    static_assert(Rgon           == ronnagradian  {});
    static_assert(Qgon           == quettagradian {});



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


    static_assert(1.0_arcmin == 1.0 * arcmin);
    static_assert(1_arcmin   == 1.0 * arcmin);


    static_assert(1.0_arcsec == 1.0 * arcsec);
    static_assert(1_arcsec   == 1.0 * arcsec);

    static_assert(1.0_mas    == 1.0 * mas   );
    static_assert(1_mas      == 1.0 * mas   );

    static_assert(1.0_micas  == 1.0 * micas );
    static_assert(1_micas    == 1.0 * micas );


    static_assert(1.0_qgon   == 1.0 * qgon  );
    static_assert(1_qgon     == 1.0 * qgon  );

    static_assert(1.0_rgon   == 1.0 * rgon  );
    static_assert(1_rgon     == 1.0 * rgon  );

    static_assert(1.0_ygon   == 1.0 * ygon  );
    static_assert(1_ygon     == 1.0 * ygon  );

    static_assert(1.0_zgon   == 1.0 * zgon  );
    static_assert(1_zgon     == 1.0 * zgon  );

    static_assert(1.0_agon   == 1.0 * agon  );
    static_assert(1_agon     == 1.0 * agon  );

    static_assert(1.0_fgon   == 1.0 * fgon  );
    static_assert(1_fgon     == 1.0 * fgon  );

    static_assert(1.0_pgon   == 1.0 * pgon  );
    static_assert(1_pgon     == 1.0 * pgon  );

    static_assert(1.0_ngon   == 1.0 * ngon  );
    static_assert(1_ngon     == 1.0 * ngon  );

    static_assert(1.0_micgon == 1.0 * micgon);
    static_assert(1_micgon   == 1.0 * micgon);

    static_assert(1.0_mgon   == 1.0 * mgon  );
    static_assert(1_mgon     == 1.0 * mgon  );

    static_assert(1.0_cgon   == 1.0 * cgon  );
    static_assert(1_cgon     == 1.0 * cgon  );

    static_assert(1.0_dgon   == 1.0 * dgon  );
    static_assert(1_dgon     == 1.0 * dgon  );

    static_assert(1.0_gon    == 1.0 * gon   );
    static_assert(1_gon      == 1.0 * gon   );

    static_assert(1.0_dagon  == 1.0 * dagon );
    static_assert(1_dagon    == 1.0 * dagon );

    static_assert(1.0_hgon   == 1.0 * hgon  );
    static_assert(1_hgon     == 1.0 * hgon  );

    static_assert(1.0_kgon   == 1.0 * kgon  );
    static_assert(1_kgon     == 1.0 * kgon  );

    static_assert(1.0_Mgon   == 1.0 * Mgon  );
    static_assert(1_Mgon     == 1.0 * Mgon  );

    static_assert(1.0_Ggon   == 1.0 * Ggon  );
    static_assert(1_Ggon     == 1.0 * Ggon  );

    static_assert(1.0_Tgon   == 1.0 * Tgon  );
    static_assert(1_Tgon     == 1.0 * Tgon  );

    static_assert(1.0_Pgon   == 1.0 * Pgon  );
    static_assert(1_Pgon     == 1.0 * Pgon  );

    static_assert(1.0_Egon   == 1.0 * Egon  );
    static_assert(1_Egon     == 1.0 * Egon  );

    static_assert(1.0_Zgon   == 1.0 * Zgon  );
    static_assert(1_Zgon     == 1.0 * Zgon  );

    static_assert(1.0_Ygon   == 1.0 * Ygon  );
    static_assert(1_Ygon     == 1.0 * Ygon  );

    static_assert(1.0_Rgon   == 1.0 * Rgon  );
    static_assert(1_Rgon     == 1.0 * Rgon  );

    static_assert(1.0_Qgon   == 1.0 * Qgon  );
    static_assert(1_Qgon     == 1.0 * Qgon  );

}
