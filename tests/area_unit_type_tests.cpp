#include <catch2/catch_all.hpp>
#include <zollstock/area_unit_types.hpp>


using namespace zollstock;


TEST_CASE("area-unit-types", "[area][unit][types]")
{

    REQUIRE(square_quektometer::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_quektometer::factors   == quantity_factors  { 1e-30L   , 0.0L , 0.0L  });
    REQUIRE(square_quektometer::symbols   == quantity_symbols  { "qm"_us  , ""_us, ""_us });

    REQUIRE(square_rontometer ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_rontometer ::factors   == quantity_factors  { 1e-27L   , 0.0L , 0.0L  });
    REQUIRE(square_rontometer ::symbols   == quantity_symbols  { "rm"_us  , ""_us, ""_us });

    REQUIRE(square_yoktometer ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_yoktometer ::factors   == quantity_factors  { 1e-24L   , 0.0L , 0.0L  });
    REQUIRE(square_yoktometer ::symbols   == quantity_symbols  { "ym"_us  , ""_us, ""_us });

    REQUIRE(square_zeptometer ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_zeptometer ::factors   == quantity_factors  { 1e-21L   , 0.0L , 0.0L  });
    REQUIRE(square_zeptometer ::symbols   == quantity_symbols  { "zm"_us  , ""_us, ""_us });

    REQUIRE(square_attometer  ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_attometer  ::factors   == quantity_factors  { 1e-18L   , 0.0L , 0.0L  });
    REQUIRE(square_attometer  ::symbols   == quantity_symbols  { "am"_us  , ""_us, ""_us });

    REQUIRE(square_femtometer ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_femtometer ::factors   == quantity_factors  { 1e-15L   , 0.0L , 0.0L  });
    REQUIRE(square_femtometer ::symbols   == quantity_symbols  { "fm"_us  , ""_us, ""_us });

    REQUIRE(square_picometer  ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_picometer  ::factors   == quantity_factors  { 1e-12L   , 0.0L , 0.0L  });
    REQUIRE(square_picometer  ::symbols   == quantity_symbols  { "pm"_us  , ""_us, ""_us });

    REQUIRE(square_nanometer  ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_nanometer  ::factors   == quantity_factors  { 1e-9L    , 0.0L , 0.0L  });
    REQUIRE(square_nanometer  ::symbols   == quantity_symbols  { "nm"_us  , ""_us, ""_us });

    REQUIRE(square_micrometer ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_micrometer ::factors   == quantity_factors  { 1e-6L    , 0.0L , 0.0L  });
    REQUIRE(square_micrometer ::symbols   == quantity_symbols  { "micm"_us, ""_us, ""_us });

    REQUIRE(square_millimeter ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_millimeter ::factors   == quantity_factors  { 1e-3L    , 0.0L , 0.0L  });
    REQUIRE(square_millimeter ::symbols   == quantity_symbols  { "mm"_us  , ""_us, ""_us });

    REQUIRE(square_centimeter ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_centimeter ::factors   == quantity_factors  { 1e-2L    , 0.0L , 0.0L  });
    REQUIRE(square_centimeter ::symbols   == quantity_symbols  { "cm"_us  , ""_us, ""_us });

    REQUIRE(square_decimeter  ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_decimeter  ::factors   == quantity_factors  { 1e-1L    , 0.0L , 0.0L  });
    REQUIRE(square_decimeter  ::symbols   == quantity_symbols  { "dm"_us  , ""_us, ""_us });

    REQUIRE(square_meter      ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_meter      ::factors   == quantity_factors  { 1e0L     , 0.0L , 0.0L  });
    REQUIRE(square_meter      ::symbols   == quantity_symbols  { "m"_us   , ""_us, ""_us });

    REQUIRE(square_decameter  ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_decameter  ::factors   == quantity_factors  { 1e1L     , 0.0L , 0.0L  });
    REQUIRE(square_decameter  ::symbols   == quantity_symbols  { "dam"_us , ""_us, ""_us });

    REQUIRE(square_hectometer ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_hectometer ::factors   == quantity_factors  { 1e2L     , 0.0L , 0.0L  });
    REQUIRE(square_hectometer ::symbols   == quantity_symbols  { "hm"_us  , ""_us, ""_us });

    REQUIRE(square_kilometer  ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_kilometer  ::factors   == quantity_factors  { 1e3L     , 0.0L , 0.0L  });
    REQUIRE(square_kilometer  ::symbols   == quantity_symbols  { "km"_us  , ""_us, ""_us });

    REQUIRE(square_megameter  ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_megameter  ::factors   == quantity_factors  { 1e6L     , 0.0L , 0.0L  });
    REQUIRE(square_megameter  ::symbols   == quantity_symbols  { "Mm"_us  , ""_us, ""_us });

    REQUIRE(square_gigameter  ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_gigameter  ::factors   == quantity_factors  { 1e9L     , 0.0L , 0.0L  });
    REQUIRE(square_gigameter  ::symbols   == quantity_symbols  { "Gm"_us  , ""_us, ""_us });

    REQUIRE(square_terameter  ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_terameter  ::factors   == quantity_factors  { 1e12L    , 0.0L , 0.0L  });
    REQUIRE(square_terameter  ::symbols   == quantity_symbols  { "Tm"_us  , ""_us, ""_us });

    REQUIRE(square_petameter  ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_petameter  ::factors   == quantity_factors  { 1e15L    , 0.0L , 0.0L  });
    REQUIRE(square_petameter  ::symbols   == quantity_symbols  { "Pm"_us  , ""_us, ""_us });

    REQUIRE(square_exameter   ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_exameter   ::factors   == quantity_factors  { 1e18L    , 0.0L , 0.0L  });
    REQUIRE(square_exameter   ::symbols   == quantity_symbols  { "Em"_us  , ""_us, ""_us });

    REQUIRE(square_zettameter ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_zettameter ::factors   == quantity_factors  { 1e21L    , 0.0L , 0.0L  });
    REQUIRE(square_zettameter ::symbols   == quantity_symbols  { "Zm"_us  , ""_us, ""_us });

    REQUIRE(square_yottameter ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_yottameter ::factors   == quantity_factors  { 1e24L    , 0.0L , 0.0L  });
    REQUIRE(square_yottameter ::symbols   == quantity_symbols  { "Ym"_us  , ""_us, ""_us });

    REQUIRE(square_ronnameter ::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_ronnameter ::factors   == quantity_factors  { 1e27L    , 0.0L , 0.0L  });
    REQUIRE(square_ronnameter ::symbols   == quantity_symbols  { "Rm"_us  , ""_us, ""_us });

    REQUIRE(square_quettameter::exponents == quantity_exponents{ 2        , 0    , 0     });
    REQUIRE(square_quettameter::factors   == quantity_factors  { 1e30L    , 0.0L , 0.0L  });
    REQUIRE(square_quettameter::symbols   == quantity_symbols  { "Qm"_us  , ""_us, ""_us });

}
