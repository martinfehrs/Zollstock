#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_types.hpp>


using namespace zollstock;


TEST_CASE("angle-unit-types", "[angle][unit][types]")
{

    REQUIRE(picoradian     ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(picoradian     ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-12L             });
    REQUIRE(picoradian     ::symbols   == quantity_symbols  { ""_us , ""_us, "prad"_us          });

    REQUIRE(nanoradian     ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(nanoradian     ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-9L              });
    REQUIRE(nanoradian     ::symbols   == quantity_symbols  { ""_us , ""_us, "nrad"_us          });

    REQUIRE(microradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(microradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-6L              });
    REQUIRE(microradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "micrad"_us        });

    REQUIRE(milliradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(milliradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-3L              });
    REQUIRE(milliradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "mrad"_us          });

    REQUIRE(centiradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(centiradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-2L              });
    REQUIRE(centiradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "crad"_us          });

    REQUIRE(deciradian     ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(deciradian     ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-1L              });
    REQUIRE(deciradian     ::symbols   == quantity_symbols  { ""_us , ""_us, "drad"_us          });

    REQUIRE(radian         ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(radian         ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e0L               });
    REQUIRE(radian         ::symbols   == quantity_symbols  { ""_us , ""_us, "rad"_us           });

    REQUIRE(decaradian     ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(decaradian     ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e1L               });
    REQUIRE(decaradian     ::symbols   == quantity_symbols  { ""_us , ""_us, "darad"_us         });

    REQUIRE(hectoradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(hectoradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e2L               });
    REQUIRE(hectoradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "hrad"_us          });

    REQUIRE(kiloradian     ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(kiloradian     ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e3L               });
    REQUIRE(kiloradian     ::symbols   == quantity_symbols  { ""_us , ""_us, "krad"_us          });

    REQUIRE(megaradian     ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(megaradian     ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e6L               });
    REQUIRE(megaradian     ::symbols   == quantity_symbols  { ""_us , ""_us, "Mrad"_us          });

    REQUIRE(gigaradian     ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(gigaradian     ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e9L               });
    REQUIRE(gigaradian     ::symbols   == quantity_symbols  { ""_us , ""_us, "Grad"_us          });

    REQUIRE(teraradian     ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(teraradian     ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e12L              });
    REQUIRE(teraradian     ::symbols   == quantity_symbols  { ""_us , ""_us, "Trad"_us          });

    REQUIRE(petaradian     ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(petaradian     ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e15L              });
    REQUIRE(petaradian     ::symbols   == quantity_symbols  { ""_us , ""_us, "Prad"_us          });

    REQUIRE(exaradian      ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(exaradian      ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e18L              });
    REQUIRE(exaradian      ::symbols   == quantity_symbols  { ""_us , ""_us, "Erad"_us          });

    REQUIRE(zettaradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(zettaradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e21L              });
    REQUIRE(zettaradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "Zrad"_us          });

    REQUIRE(yottaradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(yottaradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e24L              });
    REQUIRE(yottaradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "Yrad"_us          });

    REQUIRE(ronnaradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(ronnaradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e27L              });
    REQUIRE(ronnaradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "Rrad"_us          });

    REQUIRE(quettaradian   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(quettaradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e30L              });
    REQUIRE(quettaradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "Qrad"_us          });


    REQUIRE(degree         ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(degree         ::factors   == quantity_factors  { 0.0L  , 0.0L , pi/18e1L           });
    REQUIRE(degree         ::symbols   == quantity_symbols  { ""_us , ""_us, "deg"_us           });


    REQUIRE(arcminute      ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(arcminute      ::factors   == quantity_factors  { 0.0L  , 0.0L , pi/108e2L          });
    REQUIRE(arcminute      ::symbols   == quantity_symbols  { ""_us , ""_us, "arcmin"_us        });


    REQUIRE(quektoarcsecond::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(quektoarcsecond::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-30L * pi/648e3L });
    REQUIRE(quektoarcsecond::symbols   == quantity_symbols  { ""_us , ""_us, "qas"_us           });

    REQUIRE(rontoarcsecond ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(rontoarcsecond ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-27L * pi/648e3L });
    REQUIRE(rontoarcsecond ::symbols   == quantity_symbols  { ""_us , ""_us, "ras"_us           });

    REQUIRE(yoktoarcsecond ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(yoktoarcsecond ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-24L * pi/648e3L });
    REQUIRE(yoktoarcsecond ::symbols   == quantity_symbols  { ""_us , ""_us, "yas"_us           });

    REQUIRE(zeptoarcsecond ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(zeptoarcsecond ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-21L * pi/648e3L });
    REQUIRE(zeptoarcsecond ::symbols   == quantity_symbols  { ""_us , ""_us, "zas"_us           });

    REQUIRE(attoarcsecond  ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(attoarcsecond  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-18L * pi/648e3L });
    REQUIRE(attoarcsecond  ::symbols   == quantity_symbols  { ""_us , ""_us, "aas"_us           });

    REQUIRE(femtoarcsecond ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(femtoarcsecond ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-15L * pi/648e3L });
    REQUIRE(femtoarcsecond ::symbols   == quantity_symbols  { ""_us , ""_us, "fas"_us           });

    REQUIRE(picoarcsecond  ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(picoarcsecond  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-12L * pi/648e3L });
    REQUIRE(picoarcsecond  ::symbols   == quantity_symbols  { ""_us , ""_us, "pas"_us           });

    REQUIRE(nanoarcsecond  ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(nanoarcsecond  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-9L * pi/648e3L  });
    REQUIRE(nanoarcsecond  ::symbols   == quantity_symbols  { ""_us , ""_us, "nas"_us           });

    REQUIRE(microarcsecond ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(microarcsecond ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-6L * pi/648e3L  });
    REQUIRE(microarcsecond ::symbols   == quantity_symbols  { ""_us , ""_us, "micas"_us         });

    REQUIRE(milliarcsecond ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(milliarcsecond ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-3L * pi/648e3L  });
    REQUIRE(milliarcsecond ::symbols   == quantity_symbols  { ""_us , ""_us, "mas"_us           });

    REQUIRE(centiarcsecond ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(centiarcsecond ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-2L * pi/648e3L  });
    REQUIRE(centiarcsecond ::symbols   == quantity_symbols  { ""_us , ""_us, "cas"_us           });

    REQUIRE(deciarcsecond  ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(deciarcsecond  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-1L * pi/648e3L  });
    REQUIRE(deciarcsecond  ::symbols   == quantity_symbols  { ""_us , ""_us, "das"_us           });

    REQUIRE(arcsecond      ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(arcsecond      ::factors   == quantity_factors  { 0.0L  , 0.0L , pi/648e3L          });
    REQUIRE(arcsecond      ::symbols   == quantity_symbols  { ""_us , ""_us, "arcsec"_us        });

    REQUIRE(decaarcsecond  ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(decaarcsecond  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e1L * pi/648e3L   });
    REQUIRE(decaarcsecond  ::symbols   == quantity_symbols  { ""_us , ""_us, "daas"_us          });

    REQUIRE(hectoarcsecond ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(hectoarcsecond ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e2L * pi/648e3L   });
    REQUIRE(hectoarcsecond ::symbols   == quantity_symbols  { ""_us , ""_us, "has"_us           });

    REQUIRE(kiloarcsecond  ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(kiloarcsecond  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e3L * pi/648e3L   });
    REQUIRE(kiloarcsecond  ::symbols   == quantity_symbols  { ""_us , ""_us, "kas"_us           });

    REQUIRE(megaarcsecond  ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(megaarcsecond  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e6L * pi/648e3L   });
    REQUIRE(megaarcsecond  ::symbols   == quantity_symbols  { ""_us , ""_us, "Mas"_us           });

    REQUIRE(gigaarcsecond  ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(gigaarcsecond  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e9L * pi/648e3L   });
    REQUIRE(gigaarcsecond  ::symbols   == quantity_symbols  { ""_us , ""_us, "Gas"_us           });

    REQUIRE(teraarcsecond  ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(teraarcsecond  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e12L * pi/648e3L  });
    REQUIRE(teraarcsecond  ::symbols   == quantity_symbols  { ""_us , ""_us, "Tas"_us           });

    REQUIRE(petaarcsecond  ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(petaarcsecond  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e15L * pi/648e3L  });
    REQUIRE(petaarcsecond  ::symbols   == quantity_symbols  { ""_us , ""_us, "Pas"_us           });

    REQUIRE(exaarcsecond   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(exaarcsecond   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e18L * pi/648e3L  });
    REQUIRE(exaarcsecond   ::symbols   == quantity_symbols  { ""_us , ""_us, "Eas"_us           });

    REQUIRE(zettaarcsecond ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(zettaarcsecond ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e21L * pi/648e3L  });
    REQUIRE(zettaarcsecond ::symbols   == quantity_symbols  { ""_us , ""_us, "Zas"_us           });

    REQUIRE(yottaarcsecond ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(yottaarcsecond ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e24L * pi/648e3L  });
    REQUIRE(yottaarcsecond ::symbols   == quantity_symbols  { ""_us , ""_us, "Yas"_us           });

    REQUIRE(ronnaarcsecond ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(ronnaarcsecond ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e27L * pi/648e3L  });
    REQUIRE(ronnaarcsecond ::symbols   == quantity_symbols  { ""_us , ""_us, "Ras"_us           });

    REQUIRE(quettaarcsecond::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(quettaarcsecond::factors   == quantity_factors  { 0.0L  , 0.0L , 1e30L * pi/648e3L  });
    REQUIRE(quettaarcsecond::symbols   == quantity_symbols  { ""_us , ""_us, "Qas"_us           });


    REQUIRE(quektogradian  ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(quektogradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-30L * pi/2e2L   });
    REQUIRE(quektogradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "qgon"_us          });

    REQUIRE(rontogradian   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(rontogradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-27L * pi/2e2L   });
    REQUIRE(rontogradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "rgon"_us          });

    REQUIRE(yoktogradian   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(yoktogradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-24L * pi/2e2L   });
    REQUIRE(yoktogradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "ygon"_us          });

    REQUIRE(zeptogradian   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(zeptogradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-21L * pi/2e2L   });
    REQUIRE(zeptogradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "zgon"_us          });

    REQUIRE(attogradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(attogradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-18L * pi/2e2L   });
    REQUIRE(attogradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "agon"_us          });

    REQUIRE(femtogradian   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(femtogradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-15L * pi/2e2L   });
    REQUIRE(femtogradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "fgon"_us          });

    REQUIRE(picogradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(picogradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-12L * pi/2e2L   });
    REQUIRE(picogradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "pgon"_us          });

    REQUIRE(nanogradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(nanogradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-9L * pi/2e2L    });
    REQUIRE(nanogradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "ngon"_us          });

    REQUIRE(microgradian   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(microgradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-6L * pi/2e2L    });
    REQUIRE(microgradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "micgon"_us        });

    REQUIRE(milligradian   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(milligradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-3L * pi/2e2L    });
    REQUIRE(milligradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "mgon"_us          });

    REQUIRE(centigradian   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(centigradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-2L * pi/2e2L    });
    REQUIRE(centigradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "cgon"_us          });

    REQUIRE(decigradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(decigradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-1L * pi/2e2L    });
    REQUIRE(decigradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "dgon"_us          });

    REQUIRE(gradian        ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(gradian        ::factors   == quantity_factors  { 0.0L  , 0.0L , pi/2e2L            });
    REQUIRE(gradian        ::symbols   == quantity_symbols  { ""_us , ""_us, "gon"_us           });

    REQUIRE(decagradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(decagradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e1L * pi/2e2L     });
    REQUIRE(decagradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "dagon"_us         });

    REQUIRE(hectogradian   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(hectogradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e2L * pi/2e2L     });
    REQUIRE(hectogradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "hgon"_us          });

    REQUIRE(kilogradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(kilogradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e3L * pi/2e2L     });
    REQUIRE(kilogradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "kgon"_us          });

    REQUIRE(megagradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(megagradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e6L * pi/2e2L     });
    REQUIRE(megagradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "Mgon"_us          });

    REQUIRE(gigagradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(gigagradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e9L * pi/2e2L     });
    REQUIRE(gigagradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "Ggon"_us          });

    REQUIRE(teragradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(teragradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e12L * pi/2e2L    });
    REQUIRE(teragradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "Tgon"_us          });

    REQUIRE(petagradian    ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(petagradian    ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e15L * pi/2e2L    });
    REQUIRE(petagradian    ::symbols   == quantity_symbols  { ""_us , ""_us, "Pgon"_us          });

    REQUIRE(exagradian     ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(exagradian     ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e18L * pi/2e2L    });
    REQUIRE(exagradian     ::symbols   == quantity_symbols  { ""_us , ""_us, "Egon"_us          });

    REQUIRE(zettagradian   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(zettagradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e21L * pi/2e2L    });
    REQUIRE(zettagradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "Zgon"_us          });

    REQUIRE(yottagradian   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(yottagradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e24L * pi/2e2L    });
    REQUIRE(yottagradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "Ygon"_us          });

    REQUIRE(ronnagradian   ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(ronnagradian   ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e27L * pi/2e2L    });
    REQUIRE(ronnagradian   ::symbols   == quantity_symbols  { ""_us , ""_us, "Rgon"_us          });

    REQUIRE(quettagradian  ::exponents == quantity_exponents{ 0     , 0    , 1                  });
    REQUIRE(quettagradian  ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e30L * pi/2e2L    });
    REQUIRE(quettagradian  ::symbols   == quantity_symbols  { ""_us , ""_us, "Qgon"_us          });

}
