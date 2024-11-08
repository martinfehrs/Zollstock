#ifndef __ZOLLSTOCK_CONCEPTS_VOLUME_HPP__
#define __ZOLLSTOCK_CONCEPTS_VOLUME_HPP__


#include <zollstock/concepts/quantity.hpp>
#include <zollstock/concepts/unit.hpp>

namespace zollstock::inline quantities
{

    namespace detail
    {

        // Kapselung des Aufrufes unit_dimensions in einer Vorlagenvariable wegen eines
        // internen Fehlers des MSVC-Compilers.
        template <typename Quantity>
        inline constexpr bool volume_v =
            quantity_c<Quantity> &&
            unit_dimensions(Quantity::unit()) == dimensions::pow_v<dimensions::L, 3>;

    }

    template <typename Quantity>
    concept volume_c = detail::volume_v<Quantity>;

}


#endif //__ZOLLSTOCK_CONCEPTS_VOLUME_HPP__
