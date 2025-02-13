#ifndef __ZOLLSTOCK_TESTS_REQUIRED_HEADER_DEPENDENCIES_HPP__
#define __ZOLLSTOCK_TESTS_REQUIRED_HEADER_DEPENDENCIES_HPP__


#include <zollstock/tests/header_dependencies.hpp>


inline const header_set quantities = header_dir(
    "zollstock/quantities",
    {
        "constants.hpp",
        "math.hpp",
        "limits.hpp",
        "quantity.hpp"
    }
);

inline const header_set quantity_concepts = header_dir(
    "zollstock/quantities/concepts",
    {
        "amount_of_substance.hpp",
        "area.hpp",
        "dimensionless.hpp",
        "length.hpp",
        "planar_angle.hpp",
        "quantity.hpp",
        "temperature.hpp",
        "time.hpp",
        "volume.hpp",
        "electric_current.hpp"
    }
);

inline const header_set base_unit_constants = header_dir(
    "zollstock/units/constants",
    {
        "one.hpp",
        "amount_of_substance.hpp",
        "length.hpp",
        "mass.hpp",
        "temperature.hpp",
        "electric_current.hpp"
    }
);

inline const header_set derived_unit_constants = header_dir(
    "zollstock/units/constants",
    {
        "one.hpp",
        "planar_angle.hpp",
        "time.hpp",
        "area.hpp",
        "volume.hpp"
    }
);

inline const header_set unit_constants = base_unit_constants & derived_unit_constants;

inline const header_set base_unit_literals = header_dir(
    "zollstock/units/literals",
    {
        "one.hpp",
        "length.hpp",
        "time.hpp",
        "mass.hpp",
        "temperature.hpp",
        "amount_of_substance.hpp",
        "electric_current.hpp"
    }
);

inline const header_set derived_unit_literals = header_dir(
    "zollstock/units/literals",
    {
        "one.hpp",
        "planar_angle.hpp",
        "area.hpp",
        "volume.hpp"
    }
);

inline const header_set unit_literals = base_unit_literals & derived_unit_literals;

inline const header_set unit_concepts = header_dir(
    "zollstock/units/concepts",
    {
        "prefix.hpp",
        "unit.hpp"
    }
);

inline const header_set amount_of_substance = header_dir(
    "zollstock/units",
    {
        "constants/amount_of_substance.hpp",
        "literals/amount_of_substance.hpp"
    }
);

inline const header_set area = header_dir(
    "zollstock/units",
    {
        "constants/area.hpp",
        "literals/area.hpp"
    }
);

inline const header_set length = header_dir(
    "zollstock/units",
    {
        "constants/length.hpp",
        "literals/length.hpp"
    }
);

inline const header_set mass = header_dir(
    "zollstock/units",
    {
        "constants/mass.hpp",
        "literals/mass.hpp"
    }
);

inline const header_set electric_current = header_dir(
    "zollstock/units",
    {
        "constants/electric_current.hpp",
        "literals/electric_current.hpp"
    }
);

inline const header_set one = header_dir(
    "zollstock/units",
    {
        "constants/one.hpp",
        "literals/one.hpp"
    }
);

inline const header_set planar_angle = header_dir(
    "zollstock/units",
    {
        "constants/planar_angle.hpp",
        "literals/planar_angle.hpp"
    }
);

inline const header_set temperature = header_dir(
    "zollstock/units",
    {
        "constants/temperature.hpp",
        "literals/temperature.hpp"
    }
);

inline const header_set time_ = header_dir(
    "zollstock/units",
    {
        "constants/time.hpp",
        "literals/time.hpp"
    }
);

inline const header_set volume = header_dir(
    "zollstock/units",
    {
        "constants/volume.hpp",
        "literals/volume.hpp"
    }
);


inline const header_dependencies required_header_dependencies{
    {
        "zollstock.hpp"
            , quantities
            & quantity_concepts
            & unit_constants
            & unit_literals
            & unit_concepts
            & header_dir(
                "zollstock",
                {
                    "dimensions.hpp",
                    "numbers.hpp",
                    "prefixes.hpp",
                    "static_string.hpp",
                    "tuple_utils.hpp"
                }
            )
    },
    {
        "zollstock/quantities.hpp"
            , quantities
            & quantity_concepts
    },
    {
        "zollstock/units.hpp"
            , unit_constants
            & unit_literals
    },
    {
        "zollstock/units/concepts.hpp"
            , unit_concepts
    },
    {
        "zollstock/units/constants.hpp"
            , unit_constants
    },
    {
        "zollstock/units/literals.hpp"
            , unit_literals
    },
    {
        "zollstock/units/base.hpp"
            , base_unit_constants
            & base_unit_literals
    },
    {
        "zollstock/units/derived.hpp"
            , derived_unit_constants
            & derived_unit_literals
    },
    {
        "zollstock/units/constants/base.hpp"
            , base_unit_constants
    },
    {
        "zollstock/units/constants/derived.hpp"
            , derived_unit_constants
    },
    {
        "zollstock/units/literals/base.hpp"
            , base_unit_literals
    },
    {
        "zollstock/units/literals/derived.hpp"
            , derived_unit_literals
    },
    {
        "zollstock/units/amount_of_substance.hpp"
            , amount_of_substance
    },
    {
        "zollstock/units/area.hpp"
            , area
    },
    {
        "zollstock/units/length.hpp"
            , length
    },
    {
        "zollstock/units/mass.hpp"
            , mass
    },
    {
        "zollstock/units/electric_current.hpp"
            , electric_current
    },
    {
        "zollstock/units/one.hpp"
            , one
    },
    {
        "zollstock/units/planar_angle.hpp"
            , planar_angle
    },
    {
        "zollstock/units/temperature.hpp"
            , temperature
    },
    {
        "zollstock/units/time.hpp"
            , time_
    },
    {
        "zollstock/units/volume.hpp"
            , volume
    }
};


#endif //__ZOLLSTOCK_TESTS_REQUIRED_HEADER_DEPENDENCIES_HPP__
