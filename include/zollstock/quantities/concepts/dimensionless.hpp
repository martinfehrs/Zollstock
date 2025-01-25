#ifndef __ZOLLSTOCK_QUANTITIES_CONCEPTS_DIMENSIONLESS_HPP__
#define __ZOLLSTOCK_QUANTITIES_CONCEPTS_DIMENSIONLESS_HPP__


#include <zollstock/quantities/concepts/quantity.hpp>
#include <zollstock/units/concepts/unit.hpp>


namespace zollstock::inline quantities
{

    namespace detail
    {

        // Kapselung des Aufrufes unit_dimensions in einer Vorlagenvariable wegen eines
        // internen Fehlers des MSVC-Compilers.
        template <typename Quantity>
        inline constexpr bool dimensionless_v =
            quantity_c<Quantity> &&
            unit_dimensions(Quantity::unit()) == dimensions::_1;

    }

    template <typename Quantity>
    concept dimensionless_v = detail::dimensionless_v<Quantity>;

}


#endif //__ZOLLSTOCK_QUANTITIES_CONCEPTS_DIMENSIONLESS_HPP__
