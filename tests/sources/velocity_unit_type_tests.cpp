#include <catch2/catch_all.hpp>
#include <zollstock/velocity_unit_types.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("velocity-unit-types", "[velocity][unit][types]")
{

    REQUIRE(centimeter_per_second::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(centimeter_per_second::factors   == quantity_factors  { 1e-2L   , 1e0L    , 0.0L  });
    REQUIRE(centimeter_per_second::symbols   == quantity_symbols  { "cm"_us , "s"_us  , ""_us });

    REQUIRE(centimeter_per_minute::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(centimeter_per_minute::factors   == quantity_factors  { 1e-2L   , 60.0L   , 0.0L  });
    REQUIRE(centimeter_per_minute::symbols   == quantity_symbols  { "cm"_us , "min"_us, ""_us });

    REQUIRE(centimeter_per_hour  ::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(centimeter_per_hour  ::factors   == quantity_factors  { 1e-2L   , 3600.0L , 0.0L  });
    REQUIRE(centimeter_per_hour  ::symbols   == quantity_symbols  { "cm"_us , "h"_us  , ""_us });

    REQUIRE(decimeter_per_second ::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(decimeter_per_second ::factors   == quantity_factors  { 1e-1L   , 1e0L    , 0.0L  });
    REQUIRE(decimeter_per_second ::symbols   == quantity_symbols  { "dm"_us , "s"_us  , ""_us });

    REQUIRE(decimeter_per_minute ::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(decimeter_per_minute ::factors   == quantity_factors  { 1e-1L   , 60.0L   , 0.0L  });
    REQUIRE(decimeter_per_minute ::symbols   == quantity_symbols  { "dm"_us , "min"_us, ""_us });

    REQUIRE(decimeter_per_hour   ::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(decimeter_per_hour   ::factors   == quantity_factors  { 1e-1L   , 3600.0L , 0.0L  });
    REQUIRE(decimeter_per_hour   ::symbols   == quantity_symbols  { "dm"_us , "h"_us  , ""_us });

    REQUIRE(meter_per_second     ::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(meter_per_second     ::factors   == quantity_factors  { 1e0L    , 1e0L    , 0.0L  });
    REQUIRE(meter_per_second     ::symbols   == quantity_symbols  { "m"_us  , "s"_us  , ""_us });

    REQUIRE(meter_per_minute     ::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(meter_per_minute     ::factors   == quantity_factors  { 1e0L    , 60.0L   , 0.0L  });
    REQUIRE(meter_per_minute     ::symbols   == quantity_symbols  { "m"_us  , "min"_us, ""_us });

    REQUIRE(meter_per_hour       ::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(meter_per_hour       ::factors   == quantity_factors  { 1e0L    , 3600.0L , 0.0L  });
    REQUIRE(meter_per_hour       ::symbols   == quantity_symbols  { "m"_us  , "h"_us  , ""_us });

    REQUIRE(decameter_per_second ::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(decameter_per_second ::factors   == quantity_factors  { 1e1L    , 1e0L    , 0.0L  });
    REQUIRE(decameter_per_second ::symbols   == quantity_symbols  { "dam"_us, "s"_us  , ""_us });

    REQUIRE(decameter_per_minute ::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(decameter_per_minute ::factors   == quantity_factors  { 1e1L    , 60.0L   , 0.0L  });
    REQUIRE(decameter_per_minute ::symbols   == quantity_symbols  { "dam"_us, "min"_us, ""_us });

    REQUIRE(decameter_per_hour   ::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(decameter_per_hour   ::factors   == quantity_factors  { 1e1L    , 3600.0L , 0.0L  });
    REQUIRE(decameter_per_hour   ::symbols   == quantity_symbols  { "dam"_us, "h"_us  , ""_us });

    REQUIRE(hectometer_per_second::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(hectometer_per_second::factors   == quantity_factors  { 1e2L    , 1e0L    , 0.0L  });
    REQUIRE(hectometer_per_second::symbols   == quantity_symbols  { "hm"_us , "s"_us  , ""_us });

    REQUIRE(hectometer_per_minute::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(hectometer_per_minute::factors   == quantity_factors  { 1e2L    , 60.0L   , 0.0L  });
    REQUIRE(hectometer_per_minute::symbols   == quantity_symbols  { "hm"_us , "min"_us, ""_us });

    REQUIRE(hectometer_per_hour  ::exponents == quantity_exponents{ 1       , -1      , 0     });
    REQUIRE(hectometer_per_hour  ::factors   == quantity_factors  { 1e2L    , 3600.0L , 0.0L  });
    REQUIRE(hectometer_per_hour  ::symbols   == quantity_symbols  { "hm"_us , "h"_us  , ""_us });

    REQUIRE(kilometer_per_second ::exponents == quantity_exponents{ 1       , -1     , 0      });
    REQUIRE(kilometer_per_second ::factors   == quantity_factors  { 1e3L    , 1e0L   , 0.0L   });
    REQUIRE(kilometer_per_second ::symbols   == quantity_symbols  { "km"_us , "s"_us , ""_us  });

    REQUIRE(kilometer_per_minute::exponents == quantity_exponents{ 1        , -1      , 0     });
    REQUIRE(kilometer_per_minute::factors   == quantity_factors  { 1e3L     , 60.0L   , 0.0L  });
    REQUIRE(kilometer_per_minute::symbols   == quantity_symbols  { "km"_us  , "min"_us, ""_us });

    REQUIRE(kilometer_per_hour  ::exponents == quantity_exponents{ 1        , -1      , 0     });
    REQUIRE(kilometer_per_hour  ::factors   == quantity_factors  { 1e3L     , 3600.0L , 0.0L  });
    REQUIRE(kilometer_per_hour  ::symbols   == quantity_symbols  { "km"_us  , "h"_us  , ""_us });

}
