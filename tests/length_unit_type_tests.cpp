#include <catch2/catch_all.hpp>
#include <zollstock/length_unit_types.hpp>


using namespace zollstock;


TEST_CASE( "length-unit-types", "[length][unit][types]" )
{

    REQUIRE(quektometer::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(quektometer::factors   == quantity_factors  { 1e-30L   , 0.0L , 0.0L  });
    REQUIRE(quektometer::symbols   == quantity_symbols  { "qm"_us  , ""_us, ""_us });

    REQUIRE(rontometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(rontometer ::factors   == quantity_factors  { 1e-27L   , 0.0L , 0.0L  });
    REQUIRE(rontometer ::symbols   == quantity_symbols  { "rm"_us  , ""_us, ""_us });

    REQUIRE(yoktometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(yoktometer ::factors   == quantity_factors  { 1e-24L   , 0.0L , 0.0L  });
    REQUIRE(yoktometer ::symbols   == quantity_symbols  { "ym"_us  , ""_us, ""_us });

    REQUIRE(zeptometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(zeptometer ::factors   == quantity_factors  { 1e-21L   , 0.0L , 0.0L  });
    REQUIRE(zeptometer ::symbols   == quantity_symbols  { "zm"_us  , ""_us, ""_us });

    REQUIRE(attometer  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(attometer  ::factors   == quantity_factors  { 1e-18L   , 0.0L , 0.0L  });
    REQUIRE(attometer  ::symbols   == quantity_symbols  { "am"_us  , ""_us, ""_us });

    REQUIRE(femtometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(femtometer ::factors   == quantity_factors  { 1e-15L   , 0.0L , 0.0L  });
    REQUIRE(femtometer ::symbols   == quantity_symbols  { "fm"_us  , ""_us, ""_us });

    REQUIRE(picometer  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(picometer  ::factors   == quantity_factors  { 1e-12L   , 0.0L , 0.0L  });
    REQUIRE(picometer  ::symbols   == quantity_symbols  { "pm"_us  , ""_us, ""_us });

    REQUIRE(nanometer  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(nanometer  ::factors   == quantity_factors  { 1e-9L    , 0.0L , 0.0L  });
    REQUIRE(nanometer  ::symbols   == quantity_symbols  { "nm"_us  , ""_us, ""_us });

    REQUIRE(micrometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(micrometer ::factors   == quantity_factors  { 1e-6L    , 0.0L , 0.0L  });
    REQUIRE(micrometer ::symbols   == quantity_symbols  { "micm"_us, ""_us, ""_us });

    REQUIRE(millimeter ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(millimeter ::factors   == quantity_factors  { 1e-3L    , 0.0L , 0.0L  });
    REQUIRE(millimeter ::symbols   == quantity_symbols  { "mm"_us  , ""_us, ""_us });

    REQUIRE(centimeter ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(centimeter ::factors   == quantity_factors  { 1e-2L    , 0.0L , 0.0L  });
    REQUIRE(centimeter ::symbols   == quantity_symbols  { "cm"_us  , ""_us, ""_us });

    REQUIRE(decimeter  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(decimeter  ::factors   == quantity_factors  { 1e-1L    , 0.0L , 0.0L  });
    REQUIRE(decimeter  ::symbols   == quantity_symbols  { "dm"_us  , ""_us, ""_us });

    REQUIRE(meter      ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(meter      ::factors   == quantity_factors  { 1e0L     , 0.0L , 0.0L  });
    REQUIRE(meter      ::symbols   == quantity_symbols  { "m"_us   , ""_us, ""_us });

    REQUIRE(decameter  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(decameter  ::factors   == quantity_factors  { 1e1L     , 0.0L , 0.0L  });
    REQUIRE(decameter  ::symbols   == quantity_symbols  { "dam"_us , ""_us, ""_us });

    REQUIRE(hectometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(hectometer ::factors   == quantity_factors  { 1e2L     , 0.0L , 0.0L  });
    REQUIRE(hectometer ::symbols   == quantity_symbols  { "hm"_us  , ""_us, ""_us });

    REQUIRE(kilometer  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(kilometer  ::factors   == quantity_factors  { 1e3L     , 0.0L , 0.0L  });
    REQUIRE(kilometer  ::symbols   == quantity_symbols  { "km"_us  , ""_us, ""_us });

    REQUIRE(megameter  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(megameter  ::factors   == quantity_factors  { 1e6L     , 0.0L , 0.0L  });
    REQUIRE(megameter  ::symbols   == quantity_symbols  { "Mm"_us  , ""_us, ""_us });

    REQUIRE(gigameter  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(gigameter  ::factors   == quantity_factors  { 1e9L     , 0.0L , 0.0L  });
    REQUIRE(gigameter  ::symbols   == quantity_symbols  { "Gm"_us  , ""_us, ""_us });

    REQUIRE(terameter  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(terameter  ::factors   == quantity_factors  { 1e12L    , 0.0L , 0.0L  });
    REQUIRE(terameter  ::symbols   == quantity_symbols  { "Tm"_us  , ""_us, ""_us });

    REQUIRE(petameter  ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(petameter  ::factors   == quantity_factors  { 1e15L    , 0.0L , 0.0L  });
    REQUIRE(petameter  ::symbols   == quantity_symbols  { "Pm"_us  , ""_us, ""_us });

    REQUIRE(exameter   ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(exameter   ::factors   == quantity_factors  { 1e18L    , 0.0L , 0.0L  });
    REQUIRE(exameter   ::symbols   == quantity_symbols  { "Em"_us  , ""_us, ""_us });

    REQUIRE(zettameter ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(zettameter ::factors   == quantity_factors  { 1e21L    , 0.0L , 0.0L  });
    REQUIRE(zettameter ::symbols   == quantity_symbols  { "Zm"_us  , ""_us, ""_us });

    REQUIRE(yottameter ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(yottameter ::factors   == quantity_factors  { 1e24L    , 0.0L , 0.0L  });
    REQUIRE(yottameter ::symbols   == quantity_symbols  { "Ym"_us  , ""_us, ""_us });

    REQUIRE(ronnameter ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(ronnameter ::factors   == quantity_factors  { 1e27L    , 0.0L , 0.0L  });
    REQUIRE(ronnameter ::symbols   == quantity_symbols  { "Rm"_us  , ""_us, ""_us });

    REQUIRE(quettameter::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(quettameter::factors   == quantity_factors  { 1e30L    , 0.0L , 0.0L  });
    REQUIRE(quettameter::symbols   == quantity_symbols  { "Qm"_us  , ""_us, ""_us });

}
