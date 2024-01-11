#include <catch2/catch_all.hpp>
#include <zollstock/length_unit_constants.hpp>
#include <zollstock/length_unit_literals.hpp>


using namespace zollstock;


TEST_CASE("length-unit-literals", "[length][unit][literals]")
{

    REQUIRE(1.0_qm   == 1.0 * qm  );
    REQUIRE(1_qm     == 1.0 * qm  );

    REQUIRE(1.0_rm   == 1.0 * rm  );
    REQUIRE(1_rm     == 1.0 * rm  );

    REQUIRE(1.0_ym   == 1.0 * ym  );
    REQUIRE(1_ym     == 1.0 * ym  );

    REQUIRE(1.0_zm   == 1.0 * zm  );
    REQUIRE(1_zm     == 1.0 * zm  );

    REQUIRE(1.0_am   == 1.0 * am  );
    REQUIRE(1_am     == 1.0 * am  );

    REQUIRE(1.0_fm   == 1.0 * fm  );
    REQUIRE(1_fm     == 1.0 * fm  );

    REQUIRE(1.0_pm   == 1.0 * pm  );
    REQUIRE(1_pm     == 1.0 * pm  );

    REQUIRE(1.0_nm   == 1.0 * nm  );
    REQUIRE(1_nm     == 1.0 * nm  );

    REQUIRE(1.0_micm == 1.0 * micm);
    REQUIRE(1_micm   == 1.0 * micm);

    REQUIRE(1.0_mm   == 1.0 * mm  );
    REQUIRE(1_mm     == 1.0 * mm  );

    REQUIRE(1.0_cm   == 1.0 * cm  );
    REQUIRE(1_cm     == 1.0 * cm  );

    REQUIRE(1.0_dm   == 1.0 * dm  );
    REQUIRE(1_dm     == 1.0 * dm  );

    REQUIRE(1.0_m    == 1.0 * m   );
    REQUIRE(1_m      == 1.0 * m   );

    REQUIRE(1.0_dam  == 1.0 * dam );
    REQUIRE(1_dam    == 1.0 * dam );

    REQUIRE(1.0_hm   == 1.0 * hm  );
    REQUIRE(1_hm     == 1.0 * hm  );

    REQUIRE(1.0_km   == 1.0 * km  );
    REQUIRE(1_km     == 1.0 * km  );

    REQUIRE(1.0_Mm   == 1.0 * Mm  );
    REQUIRE(1_Mm     == 1.0 * Mm  );

    REQUIRE(1.0_Gm   == 1.0 * Gm  );
    REQUIRE(1_Gm     == 1.0 * Gm  );

    REQUIRE(1.0_Tm   == 1.0 * Tm  );
    REQUIRE(1_Tm     == 1.0 * Tm  );

    REQUIRE(1.0_Pm   == 1.0 * Pm  );
    REQUIRE(1_Pm     == 1.0 * Pm  );

    REQUIRE(1.0_Em   == 1.0 * Em  );
    REQUIRE(1_Em     == 1.0 * Em  );

    REQUIRE(1.0_Zm   == 1.0 * Zm  );
    REQUIRE(1_Zm     == 1.0 * Zm  );

    REQUIRE(1.0_Ym   == 1.0 * Ym  );
    REQUIRE(1_Ym     == 1.0 * Ym  );

    REQUIRE(1.0_Rm   == 1.0 * Rm  );
    REQUIRE(1_Rm     == 1.0 * Rm  );

    REQUIRE(1.0_Qm   == 1.0 * Qm  );
    REQUIRE(1_Qm     == 1.0 * Qm  );

}
