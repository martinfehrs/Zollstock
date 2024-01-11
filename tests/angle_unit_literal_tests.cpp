#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/angle_unit_literals.hpp>


using namespace zollstock;


TEST_CASE("angle-unit-literals", "[angle][unit][literals]")
{

    REQUIRE(1.0_prad   == 1.0 * prad  );
    REQUIRE(1_prad     == 1.0 * prad  );

    REQUIRE(1.0_nrad   == 1.0 * nrad  );
    REQUIRE(1_nrad     == 1.0 * nrad  );

    REQUIRE(1.0_micrad == 1.0 * micrad);
    REQUIRE(1_micrad   == 1.0 * micrad);

    REQUIRE(1.0_mrad   == 1.0 * mrad  );
    REQUIRE(1_mrad     == 1.0 * mrad  );

    REQUIRE(1.0_crad   == 1.0 * crad  );
    REQUIRE(1_crad     == 1.0 * crad  );

    REQUIRE(1.0_drad   == 1.0 * drad  );
    REQUIRE(1_drad     == 1.0 * drad  );

    REQUIRE(1.0_rad    == 1.0 * rad   );
    REQUIRE(1_rad      == 1.0 * rad   );

    REQUIRE(1.0_darad  == 1.0 * darad );
    REQUIRE(1_darad    == 1.0 * darad );

    REQUIRE(1.0_hrad   == 1.0 * hrad  );
    REQUIRE(1_hrad     == 1.0 * hrad  );

    REQUIRE(1.0_krad   == 1.0 * krad  );
    REQUIRE(1_krad     == 1.0 * krad  );

    REQUIRE(1.0_Mrad   == 1.0 * Mrad  );
    REQUIRE(1_Mrad     == 1.0 * Mrad  );

    REQUIRE(1.0_Grad   == 1.0 * Grad  );
    REQUIRE(1_Grad     == 1.0 * Grad  );

    REQUIRE(1.0_Trad   == 1.0 * Trad  );
    REQUIRE(1_Trad     == 1.0 * Trad  );

    REQUIRE(1.0_Prad   == 1.0 * Prad  );
    REQUIRE(1_Prad     == 1.0 * Prad  );

    REQUIRE(1.0_Erad   == 1.0 * Erad  );
    REQUIRE(1_Erad     == 1.0 * Erad  );

    REQUIRE(1.0_Zrad   == 1.0 * Zrad  );
    REQUIRE(1_Zrad     == 1.0 * Zrad  );

    REQUIRE(1.0_Yrad   == 1.0 * Yrad  );
    REQUIRE(1_Yrad     == 1.0 * Yrad  );

    REQUIRE(1.0_Rrad   == 1.0 * Rrad  );
    REQUIRE(1_Rrad     == 1.0 * Rrad  );

    REQUIRE(1.0_Qrad   == 1.0 * Qrad  );
    REQUIRE(1_Qrad     == 1.0 * Qrad  );


    REQUIRE(1.0_deg    == 1.0 * deg   );
    REQUIRE(1_deg      == 1.0 * deg   );


    REQUIRE(1.0_arcmin == 1.0 * arcmin);
    REQUIRE(1_arcmin   == 1.0 * arcmin);


    REQUIRE(1.0_arcsec == 1.0 * arcsec);
    REQUIRE(1_arcsec   == 1.0 * arcsec);

    REQUIRE(1.0_mas    == 1.0 * mas   );
    REQUIRE(1_mas      == 1.0 * mas   );

    REQUIRE(1.0_micas  == 1.0 * micas );
    REQUIRE(1_micas    == 1.0 * micas );


    REQUIRE(1.0_qgon   == 1.0 * qgon  );
    REQUIRE(1_qgon     == 1.0 * qgon  );

    REQUIRE(1.0_rgon   == 1.0 * rgon  );
    REQUIRE(1_rgon     == 1.0 * rgon  );

    REQUIRE(1.0_ygon   == 1.0 * ygon  );
    REQUIRE(1_ygon     == 1.0 * ygon  );

    REQUIRE(1.0_zgon   == 1.0 * zgon  );
    REQUIRE(1_zgon     == 1.0 * zgon  );

    REQUIRE(1.0_agon   == 1.0 * agon  );
    REQUIRE(1_agon     == 1.0 * agon  );

    REQUIRE(1.0_fgon   == 1.0 * fgon  );
    REQUIRE(1_fgon     == 1.0 * fgon  );

    REQUIRE(1.0_pgon   == 1.0 * pgon  );
    REQUIRE(1_pgon     == 1.0 * pgon  );

    REQUIRE(1.0_ngon   == 1.0 * ngon  );
    REQUIRE(1_ngon     == 1.0 * ngon  );

    REQUIRE(1.0_micgon == 1.0 * micgon);
    REQUIRE(1_micgon   == 1.0 * micgon);

    REQUIRE(1.0_mgon   == 1.0 * mgon  );
    REQUIRE(1_mgon     == 1.0 * mgon  );

    REQUIRE(1.0_cgon   == 1.0 * cgon  );
    REQUIRE(1_cgon     == 1.0 * cgon  );

    REQUIRE(1.0_dgon   == 1.0 * dgon  );
    REQUIRE(1_dgon     == 1.0 * dgon  );

    REQUIRE(1.0_gon    == 1.0 * gon   );
    REQUIRE(1_gon      == 1.0 * gon   );

    REQUIRE(1.0_dagon  == 1.0 * dagon );
    REQUIRE(1_dagon    == 1.0 * dagon );

    REQUIRE(1.0_hgon   == 1.0 * hgon  );
    REQUIRE(1_hgon     == 1.0 * hgon  );

    REQUIRE(1.0_kgon   == 1.0 * kgon  );
    REQUIRE(1_kgon     == 1.0 * kgon  );

    REQUIRE(1.0_Mgon   == 1.0 * Mgon  );
    REQUIRE(1_Mgon     == 1.0 * Mgon  );

    REQUIRE(1.0_Ggon   == 1.0 * Ggon  );
    REQUIRE(1_Ggon     == 1.0 * Ggon  );

    REQUIRE(1.0_Tgon   == 1.0 * Tgon  );
    REQUIRE(1_Tgon     == 1.0 * Tgon  );

    REQUIRE(1.0_Pgon   == 1.0 * Pgon  );
    REQUIRE(1_Pgon     == 1.0 * Pgon  );

    REQUIRE(1.0_Egon   == 1.0 * Egon  );
    REQUIRE(1_Egon     == 1.0 * Egon  );

    REQUIRE(1.0_Zgon   == 1.0 * Zgon  );
    REQUIRE(1_Zgon     == 1.0 * Zgon  );

    REQUIRE(1.0_Ygon   == 1.0 * Ygon  );
    REQUIRE(1_Ygon     == 1.0 * Ygon  );

    REQUIRE(1.0_Rgon   == 1.0 * Rgon  );
    REQUIRE(1_Rgon     == 1.0 * Rgon  );

    REQUIRE(1.0_Qgon   == 1.0 * Qgon  );
    REQUIRE(1_Qgon     == 1.0 * Qgon  );

}
