#ifndef __ZOLLSTOCK_VOLUME_UNITS_HPP__
#define __ZOLLSTOCK_VOLUME_UNITS_HPP__


#include <zollstock/volume_unit_constants.hpp>
#include <zollstock/literal_definition_helpers.hpp>


namespace zollstock::units::inline literals
{

    ZOLLSTOCK_DEFINE_SI_LITERALS(m3)


    template <typename Quantity>
    concept volume_c = requires
    {
        requires quantity_c<Quantity>;
        requires unit_dimensions(Quantity::unit()) == dimensions::pow_v<dimensions::L, 3>;
    };

}


#endif //__ZOLLSTOCK_VOLUME_UNITS_HPP__
