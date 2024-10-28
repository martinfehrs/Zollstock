#ifndef __ZOLLSTOCK_VOLUME_CONCEPT_HPP__
#define __ZOLLSTOCK_VOLUME_CONCEPT_HPP__


#include <zollstock/quantity_concept.hpp>
#include <zollstock/unit_concept.hpp>


namespace zollstock::inline quantities
{

    template <typename Quantity>
    concept volume_c = requires
    {
        requires quantity_c<Quantity>;
        requires unit_dimensions(Quantity::unit()) == dimensions::pow_v<dimensions::L, 3>;
    };

}


#endif //__ZOLLSTOCK_VOLUME_CONCEPT_HPP__
