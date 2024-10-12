#ifndef __ZOLLSTOCK_AREA_UNITS_HPP__
#define __ZOLLSTOCK_AREA_UNITS_HPP__


#include <zollstock/area_unit_constants.hpp>
#include <zollstock/literal_definition_helpers.hpp>


namespace zollstock::units::inline literals
{

    ZOLLSTOCK_DEFINE_SI_LITERALS(m2)


    template <typename Quantity>
    concept area_c = requires
    {
        requires quantity_c<Quantity>;
        requires unit_dimensions(Quantity::unit()) == dimensions::pow_v<dimensions::L, 2>;
    };

}


#endif //__ZOLLSTOCK_AREA_UNITS_HPP__
