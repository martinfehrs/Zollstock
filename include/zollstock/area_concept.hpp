#ifndef __ZOLLSTOCK_AREA_CONCEPT_HPP__
#define __ZOLLSTOCK_AREA_CONCEPT_HPP__


#include <zollstock/quantity_concept.hpp>
#include <zollstock/unit_concept.hpp>


namespace zollstock::inline quantities
{

    namespace detail
    {

        // Kapselung des Aufrufes unit_dimensions in einer Vorlagenvariable wegen eines
        // internen Fehlers des MSVC-Compilers.
        template <typename Quantity>
        inline constexpr bool area_v =
            quantity_c<Quantity> &&
            unit_dimensions(Quantity::unit()) == dimensions::pow_v<dimensions::L, 2>;

    }

    template <typename Quantity>
    concept area_c = detail::area_v<Quantity>;

}


#endif //__ZOLLSTOCK_AREA_CONCEPT_HPP__
