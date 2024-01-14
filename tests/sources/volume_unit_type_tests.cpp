#include <catch2/catch_all.hpp>
#include <zollstock/volume_unit_types.hpp>


using namespace zollstock;


TEST_CASE("volume-unit-types", "[volume][unit][types]")
{

    REQUIRE(cubic_quektometer::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_quektometer::factors   == quantity_factors  { 1e-30L   , 0.0L , 0.0L  });
    REQUIRE(cubic_quektometer::symbols   == quantity_symbols  { "qm"_us  , ""_us, ""_us });

    REQUIRE(cubic_rontometer ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_rontometer ::factors   == quantity_factors  { 1e-27L   , 0.0L , 0.0L  });
    REQUIRE(cubic_rontometer ::symbols   == quantity_symbols  { "rm"_us  , ""_us, ""_us });

    REQUIRE(cubic_yoktometer ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_yoktometer ::factors   == quantity_factors  { 1e-24L   , 0.0L , 0.0L  });
    REQUIRE(cubic_yoktometer ::symbols   == quantity_symbols  { "ym"_us  , ""_us, ""_us });

    REQUIRE(cubic_zeptometer ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_zeptometer ::factors   == quantity_factors  { 1e-21L   , 0.0L , 0.0L  });
    REQUIRE(cubic_zeptometer ::symbols   == quantity_symbols  { "zm"_us  , ""_us, ""_us });

    REQUIRE(cubic_attometer  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_attometer  ::factors   == quantity_factors  { 1e-18L   , 0.0L , 0.0L  });
    REQUIRE(cubic_attometer  ::symbols   == quantity_symbols  { "am"_us  , ""_us, ""_us });

    REQUIRE(cubic_femtometer ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_femtometer ::factors   == quantity_factors  { 1e-15L   , 0.0L , 0.0L  });
    REQUIRE(cubic_femtometer ::symbols   == quantity_symbols  { "fm"_us  , ""_us, ""_us });

    REQUIRE(cubic_picometer  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_picometer  ::factors   == quantity_factors  { 1e-12L   , 0.0L , 0.0L  });
    REQUIRE(cubic_picometer  ::symbols   == quantity_symbols  { "pm"_us  , ""_us, ""_us });

    REQUIRE(cubic_nanometer  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_nanometer  ::factors   == quantity_factors  { 1e-9L    , 0.0L , 0.0L  });
    REQUIRE(cubic_nanometer  ::symbols   == quantity_symbols  { "nm"_us  , ""_us, ""_us });

    REQUIRE(cubic_micrometer ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_micrometer ::factors   == quantity_factors  { 1e-6L    , 0.0L , 0.0L  });
    REQUIRE(cubic_micrometer ::symbols   == quantity_symbols  { "micm"_us, ""_us, ""_us });

    REQUIRE(cubic_millimeter ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_millimeter ::factors   == quantity_factors  { 1e-3L    , 0.0L , 0.0L  });
    REQUIRE(cubic_millimeter ::symbols   == quantity_symbols  { "mm"_us  , ""_us, ""_us });

    REQUIRE(cubic_centimeter ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_centimeter ::factors   == quantity_factors  { 1e-2L    , 0.0L , 0.0L  });
    REQUIRE(cubic_centimeter ::symbols   == quantity_symbols  { "cm"_us  , ""_us, ""_us });

    REQUIRE(cubic_decimeter  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_decimeter  ::factors   == quantity_factors  { 1e-1L    , 0.0L , 0.0L  });
    REQUIRE(cubic_decimeter  ::symbols   == quantity_symbols  { "dm"_us  , ""_us, ""_us });

    REQUIRE(cubic_meter      ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_meter      ::factors   == quantity_factors  { 1e0L     , 0.0L , 0.0L  });
    REQUIRE(cubic_meter      ::symbols   == quantity_symbols  { "m"_us   , ""_us, ""_us });

    REQUIRE(cubic_decameter  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_decameter  ::factors   == quantity_factors  { 1e1L     , 0.0L , 0.0L  });
    REQUIRE(cubic_decameter  ::symbols   == quantity_symbols  { "dam"_us , ""_us, ""_us });

    REQUIRE(cubic_hectometer ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_hectometer ::factors   == quantity_factors  { 1e2L     , 0.0L , 0.0L  });
    REQUIRE(cubic_hectometer ::symbols   == quantity_symbols  { "hm"_us  , ""_us, ""_us });

    REQUIRE(cubic_kilometer  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_kilometer  ::factors   == quantity_factors  { 1e3L     , 0.0L , 0.0L  });
    REQUIRE(cubic_kilometer  ::symbols   == quantity_symbols  { "km"_us  , ""_us, ""_us });

    REQUIRE(cubic_megameter  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_megameter  ::factors   == quantity_factors  { 1e6L     , 0.0L , 0.0L  });
    REQUIRE(cubic_megameter  ::symbols   == quantity_symbols  { "Mm"_us  , ""_us, ""_us });

    REQUIRE(cubic_gigameter  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_gigameter  ::factors   == quantity_factors  { 1e9L     , 0.0L , 0.0L  });
    REQUIRE(cubic_gigameter  ::symbols   == quantity_symbols  { "Gm"_us  , ""_us, ""_us });

    REQUIRE(cubic_terameter  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_terameter  ::factors   == quantity_factors  { 1e12L    , 0.0L , 0.0L  });
    REQUIRE(cubic_terameter  ::symbols   == quantity_symbols  { "Tm"_us  , ""_us, ""_us });

    REQUIRE(cubic_petameter  ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_petameter  ::factors   == quantity_factors  { 1e15L    , 0.0L , 0.0L  });
    REQUIRE(cubic_petameter  ::symbols   == quantity_symbols  { "Pm"_us  , ""_us, ""_us });

    REQUIRE(cubic_exameter   ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_exameter   ::factors   == quantity_factors  { 1e18L    , 0.0L , 0.0L  });
    REQUIRE(cubic_exameter   ::symbols   == quantity_symbols  { "Em"_us  , ""_us, ""_us });

    REQUIRE(cubic_zettameter ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_zettameter ::factors   == quantity_factors  { 1e21L    , 0.0L , 0.0L  });
    REQUIRE(cubic_zettameter ::symbols   == quantity_symbols  { "Zm"_us  , ""_us, ""_us });

    REQUIRE(cubic_yottameter ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_yottameter ::factors   == quantity_factors  { 1e24L    , 0.0L , 0.0L  });
    REQUIRE(cubic_yottameter ::symbols   == quantity_symbols  { "Ym"_us  , ""_us, ""_us });

    REQUIRE(cubic_ronnameter ::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_ronnameter ::factors   == quantity_factors  { 1e27L    , 0.0L , 0.0L  });
    REQUIRE(cubic_ronnameter ::symbols   == quantity_symbols  { "Rm"_us  , ""_us, ""_us });

    REQUIRE(cubic_quettameter::exponents == quantity_exponents{ 3        , 0    , 0     });
    REQUIRE(cubic_quettameter::factors   == quantity_factors  { 1e30L    , 0.0L , 0.0L  });
    REQUIRE(cubic_quettameter::symbols   == quantity_symbols  { "Qm"_us  , ""_us, ""_us });

}
