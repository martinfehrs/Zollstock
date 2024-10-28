#ifndef __ZOLLSTOCK_TEMPERATURE_CONCEPT_HPP__
#define __ZOLLSTOCK_TEMPERATURE_CONCEPT_HPP__


#include <zollstock/quantity_concept.hpp>
#include <zollstock/unit_concept.hpp>


namespace zollstock::inline quantities
{

    template <typename Quantity>
    concept temperature_c = requires
    {
        requires quantity_c<Quantity>;
        requires unit_dimensions(Quantity::unit()) == dimensions::Theta;
    };

}


#endif //__ZOLLSTOCK_TEMPERATURE_CONCEPT_HPP__
