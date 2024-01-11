#include <catch2/catch_all.hpp>
#include <zollstock/area_unit_constants.hpp>
#include <zollstock/area_unit_literals.hpp>


using namespace zollstock;


TEST_CASE("area-unit-literals", "[area][unit][literals]")
{

    REQUIRE(1.0_qm2   == 1.0 * qm2  );
    REQUIRE(1_qm2     == 1.0 * qm2  );

    REQUIRE(1.0_rm2   == 1.0 * rm2  );
    REQUIRE(1_rm2     == 1.0 * rm2  );

    REQUIRE(1.0_ym2   == 1.0 * ym2  );
    REQUIRE(1_ym2     == 1.0 * ym2  );

    REQUIRE(1.0_zm2   == 1.0 * zm2  );
    REQUIRE(1_zm2     == 1.0 * zm2  );

    REQUIRE(1.0_am2   == 1.0 * am2  );
    REQUIRE(1_am2     == 1.0 * am2  );

    REQUIRE(1.0_fm2   == 1.0 * fm2  );
    REQUIRE(1_fm2     == 1.0 * fm2  );

    REQUIRE(1.0_pm2   == 1.0 * pm2  );
    REQUIRE(1_pm2     == 1.0 * pm2  );

    REQUIRE(1.0_nm2   == 1.0 * nm2  );
    REQUIRE(1_nm2     == 1.0 * nm2  );

    REQUIRE(1.0_micm2 == 1.0 * micm2);
    REQUIRE(1_micm2   == 1.0 * micm2);

    REQUIRE(1.0_mm2   == 1.0 * mm2  );
    REQUIRE(1_mm2     == 1.0 * mm2  );

    REQUIRE(1.0_cm2   == 1.0 * cm2  );
    REQUIRE(1_cm2     == 1.0 * cm2  );

    REQUIRE(1.0_dm2   == 1.0 * dm2  );
    REQUIRE(1_dm2     == 1.0 * dm2  );

    REQUIRE(1.0_m2    == 1.0 * m2   );
    REQUIRE(1_m2      == 1.0 * m2   );

    REQUIRE(1.0_dam2  == 1.0 * dam2 );
    REQUIRE(1_dam2    == 1.0 * dam2 );

    REQUIRE(1.0_hm2   == 1.0 * hm2  );
    REQUIRE(1_hm2     == 1.0 * hm2  );

    REQUIRE(1.0_km2   == 1.0 * km2  );
    REQUIRE(1_km2     == 1.0 * km2  );

    REQUIRE(1.0_Mm2   == 1.0 * Mm2  );
    REQUIRE(1_Mm2     == 1.0 * Mm2  );

    REQUIRE(1.0_Gm2   == 1.0 * Gm2  );
    REQUIRE(1_Gm2     == 1.0 * Gm2  );

    REQUIRE(1.0_Tm2   == 1.0 * Tm2  );
    REQUIRE(1_Tm2     == 1.0 * Tm2  );

    REQUIRE(1.0_Pm2   == 1.0 * Pm2  );
    REQUIRE(1_Pm2     == 1.0 * Pm2  );

    REQUIRE(1.0_Em2   == 1.0 * Em2  );
    REQUIRE(1_Em2     == 1.0 * Em2  );

    REQUIRE(1.0_Zm2   == 1.0 * Zm2  );
    REQUIRE(1_Zm2     == 1.0 * Zm2  );

    REQUIRE(1.0_Ym2   == 1.0 * Ym2  );
    REQUIRE(1_Ym2     == 1.0 * Ym2  );

    REQUIRE(1.0_Rm2   == 1.0 * Rm2  );
    REQUIRE(1_Rm2     == 1.0 * Rm2  );

    REQUIRE(1.0_Qm2   == 1.0 * Qm2  );
    REQUIRE(1_Qm2     == 1.0 * Qm2  );

}
