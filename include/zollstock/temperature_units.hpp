#ifndef __ZOLLSTOCK_TEMPERATURE_UNITS_HPP__
#define __ZOLLSTOCK_TEMPERATURE_UNITS_HPP__


#include <zollstock/temperature_unit_constants.hpp>
#include <zollstock/literal_definition_helpers.hpp>


namespace zollstock::units::inline literals
{

    ZOLLSTOCK_DEFINE_SI_LITERALS(K)


    template <typename Quantity>
    concept temperature_c = requires
    {
        requires quantity_c<Quantity>;
        requires unit_dimensions(Quantity::unit()) == dimensions::Theta;
    };

}


#endif //__ZOLLSTOCK_TEMPERATURE_UNITS_HPP__
