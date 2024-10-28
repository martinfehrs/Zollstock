#ifndef __ZOLLSTOCK_LENGTH_CONCEPT_HPP__
#define __ZOLLSTOCK_LENGTH_CONCEPT_HPP__


#include <zollstock/quantity_concept.hpp>
#include <zollstock/unit_concept.hpp>


namespace zollstock::inline quantities
{

    template <typename Quantity>
    concept length_c = requires
    {
        requires quantity_c<Quantity>;
        requires unit_dimensions(Quantity::unit()) == dimensions::L;
    };

}


#endif //__ZOLLSTOCK_LENGTH_CONCEPT_HPP__
