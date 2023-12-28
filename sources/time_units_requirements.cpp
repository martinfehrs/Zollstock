#include <zollstock/time_units.hpp>


namespace zollstock
{

    static_assert(quektosecond::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(quektosecond::factors   == unit_factors  { 0.0L   , 1e-30L , 0.0L  });
    static_assert(quektosecond::symbols   == unit_symbols  { ""_us  , "qs"_us, ""_us });

    static_assert(rontosecond ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(rontosecond ::factors   == unit_factors  { 0.0L   , 1e-27L , 0.0L  });
    static_assert(rontosecond ::symbols   == unit_symbols  { ""_us  , "rs"_us, ""_us });

    static_assert(yoktosecond ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(yoktosecond ::factors   == unit_factors  { 0.0L   , 1e-24L , 0.0L  });
    static_assert(yoktosecond ::symbols   == unit_symbols  { ""_us  , "ys"_us, ""_us });

    static_assert(zeptosecond ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(zeptosecond ::factors   == unit_factors  { 0.0L   , 1e-21L , 0.0L  });
    static_assert(zeptosecond ::symbols   == unit_symbols  { ""_us  , "zs"_us, ""_us });

    static_assert(attosecond  ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(attosecond  ::factors   == unit_factors  { 0.0L   , 1e-18L , 0.0L  });
    static_assert(attosecond  ::symbols   == unit_symbols  { ""_us  , "as"_us, ""_us });

    static_assert(femtosecond ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(femtosecond ::factors   == unit_factors  { 0.0L   , 1e-15L , 0.0L  });
    static_assert(femtosecond ::symbols   == unit_symbols  { ""_us  , "fs"_us, ""_us });

    static_assert(picosecond  ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(picosecond  ::factors   == unit_factors  { 0.0L   , 1e-12L , 0.0L  });
    static_assert(picosecond  ::symbols   == unit_symbols  { ""_us  , "ps"_us, ""_us });

    static_assert(nanosecond  ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(nanosecond  ::factors   == unit_factors  { 0.0L    , 1e-9L , 0.0L  });
    static_assert(nanosecond  ::symbols   == unit_symbols  { ""_us  , "ns"_us, ""_us });

    static_assert(microsecond ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(microsecond ::factors   == unit_factors  { 0.0L    , 1e-6L , 0.0L  });
    static_assert(microsecond ::symbols   == unit_symbols  { ""_us, "mics"_us, ""_us });

    static_assert(millisecond ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(millisecond ::factors   == unit_factors  { 0.0L    , 1e-3L , 0.0L  });
    static_assert(millisecond ::symbols   == unit_symbols  { ""_us  , "ms"_us, ""_us });

    static_assert(centisecond ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(centisecond ::factors   == unit_factors  { 0.0L    , 1e-2L , 0.0L  });
    static_assert(centisecond ::symbols   == unit_symbols  { ""_us  , "cs"_us, ""_us });

    static_assert(decisecond  ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(decisecond  ::factors   == unit_factors  { 0.0L    , 1e-1L , 0.0L  });
    static_assert(decisecond  ::symbols   == unit_symbols  { ""_us  , "ds"_us, ""_us });

    static_assert(second      ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(second      ::factors   == unit_factors  { 0.0L     , 1e0L , 0.0L  });
    static_assert(second      ::symbols   == unit_symbols  { ""_us   , "s"_us, ""_us });

    static_assert(decasecond  ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(decasecond  ::factors   == unit_factors  { 0.0L     , 1e1L , 0.0L  });
    static_assert(decasecond  ::symbols   == unit_symbols  { ""_us , "das"_us, ""_us });

    static_assert(hectosecond ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(hectosecond ::factors   == unit_factors  { 0.0L     , 1e2L , 0.0L  });
    static_assert(hectosecond ::symbols   == unit_symbols  { ""_us  , "hs"_us, ""_us });

    static_assert(kilosecond  ::exponents == unit_exponents{ 0        , 1    , 0     });
    static_assert(kilosecond  ::factors   == unit_factors  { 0.0L     , 1e3L , 0.0L  });
    static_assert(kilosecond  ::symbols   == unit_symbols  { ""_us  , "ks"_us, ""_us });

    static_assert(megasecond  ::exponents == unit_exponents{ 0    , 1      , 0     });
    static_assert(megasecond  ::factors   == unit_factors  { 0.0L , 1e6L   , 0.0L  });
    static_assert(megasecond  ::symbols   == unit_symbols  { ""_us, "Ms"_us, ""_us });

    static_assert(gigasecond  ::exponents == unit_exponents{ 0    , 1      , 0     });
    static_assert(gigasecond  ::factors   == unit_factors  { 0.0L , 1e9L   , 0.0L  });
    static_assert(gigasecond  ::symbols   == unit_symbols  { ""_us, "Gs"_us, ""_us });

    static_assert(terasecond  ::exponents == unit_exponents{ 0    , 1      , 0     });
    static_assert(terasecond  ::factors   == unit_factors  { 0.0L , 1e12L  , 0.0L  });
    static_assert(terasecond  ::symbols   == unit_symbols  { ""_us, "Ts"_us, ""_us });

    static_assert(petasecond  ::exponents == unit_exponents{ 0    , 1      , 0     });
    static_assert(petasecond  ::factors   == unit_factors  { 0.0L , 1e15L  , 0.0L  });
    static_assert(petasecond  ::symbols   == unit_symbols  { ""_us, "Ps"_us, ""_us });

    static_assert(exasecond   ::exponents == unit_exponents{ 0    , 1      , 0     });
    static_assert(exasecond   ::factors   == unit_factors  { 0.0L , 1e18L  , 0.0L  });
    static_assert(exasecond   ::symbols   == unit_symbols  { ""_us, "Es"_us, ""_us });

    static_assert(zettasecond ::exponents == unit_exponents{ 0    , 1      , 0     });
    static_assert(zettasecond ::factors   == unit_factors  { 0.0L , 1e21L  , 0.0L  });
    static_assert(zettasecond ::symbols   == unit_symbols  { ""_us, "Zs"_us, ""_us });

    static_assert(yottasecond ::exponents == unit_exponents{ 0    , 1      , 0     });
    static_assert(yottasecond ::factors   == unit_factors  { 0.0L , 1e24L  , 0.0L  });
    static_assert(yottasecond ::symbols   == unit_symbols  { ""_us, "Ys"_us, ""_us });

    static_assert(ronnasecond ::exponents == unit_exponents{ 0    , 1      , 0     });
    static_assert(ronnasecond ::factors   == unit_factors  { 0.0L , 1e27L  , 0.0L  });
    static_assert(ronnasecond ::symbols   == unit_symbols  { ""_us, "Rs"_us, ""_us });

    static_assert(quettasecond::exponents == unit_exponents{ 0    , 1      , 0     });
    static_assert(quettasecond::factors   == unit_factors  { 0.0L , 1e30L  , 0.0L  });
    static_assert(quettasecond::symbols   == unit_symbols  { ""_us, "Qs"_us, ""_us });


    static_assert(qs   == quektosecond{});
    static_assert(rs   == rontosecond {});
    static_assert(ys   == yoktosecond {});
    static_assert(zs   == zeptosecond {});
    static_assert(as   == attosecond  {});
    static_assert(fs   == femtosecond {});
    static_assert(ps   == picosecond  {});
    static_assert(mics == microsecond {});
    static_assert(ms   == millisecond {});
    static_assert(cs   == centisecond {});
    static_assert(s    == second      {});
    static_assert(das  == decasecond  {});
    static_assert(hs   == hectosecond {});
    static_assert(ks   == kilosecond  {});
    static_assert(Ms   == megasecond  {});
    static_assert(Gs   == gigasecond  {});
    static_assert(Ts   == terasecond  {});
    static_assert(Ps   == petasecond  {});
    static_assert(Es   == exasecond   {});
    static_assert(Zs   == zettasecond {});
    static_assert(Ys   == yottasecond {});
    static_assert(Rs   == ronnasecond {});
    static_assert(Qs   == quettasecond{});


    static_assert(1.0_qs   == 1.0 * qs  );
    static_assert(1_qs     == 1.0 * qs  );

    static_assert(1.0_rs   == 1.0 * rs  );
    static_assert(1_rs     == 1.0 * rs  );

    static_assert(1.0_ys   == 1.0 * ys  );
    static_assert(1_ys     == 1.0 * ys  );

    static_assert(1.0_zs   == 1.0 * zs  );
    static_assert(1_zs     == 1.0 * zs  );

    static_assert(1.0_as   == 1.0 * as  );
    static_assert(1_as     == 1.0 * as  );

    static_assert(1.0_fs   == 1.0 * fs  );
    static_assert(1_fs     == 1.0 * fs  );

    static_assert(1.0_ps   == 1.0 * ps  );
    static_assert(1_ps     == 1.0 * ps  );

    static_assert(1.0_ns   == 1.0 * ns  );
    static_assert(1_ns     == 1.0 * ns  );

    static_assert(1.0_mics == 1.0 * mics);
    static_assert(1_mics   == 1.0 * mics);

    static_assert(1.0_ms   == 1.0 * ms  );
    static_assert(1_ms     == 1.0 * ms  );

    static_assert(1.0_cs   == 1.0 * cs   );
    static_assert(1_cs     == 1.0 * cs  );

    static_assert(1.0_ds   == 1.0 * ds  );
    static_assert(1_ds     == 1.0 * ds  );

    static_assert(1.0_s    == 1.0 * s   );
    static_assert(1_s      == 1.0 * s   );

    static_assert(1.0_das  == 1.0 * das );
    static_assert(1_das    == 1.0 * das );

    static_assert(1.0_hs   == 1.0 * hs  );
    static_assert(1_hs     == 1.0 * hs  );

    static_assert(1.0_ks   == 1.0 * ks  );
    static_assert(1_ks     == 1.0 * ks  );

    static_assert(1.0_Ms   == 1.0 * Ms  );
    static_assert(1_Ms     == 1.0 * Ms  );

    static_assert(1.0_Gs   == 1.0 * Gs  );
    static_assert(1_Gs     == 1.0 * Gs  );

    static_assert(1.0_Ts   == 1.0 * Ts  );
    static_assert(1_Ts     == 1.0 * Ts  );

    static_assert(1.0_Ps   == 1.0 * Ps  );
    static_assert(1_Ps     == 1.0 * Ps  );

    static_assert(1.0_Es   == 1.0 * Es  );
    static_assert(1_Es     == 1.0 * Es  );

    static_assert(1.0_Zs   == 1.0 * Zs  );
    static_assert(1_Zs     == 1.0 * Zs  );

    static_assert(1.0_Ys   == 1.0 * Ys  );
    static_assert(1_Ys     == 1.0 * Ys  );

    static_assert(1.0_Rs   == 1.0 * Rs  );
    static_assert(1_Rs     == 1.0 * Rs  );

    static_assert(1.0_Qs   == 1.0 * Qs  );
    static_assert(1_Qs     == 1.0 * Qs  );

}
