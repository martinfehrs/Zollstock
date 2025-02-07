#ifndef __ZOLLSTOCK_TESTS_REQUIRED_HEADER_DEPENDENCIES_HPP__
#define __ZOLLSTOCK_TESTS_REQUIRED_HEADER_DEPENDENCIES_HPP__


#include <zollstock/tests/header_dependencies.hpp>


inline const header_set quantities{
    "zollstock/quantities/constants.hpp",
    "zollstock/quantities/math.hpp",
    "zollstock/quantities/limits.hpp",
    "zollstock/quantities/quantity.hpp"
};

inline const header_set quantity_concepts{
    "zollstock/quantities/concepts/amount_of_substance.hpp",
    "zollstock/quantities/concepts/area.hpp",
    "zollstock/quantities/concepts/dimensionless.hpp",
    "zollstock/quantities/concepts/length.hpp",
    "zollstock/quantities/concepts/planar_angle.hpp",
    "zollstock/quantities/concepts/quantity.hpp",
    "zollstock/quantities/concepts/temperature.hpp",
    "zollstock/quantities/concepts/time.hpp",
    "zollstock/quantities/concepts/volume.hpp"
};

inline const header_set base_unit_constants{
    "zollstock/units/constants/one.hpp",
    "zollstock/units/constants/amount_of_substance.hpp",
    "zollstock/units/constants/length.hpp",
    "zollstock/units/constants/mass.hpp",
    "zollstock/units/constants/temperature.hpp"
};

inline const header_set derived_unit_constants{
    "zollstock/units/constants/one.hpp",
    "zollstock/units/constants/planar_angle.hpp",
    "zollstock/units/constants/time.hpp",
    "zollstock/units/constants/area.hpp",
    "zollstock/units/constants/volume.hpp"
};

inline const header_set unit_constants = base_unit_constants & derived_unit_constants;

inline const header_set base_unit_literals{
    "zollstock/units/literals/one.hpp",
    "zollstock/units/literals/length.hpp",
    "zollstock/units/literals/time.hpp",
    "zollstock/units/literals/mass.hpp",
    "zollstock/units/literals/temperature.hpp",
    "zollstock/units/literals/amount_of_substance.hpp"
};

inline const header_set derived_unit_literals{
    "zollstock/units/literals/one.hpp",
    "zollstock/units/literals/planar_angle.hpp",
    "zollstock/units/literals/area.hpp",
    "zollstock/units/literals/volume.hpp"
};

inline const header_set unit_literals = base_unit_literals & derived_unit_literals;

inline const header_set unit_concepts{
    "zollstock/units/concepts/prefix.hpp",
    "zollstock/units/concepts/unit.hpp"
};


inline const header_dependencies required_header_dependencies{
    {
        "zollstock.hpp"
            , quantities
            & quantity_concepts
            & unit_constants
            & unit_literals
            & unit_concepts
            & header_set{
                "zollstock/dimensions.hpp",
                "zollstock/numbers.hpp",
                "zollstock/prefixes.hpp",
                "zollstock/static_string.hpp",
                "zollstock/tuple_utils.hpp"
            }
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
        "zollstock/units/amount_of_substance.hpp", {
            "zollstock/units/constants/amount_of_substance.hpp",
            "zollstock/units/literals/amount_of_substance.hpp"
        }
    },
    {
        "zollstock/units/area.hpp", {
            "zollstock/units/constants/area.hpp",
            "zollstock/units/literals/area.hpp"
        }
    },
    {
        "zollstock/units/length.hpp", {
            "zollstock/units/constants/length.hpp",
            "zollstock/units/literals/length.hpp"
        }
    },
    {
        "zollstock/units/mass.hpp", {
            "zollstock/units/constants/mass.hpp",
            "zollstock/units/literals/mass.hpp"
        }
    },
    {
        "zollstock/units/one.hpp", {
            "zollstock/units/constants/one.hpp",
            "zollstock/units/literals/one.hpp"
        }
    },
    {
        "zollstock/units/planar_angle.hpp", {
            "zollstock/units/constants/planar_angle.hpp",
            "zollstock/units/literals/planar_angle.hpp"
        }
    },
    {
        "zollstock/units/temperature.hpp", {
            "zollstock/units/constants/temperature.hpp",
            "zollstock/units/literals/temperature.hpp"
        }
    },
    {
        "zollstock/units/time.hpp", {
            "zollstock/units/constants/time.hpp",
            "zollstock/units/literals/time.hpp"
        }
    },
    {
        "zollstock/units/volume.hpp", {
            "zollstock/units/constants/volume.hpp",
            "zollstock/units/literals/volume.hpp"
        }
    }
};


#endif //__ZOLLSTOCK_TESTS_REQUIRED_HEADER_DEPENDENCIES_HPP__
