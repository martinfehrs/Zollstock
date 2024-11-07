#ifndef __ZOLLSTOCK_AMOUNT_OF_SUBSTANCE_CONCEPT_HPP__
#define __ZOLLSTOCK_AMOUNT_OF_SUBSTANCE_CONCEPT_HPP__


#include <zollstock/quantity_concept.hpp>
#include <zollstock/unit_concept.hpp>


namespace zollstock::inline quantities
{

    namespace detail
    {

        // Kapselung des Aufrufes unit_dimensions in einer Vorlagenvariable wegen eines
        // internen Fehlers des MSVC-Compilers.
        template <typename Quantity>
        inline constexpr bool amount_of_substance_v =
            quantity_c<Quantity> &&
            unit_dimensions(Quantity::unit()) == dimensions::N;

    }

    template <typename Quantity>
    concept amount_of_substance_v = detail::amount_of_substance_v<Quantity>;

}


#endif //__ZOLLSTOCK_AMOUNT_OF_SUBSTANCE_CONCEPT_HPP__
