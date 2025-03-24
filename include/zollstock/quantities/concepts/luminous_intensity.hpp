#ifndef __ZOLLSTOCK_QUANTITIES_CONCEPTS_LUMINOUS_INTENSITY_HPP__
#define __ZOLLSTOCK_QUANTITIES_CONCEPTS_LUMINOUS_INTENSITY_HPP__


#include <zollstock/quantities/concepts/quantity.hpp>
#include <zollstock/units/concepts/unit.hpp>


namespace zollstock::inline quantities
{

    namespace detail
    {

        // Kapselung des Aufrufes unit_dimensions in einer Vorlagenvariable wegen eines
        // internen Fehlers des MSVC-Compilers.
        template <typename Quantity>
        inline constexpr bool luminous_intensity_v =
            quantity_c<Quantity> &&
            unit_dimensions(Quantity::unit()) == dimensions::J;

    }

    template <typename Quantity>
    concept luminous_intensity_c = detail::luminous_intensity_v<Quantity>;

}


#endif //__ZOLLSTOCK_QUANTITIES_CONCEPTS_LUMINOUS_INTENSITY_HPP__
