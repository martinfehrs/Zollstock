#include <zollstock/angle_units.hpp>


namespace zollstock
{

    static_assert(picoradian ::exponents == quantity_exponents{ 0     , 0    , 1                 });
    static_assert(picoradian ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-12L            });
    static_assert(picoradian ::symbols   == quantity_symbols  { ""_us , ""_us, "prad"_us         });

    static_assert(nanoradian ::exponents == quantity_exponents{ 0     , 0    , 1                 });
    static_assert(nanoradian ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-9L             });
    static_assert(nanoradian ::symbols   == quantity_symbols  { ""_us , ""_us, "nrad"_us         });

    static_assert(microradian::exponents == quantity_exponents{ 0     , 0    , 1                 });
    static_assert(microradian::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-6L             });
    static_assert(microradian::symbols   == quantity_symbols  { ""_us , ""_us, "micrad"_us       });

    static_assert(milliradian::exponents == quantity_exponents{ 0     , 0    , 1                 });
    static_assert(milliradian::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-3L             });
    static_assert(milliradian::symbols   == quantity_symbols  { ""_us , ""_us, "mrad"_us         });

    static_assert(centiradian::exponents == quantity_exponents{ 0     , 0    , 1                 });
    static_assert(centiradian::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-2L             });
    static_assert(centiradian::symbols   == quantity_symbols  { ""_us , ""_us, "crad"_us         });

    static_assert(deciradian ::exponents == quantity_exponents{ 0     , 0    , 1                 });
    static_assert(deciradian ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e-1L             });
    static_assert(deciradian ::symbols   == quantity_symbols  { ""_us , ""_us, "drad"_us         });

    static_assert(radian     ::exponents == quantity_exponents{ 0     , 0    , 1                 });
    static_assert(radian     ::factors   == quantity_factors  { 0.0L  , 0.0L , 1e0L              });
    static_assert(radian     ::symbols   == quantity_symbols  { ""_us , ""_us, "rad"_us          });

    static_assert(degree     ::exponents == quantity_exponents{ 0     , 0    , 1                 });
    static_assert(degree     ::factors   == quantity_factors  { 0.0L  , 0.0L , pi/180.0L         });
    static_assert(degree     ::symbols   == quantity_symbols  { ""_us , ""_us, "deg"_us          });


    static_assert(prad   == picoradian  {});
    static_assert(micrad == microradian {});
    static_assert(mrad   == milliradian {});
    static_assert(crad   == centiradian {});
    static_assert(rad    == radian      {});
    static_assert(deg    == degree      {});


    static_assert(1.0_prad   == 1.0 * prad  );
    static_assert(1_prad     == 1.0 * prad  );

    static_assert(1.0_nrad   == 1.0 * nrad  );
    static_assert(1_nrad     == 1.0 * nrad  );

    static_assert(1.0_micrad == 1.0 * micrad);
    static_assert(1_micrad   == 1.0 * micrad);

    static_assert(1.0_mrad   == 1.0 * mrad  );
    static_assert(1_mrad     == 1.0 * mrad  );

    static_assert(1.0_crad   == 1.0 * crad  );
    static_assert(1_crad     == 1.0 * crad  );

    static_assert(1.0_drad   == 1.0 * drad  );
    static_assert(1_drad     == 1.0 * drad  );

    static_assert(1.0_rad    == 1.0 * rad   );
    static_assert(1_rad      == 1.0 * rad   );

    static_assert(1.0_deg    == 1.0 * deg   );
    static_assert(1_deg      == 1.0 * deg   );

}
