#include <catch2/catch_all.hpp>
#include <zollstock/length_units.hpp>


using namespace zollstock;


TEST_CASE( "length-unit-types", "[length-unit-types]" ) {

    auto unit = GENERATE(std::make_tuple( quektometer{}, 1, 1e-30L ));

    REQUIRE(quektometer::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(quektometer::factors   == quantity_factors  { 1e-30L   , 0.0L , 0.0L  });
    REQUIRE(quektometer::symbols   == quantity_symbols  { "qm"_us  , ""_us, ""_us });

    REQUIRE(rontometer ::exponents == quantity_exponents{ 1        , 0    , 0     });
    REQUIRE(rontometer ::factors   == quantity_factors  { 1e-27L   , 0.0L , 0.0L  });
    REQUIRE(rontometer ::symbols   == quantity_symbols  { "rm"_us  , ""_us, ""_us });

}
