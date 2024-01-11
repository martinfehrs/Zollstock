#include <catch2/catch_all.hpp>
#include <zollstock/volume_unit_constants.hpp>
#include <zollstock/volume_unit_literals.hpp>


using namespace zollstock;


TEST_CASE("volume-unit-literals", "[volume][unit][literals]")
{

    REQUIRE(1.0_qm3   == 1.0 * qm3  );
    REQUIRE(1_qm3     == 1.0 * qm3  );

    REQUIRE(1.0_rm3   == 1.0 * rm3  );
    REQUIRE(1_rm3     == 1.0 * rm3  );

    REQUIRE(1.0_ym3   == 1.0 * ym3  );
    REQUIRE(1_ym3     == 1.0 * ym3  );

    REQUIRE(1.0_zm3   == 1.0 * zm3  );
    REQUIRE(1_zm3     == 1.0 * zm3  );

    REQUIRE(1.0_am3   == 1.0 * am3  );
    REQUIRE(1_am3     == 1.0 * am3  );

    REQUIRE(1.0_fm3   == 1.0 * fm3  );
    REQUIRE(1_fm3     == 1.0 * fm3  );

    REQUIRE(1.0_pm3   == 1.0 * pm3  );
    REQUIRE(1_pm3     == 1.0 * pm3  );

    REQUIRE(1.0_nm3   == 1.0 * nm3  );
    REQUIRE(1_nm3     == 1.0 * nm3  );

    REQUIRE(1.0_micm3 == 1.0 * micm3);
    REQUIRE(1_micm3   == 1.0 * micm3);

    REQUIRE(1.0_mm3   == 1.0 * mm3  );
    REQUIRE(1_mm3     == 1.0 * mm3  );

    REQUIRE(1.0_cm3   == 1.0 * cm3  );
    REQUIRE(1_cm3     == 1.0 * cm3  );

    REQUIRE(1.0_dm3   == 1.0 * dm3  );
    REQUIRE(1_dm3     == 1.0 * dm3  );

    REQUIRE(1.0_m3    == 1.0 * m3   );
    REQUIRE(1_m3      == 1.0 * m3   );

    REQUIRE(1.0_dam3  == 1.0 * dam3 );
    REQUIRE(1_dam3    == 1.0 * dam3 );

    REQUIRE(1.0_hm3   == 1.0 * hm3  );
    REQUIRE(1_hm3     == 1.0 * hm3  );

    REQUIRE(1.0_km3   == 1.0 * km3  );
    REQUIRE(1_km3     == 1.0 * km3  );

    REQUIRE(1.0_Mm3   == 1.0 * Mm3  );
    REQUIRE(1_Mm3     == 1.0 * Mm3  );

    REQUIRE(1.0_Gm3   == 1.0 * Gm3  );
    REQUIRE(1_Gm3     == 1.0 * Gm3  );

    REQUIRE(1.0_Tm3   == 1.0 * Tm3  );
    REQUIRE(1_Tm3     == 1.0 * Tm3  );

    REQUIRE(1.0_Pm3   == 1.0 * Pm3  );
    REQUIRE(1_Pm3     == 1.0 * Pm3  );

    REQUIRE(1.0_Em3   == 1.0 * Em3  );
    REQUIRE(1_Em3     == 1.0 * Em3  );

    REQUIRE(1.0_Zm3   == 1.0 * Zm3  );
    REQUIRE(1_Zm3     == 1.0 * Zm3  );

    REQUIRE(1.0_Ym3   == 1.0 * Ym3  );
    REQUIRE(1_Ym3     == 1.0 * Ym3  );

    REQUIRE(1.0_Rm3   == 1.0 * Rm3  );
    REQUIRE(1_Rm3     == 1.0 * Rm3  );

    REQUIRE(1.0_Qm3   == 1.0 * Qm3  );
    REQUIRE(1_Qm3     == 1.0 * Qm3  );

}
