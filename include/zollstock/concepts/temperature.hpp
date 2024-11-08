#ifndef __ZOLLSTOCK_CONCEPTS_TEMPERATURE_HPP__
#define __ZOLLSTOCK_CONCEPTS_TEMPERATURE_HPP__


#include <zollstock/concepts/quantity.hpp>
#include <zollstock/concepts/unit.hpp>


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


#endif //__ZOLLSTOCK_CONCEPTS_TEMPERATURE_HPP__
