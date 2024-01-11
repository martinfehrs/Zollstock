#include <catch2/catch_all.hpp>
#include <zollstock/time_unit_types.hpp>


using namespace zollstock;


TEST_CASE("time-unit-types", "[time][unit][types]")
{

    REQUIRE(quektosecond::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(quektosecond::factors   == quantity_factors  { 0.0L   , 1e-30L , 0.0L  });
    REQUIRE(quektosecond::symbols   == quantity_symbols  { ""_us  , "qs"_us, ""_us });

    REQUIRE(rontosecond ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(rontosecond ::factors   == quantity_factors  { 0.0L   , 1e-27L , 0.0L  });
    REQUIRE(rontosecond ::symbols   == quantity_symbols  { ""_us  , "rs"_us, ""_us });

    REQUIRE(yoktosecond ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(yoktosecond ::factors   == quantity_factors  { 0.0L   , 1e-24L , 0.0L  });
    REQUIRE(yoktosecond ::symbols   == quantity_symbols  { ""_us  , "ys"_us, ""_us });

    REQUIRE(zeptosecond ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(zeptosecond ::factors   == quantity_factors  { 0.0L   , 1e-21L , 0.0L  });
    REQUIRE(zeptosecond ::symbols   == quantity_symbols  { ""_us  , "zs"_us, ""_us });

    REQUIRE(attosecond  ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(attosecond  ::factors   == quantity_factors  { 0.0L   , 1e-18L , 0.0L  });
    REQUIRE(attosecond  ::symbols   == quantity_symbols  { ""_us  , "as"_us, ""_us });

    REQUIRE(femtosecond ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(femtosecond ::factors   == quantity_factors  { 0.0L   , 1e-15L , 0.0L  });
    REQUIRE(femtosecond ::symbols   == quantity_symbols  { ""_us  , "fs"_us, ""_us });

    REQUIRE(picosecond  ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(picosecond  ::factors   == quantity_factors  { 0.0L   , 1e-12L , 0.0L  });
    REQUIRE(picosecond  ::symbols   == quantity_symbols  { ""_us  , "ps"_us, ""_us });

    REQUIRE(nanosecond  ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(nanosecond  ::factors   == quantity_factors  { 0.0L    , 1e-9L , 0.0L  });
    REQUIRE(nanosecond  ::symbols   == quantity_symbols  { ""_us  , "ns"_us, ""_us });

    REQUIRE(microsecond ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(microsecond ::factors   == quantity_factors  { 0.0L    , 1e-6L , 0.0L  });
    REQUIRE(microsecond ::symbols   == quantity_symbols  { ""_us, "mics"_us, ""_us });

    REQUIRE(millisecond ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(millisecond ::factors   == quantity_factors  { 0.0L    , 1e-3L , 0.0L  });
    REQUIRE(millisecond ::symbols   == quantity_symbols  { ""_us  , "ms"_us, ""_us });

    REQUIRE(centisecond ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(centisecond ::factors   == quantity_factors  { 0.0L    , 1e-2L , 0.0L  });
    REQUIRE(centisecond ::symbols   == quantity_symbols  { ""_us  , "cs"_us, ""_us });

    REQUIRE(decisecond  ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(decisecond  ::factors   == quantity_factors  { 0.0L    , 1e-1L , 0.0L  });
    REQUIRE(decisecond  ::symbols   == quantity_symbols  { ""_us  , "ds"_us, ""_us });

    REQUIRE(second      ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(second      ::factors   == quantity_factors  { 0.0L     , 1e0L , 0.0L  });
    REQUIRE(second      ::symbols   == quantity_symbols  { ""_us   , "s"_us, ""_us });

    REQUIRE(decasecond  ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(decasecond  ::factors   == quantity_factors  { 0.0L     , 1e1L , 0.0L  });
    REQUIRE(decasecond  ::symbols   == quantity_symbols  { ""_us , "das"_us, ""_us });

    REQUIRE(hectosecond ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(hectosecond ::factors   == quantity_factors  { 0.0L     , 1e2L , 0.0L  });
    REQUIRE(hectosecond ::symbols   == quantity_symbols  { ""_us  , "hs"_us, ""_us });

    REQUIRE(kilosecond  ::exponents == quantity_exponents{ 0        , 1    , 0     });
    REQUIRE(kilosecond  ::factors   == quantity_factors  { 0.0L     , 1e3L , 0.0L  });
    REQUIRE(kilosecond  ::symbols   == quantity_symbols  { ""_us  , "ks"_us, ""_us });

    REQUIRE(megasecond  ::exponents == quantity_exponents{ 0    , 1      , 0     });
    REQUIRE(megasecond  ::factors   == quantity_factors  { 0.0L , 1e6L   , 0.0L  });
    REQUIRE(megasecond  ::symbols   == quantity_symbols  { ""_us, "Ms"_us, ""_us });

    REQUIRE(gigasecond  ::exponents == quantity_exponents{ 0    , 1      , 0     });
    REQUIRE(gigasecond  ::factors   == quantity_factors  { 0.0L , 1e9L   , 0.0L  });
    REQUIRE(gigasecond  ::symbols   == quantity_symbols  { ""_us, "Gs"_us, ""_us });

    REQUIRE(terasecond  ::exponents == quantity_exponents{ 0    , 1      , 0     });
    REQUIRE(terasecond  ::factors   == quantity_factors  { 0.0L , 1e12L  , 0.0L  });
    REQUIRE(terasecond  ::symbols   == quantity_symbols  { ""_us, "Ts"_us, ""_us });

    REQUIRE(petasecond  ::exponents == quantity_exponents{ 0    , 1      , 0     });
    REQUIRE(petasecond  ::factors   == quantity_factors  { 0.0L , 1e15L  , 0.0L  });
    REQUIRE(petasecond  ::symbols   == quantity_symbols  { ""_us, "Ps"_us, ""_us });

    REQUIRE(exasecond   ::exponents == quantity_exponents{ 0    , 1      , 0     });
    REQUIRE(exasecond   ::factors   == quantity_factors  { 0.0L , 1e18L  , 0.0L  });
    REQUIRE(exasecond   ::symbols   == quantity_symbols  { ""_us, "Es"_us, ""_us });

    REQUIRE(zettasecond ::exponents == quantity_exponents{ 0    , 1      , 0     });
    REQUIRE(zettasecond ::factors   == quantity_factors  { 0.0L , 1e21L  , 0.0L  });
    REQUIRE(zettasecond ::symbols   == quantity_symbols  { ""_us, "Zs"_us, ""_us });

    REQUIRE(yottasecond ::exponents == quantity_exponents{ 0    , 1      , 0     });
    REQUIRE(yottasecond ::factors   == quantity_factors  { 0.0L , 1e24L  , 0.0L  });
    REQUIRE(yottasecond ::symbols   == quantity_symbols  { ""_us, "Ys"_us, ""_us });

    REQUIRE(ronnasecond ::exponents == quantity_exponents{ 0    , 1      , 0     });
    REQUIRE(ronnasecond ::factors   == quantity_factors  { 0.0L , 1e27L  , 0.0L  });
    REQUIRE(ronnasecond ::symbols   == quantity_symbols  { ""_us, "Rs"_us, ""_us });

    REQUIRE(quettasecond::exponents == quantity_exponents{ 0    , 1      , 0     });
    REQUIRE(quettasecond::factors   == quantity_factors  { 0.0L , 1e30L  , 0.0L  });
    REQUIRE(quettasecond::symbols   == quantity_symbols  { ""_us, "Qs"_us, ""_us });

}
