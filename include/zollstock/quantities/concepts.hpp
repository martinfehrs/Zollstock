#ifndef __ZOLLSTOCK_QUANTITIES_CONCEPTS_HPP__
#define __ZOLLSTOCK_QUANTITIES_CONCEPTS_HPP__


#include <zollstock/dimensions.hpp>
#include <zollstock/numbers.hpp>
#include <zollstock/units/concepts/unit.hpp>


namespace zollstock::inline quantities
{

    namespace detail
    {

        template <typename Quantity>
        concept quantity_base_c = requires(Quantity quantity, Quantity::value_type number)
        {
            requires std::regular<Quantity>;
            requires std::totally_ordered<Quantity>;

            requires number_c<typename Quantity::value_type>;
            requires unit_c<typename Quantity::unit_type>;

            { Quantity::unit()  } -> std::same_as<const typename Quantity::unit_type&>;
            { quantity.value()  } -> std::same_as<typename Quantity::value_type&>;
            { quantity.cvalue() } -> std::same_as<const typename Quantity::value_type&>;

            { -quantity } -> std::same_as<Quantity>;
            { +quantity } -> std::same_as<Quantity>;

            { quantity += quantity } -> std::same_as<Quantity&>;
            { quantity -= quantity } -> std::same_as<Quantity&>;
            { quantity *= number   } -> std::same_as<Quantity&>;
            { quantity /= number   } -> std::same_as<Quantity&>;

            { quantity + quantity } -> std::same_as<Quantity>;
            { quantity - quantity } -> std::same_as<Quantity>;
            { quantity * number   } -> std::same_as<Quantity>;
            { number   * quantity } -> std::same_as<Quantity>;
            { quantity / number   } -> std::same_as<Quantity>;

            { quantity * quantity };
            { quantity / quantity };

        };

    }

    template <typename Quantity>
    concept quantity_c = requires(Quantity quantity)
    {
        requires detail::quantity_base_c<Quantity>;

        { quantity * quantity } -> detail::quantity_base_c;
        { quantity / quantity } -> detail::quantity_base_c;
    };

    template <typename Quantity, typename Unit>
    concept measured_in_c = requires
    {
        requires quantity_c<Quantity>;
        requires std::same_as<typename Quantity::unit_type, std::remove_cvref_t<Unit>>;
    };



    namespace detail
    {

        // Kapselung des Aufrufes unit_dimensions in einer Vorlagenvariable wegen eines
        // internen Fehlers des MSVC-Compilers.
        template <typename Quantity, dimensions::dimensions_t dimensions>
        inline constexpr bool of_dimension_v =
            quantity_c<Quantity> &&
            unit_dimensions(Quantity::unit()) == dimensions;

    }

    template <typename Quantity, dimensions::dimensions_t dimensions>
    concept of_dimension_c = detail::of_dimension_v<Quantity, dimensions>;

}


#endif //__ZOLLSTOCK_QUANTITIES_CONCEPTS_HPP__
