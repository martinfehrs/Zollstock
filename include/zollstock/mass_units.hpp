#ifndef __ZOLLSTOCK_MASS_UNITS_HPP__
#define __ZOLLSTOCK_MASS_UNITS_HPP__


#include <zollstock/mass_unit_constants.hpp>
#include <zollstock/literal_definition_helpers.hpp>


namespace zollstock::units::inline literals
{

    ZOLLSTOCK_DEFINE_SI_LITERALS(g)


    template <typename Quantity>
    concept mass_c = requires
    {
        requires quantity_c<Quantity>;
        requires unit_dimensions(Quantity::unit()) == dimensions::M;
    };

}


#endif //__ZOLLSTOCK_MASS_UNITS_HPP__
