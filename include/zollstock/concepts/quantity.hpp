#ifndef __ZOLLSTOCK_CONCEPTS_QUANTITY_HPP__
#define __ZOLLSTOCK_CONCEPTS_QUANTITY_HPP__


#include <zollstock/number_utilities.hpp>
#include <zollstock/concepts/unit.hpp>

#include <concepts>


namespace zollstock
{

    namespace detail
    {

        template <typename Quantity>
        concept quantity_base_c = requires(Quantity quantity, Quantity::value_type number)
        {
            requires std::regular<Quantity>;

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
    concept quantity_with_unit_c = requires
    {
        requires quantity_c<Quantity>;
        requires std::same_as<typename Quantity::unit_type, std::remove_cvref_t<Unit>>;
    };

}


#endif //__ZOLLSTOCK_CONCEPTS_QUANTITY_HPP__
