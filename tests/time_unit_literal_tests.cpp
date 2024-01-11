#include <catch2/catch_all.hpp>
#include <zollstock/time_unit_constants.hpp>
#include <zollstock/time_unit_literals.hpp>


using namespace zollstock;


TEST_CASE("time-unit-literals", "[time][unit][literals]")
{

    REQUIRE(1.0_qs   == 1.0 * qs  );
    REQUIRE(1_qs     == 1.0 * qs  );

    REQUIRE(1.0_rs   == 1.0 * rs  );
    REQUIRE(1_rs     == 1.0 * rs  );

    REQUIRE(1.0_ys   == 1.0 * ys  );
    REQUIRE(1_ys     == 1.0 * ys  );

    REQUIRE(1.0_zs   == 1.0 * zs  );
    REQUIRE(1_zs     == 1.0 * zs  );

    REQUIRE(1.0_as   == 1.0 * as  );
    REQUIRE(1_as     == 1.0 * as  );

    REQUIRE(1.0_fs   == 1.0 * fs  );
    REQUIRE(1_fs     == 1.0 * fs  );

    REQUIRE(1.0_ps   == 1.0 * ps  );
    REQUIRE(1_ps     == 1.0 * ps  );

    REQUIRE(1.0_ns   == 1.0 * ns  );
    REQUIRE(1_ns     == 1.0 * ns  );

    REQUIRE(1.0_mics == 1.0 * mics);
    REQUIRE(1_mics   == 1.0 * mics);

    REQUIRE(1.0_ms   == 1.0 * ms  );
    REQUIRE(1_ms     == 1.0 * ms  );

    REQUIRE(1.0_cs   == 1.0 * cs   );
    REQUIRE(1_cs     == 1.0 * cs  );

    REQUIRE(1.0_ds   == 1.0 * ds  );
    REQUIRE(1_ds     == 1.0 * ds  );

    REQUIRE(1.0_s    == 1.0 * s   );
    REQUIRE(1_s      == 1.0 * s   );

    REQUIRE(1.0_das  == 1.0 * das );
    REQUIRE(1_das    == 1.0 * das );

    REQUIRE(1.0_hs   == 1.0 * hs  );
    REQUIRE(1_hs     == 1.0 * hs  );

    REQUIRE(1.0_ks   == 1.0 * ks  );
    REQUIRE(1_ks     == 1.0 * ks  );

    REQUIRE(1.0_Ms   == 1.0 * Ms  );
    REQUIRE(1_Ms     == 1.0 * Ms  );

    REQUIRE(1.0_Gs   == 1.0 * Gs  );
    REQUIRE(1_Gs     == 1.0 * Gs  );

    REQUIRE(1.0_Ts   == 1.0 * Ts  );
    REQUIRE(1_Ts     == 1.0 * Ts  );

    REQUIRE(1.0_Ps   == 1.0 * Ps  );
    REQUIRE(1_Ps     == 1.0 * Ps  );

    REQUIRE(1.0_Es   == 1.0 * Es  );
    REQUIRE(1_Es     == 1.0 * Es  );

    REQUIRE(1.0_Zs   == 1.0 * Zs  );
    REQUIRE(1_Zs     == 1.0 * Zs  );

    REQUIRE(1.0_Ys   == 1.0 * Ys  );
    REQUIRE(1_Ys     == 1.0 * Ys  );

    REQUIRE(1.0_Rs   == 1.0 * Rs  );
    REQUIRE(1_Rs     == 1.0 * Rs  );

    REQUIRE(1.0_Qs   == 1.0 * Qs  );
    REQUIRE(1_Qs     == 1.0 * Qs  );

}
