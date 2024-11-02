#ifndef __ZOLLSTOCK_TEMPERATURE_CONCEPT_HPP__
#define __ZOLLSTOCK_TEMPERATURE_CONCEPT_HPP__


#include <zollstock/quantity_concept.hpp>
#include <zollstock/unit_concept.hpp>


namespace zollstock::inline quantities
{

    namespace detail
    {

        // Kapselung des Aufrufes unit_dimensions in einer Vorlagenvariable wegen eines
        // internen Fehlers des MSVC-Compilers.
        template <typename Quantity>
        inline constexpr bool temperature_v =
            quantity_c<Quantity> &&
            unit_dimensions(Quantity::unit()) == dimensions::Theta;

    }

    template <typename Quantity>
    concept temperature_c = detail::temperature_v<Quantity>;

}


#endif //__ZOLLSTOCK_TEMPERATURE_CONCEPT_HPP__
