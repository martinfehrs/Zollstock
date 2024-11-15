#ifndef __ZOLLSTOCK_QUANTITIES_CONCEPTS_AMOUNT_OF_SUBSTANCE_HPP__
#define __ZOLLSTOCK_QUANTITIES_CONCEPTS_AMOUNT_OF_SUBSTANCE_HPP__


#include <zollstock/quantities/concepts/quantity.hpp>
#include <zollstock/units/concepts/unit.hpp>


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


#endif //__ZOLLSTOCK_QUANTITIES_CONCEPTS_AMOUNT_OF_SUBSTANCE_HPP__
