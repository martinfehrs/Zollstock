#ifndef __ZOLLSTOCK_QUANTITIES_CONCEPTS_ELECTRIC_CURRENT_HPP__
#define __ZOLLSTOCK_QUANTITIES_CONCEPTS_ELECTRIC_CURRENT_HPP__


#include <zollstock/quantities/concepts/quantity.hpp>
#include <zollstock/units/concepts/unit.hpp>


namespace zollstock::inline quantities
{

    namespace detail
    {

        // Kapselung des Aufrufes unit_dimensions in einer Vorlagenvariable wegen eines
        // internen Fehlers des MSVC-Compilers.
        template <typename Quantity>
        inline constexpr bool electric_current_v =
            quantity_c<Quantity> &&
            unit_dimensions(Quantity::unit()) == dimensions::I;

    }

    template <typename Quantity>
    concept electric_current_c = detail::electric_current_v<Quantity>;

}


#endif //__ZOLLSTOCK_QUANTITIES_CONCEPTS_ELECTRIC_CURRENT_HPP__
