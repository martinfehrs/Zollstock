#ifndef __ZOLLSTOCK_TUPLE_UTILS_HPP__
#define __ZOLLSTOCK_TUPLE_UTILS_HPP__


#ifndef ZOLLSTOCK_USE_MODULES
#  include <zollstock/config.hpp>

#  include <cstddef>
#  include <functional>
#  include <tuple>
#endif


namespace zollstock
{

    namespace detail
    {

        template <typename Tuple1, typename Tuple2, typename BinaryPred, std::size_t... indices>
        [[nodiscard]] consteval bool tuple_equal_impl(
            const Tuple1& tuple_1,
            const Tuple2& tuple_2,
            BinaryPred compare,
            std::index_sequence<indices...>
        )
        {
            if constexpr(std::tuple_size_v<Tuple1> != std::tuple_size_v<Tuple2>)
            {
                return false;
            }
            else
            {
                return (
                    true && ... && compare(std::get<indices>(tuple_1), std::get<indices>(tuple_2))
                );
            }
        }

    }

    ZOLLSTOCK_MODULE_EXPORT template <typename Tuple1, typename Tuple2, typename BinaryPred>
    [[nodiscard]] consteval bool tuple_equal(
        const Tuple1& tuple_1, const Tuple2& tuple_2, BinaryPred compare
    ) noexcept
    {
        return detail::tuple_equal_impl(
            tuple_1,
            tuple_2,
            compare,
            std::make_index_sequence<std::tuple_size_v<Tuple1>>{}
        );
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval bool tuple_equal(
        const auto& tuple_1, const auto& tuple_2
    ) noexcept
    {
        return tuple_equal(
            tuple_1, tuple_2, [](const auto& lhs, const auto& rhs) consteval { return lhs == rhs; }
        );
    }



    namespace detail
    {

        template <typename Tuple, typename UnaryPred, std::size_t... indices>
        [[nodiscard]] consteval bool tuple_all_of_impl(
            const Tuple& tuple,
            UnaryPred pred,
            std::index_sequence<indices...>
        )
        {
            return (true && ... && static_cast<bool>(pred(std::get<indices>(tuple))));
        }
    }

    ZOLLSTOCK_MODULE_EXPORT template <typename Tuple, typename UnaryPred>
    [[nodiscard]] consteval bool tuple_all_of(const Tuple& tuple, UnaryPred pred)
    {
        return detail::tuple_all_of_impl(
            tuple, pred, std::make_index_sequence<std::tuple_size_v<Tuple>>{}
        );
    }



    namespace detail
    {

        template <
            typename Tuple,
            typename T,
            typename BinaryOp,
            typename UnaryOp,
            std::size_t index
        >
        [[nodiscard]] constexpr auto tuple_transform_reduce_impl(
            Tuple&& tuple,
            T init,
            BinaryOp reduce,
            UnaryOp transform,
            std::integral_constant<std::size_t, index>
        )
        {
            if constexpr(index == std::tuple_size_v<std::remove_cvref_t<Tuple>>)
            {
                return init;
            }
            else
            {
                return reduce(
                    tuple_transform_reduce_impl(
                        std::forward<Tuple>(tuple),
                        init,
                        reduce,
                        transform,
                        std::integral_constant<std::size_t, index + 1>{}
                    ),
                    transform(std::get<index>(std::forward<Tuple>(tuple)))
                );
            }
        }

    }

    ZOLLSTOCK_MODULE_EXPORT template <
        typename Tuple, typename T, typename BinaryOp, typename UnaryOp
    >
    [[nodiscard]] constexpr auto tuple_transform_reduce(
        Tuple&& tuple,
        T init,
        BinaryOp reduce,
        UnaryOp transform
    )
    {
        return detail::tuple_transform_reduce_impl(
            std::forward<Tuple>(tuple),
            init,
            reduce,
            transform,
            std::integral_constant<std::size_t, 0>{}
        );
    }



    namespace detail
    {

        template <
            typename Tuple1,
            typename Tuple2,
            typename T,
            typename BinaryOp1,
            typename BinaryOp2,
            std::size_t index
        >
        [[nodiscard]] constexpr auto tuple_transform_reduce_impl(
            Tuple1&& tuple_1,
            Tuple2&& tuple_2,
            T init,
            BinaryOp1 reduce,
            BinaryOp2 transform,
            std::integral_constant<std::size_t, index>
        )
        {
            if constexpr(index == std::tuple_size_v<std::remove_cvref_t<Tuple1>>)
            {
                return init;
            }
            else
            {
                return reduce(
                    tuple_transform_reduce_impl(
                        std::forward<Tuple1>(tuple_1),
                        std::forward<Tuple2>(tuple_2),
                        init,
                        reduce,
                        transform,
                        std::integral_constant<std::size_t, index + 1>{}
                    ),
                    transform(
                        std::get<index>(std::forward<Tuple1>(tuple_1)),
                        std::get<index>(std::forward<Tuple2>(tuple_2))
                    )
                );
            }
        }

    }

    ZOLLSTOCK_MODULE_EXPORT template <
        typename Tuple1, typename Tuple2, typename T, typename BinaryOp1, typename BinaryOp2
    >
    [[nodiscard]] constexpr auto tuple_transform_reduce(
        Tuple1&& tuple_1,
        Tuple2&& tuple_2,
        T init,
        BinaryOp1 reduce,
        BinaryOp2 transform
    )
    {
        return detail::tuple_transform_reduce_impl(
            std::forward<Tuple1>(tuple_1),
            std::forward<Tuple2>(tuple_2),
            init,
            reduce,
            transform,
            std::integral_constant<std::size_t, 0>{}
        );
    }

    namespace detail
    {

        template <typename Tuple, typename T, std::size_t... indices>
        [[nodiscard]] consteval bool tuple_contains_impl(
            const Tuple& tuple, const T& value, std::index_sequence<indices...>
        )
        {
            return (false || ... || (std::get<indices>(tuple) == value));
        }

    }

    ZOLLSTOCK_MODULE_EXPORT template <typename Tuple, typename T>
    [[nodiscard]] consteval bool tuple_contains(const Tuple& tuple, const T& value)
    {
        return detail::tuple_contains_impl(
            tuple,
            value,
            std::make_index_sequence<std::tuple_size_v<Tuple>>{}
        );
    }



    namespace detail
    {

        template <typename Tuple1, typename Tuple2, std::size_t index>
        [[nodiscard]] consteval int tuple_lexicographical_compare_three_way_impl(
            const Tuple1& tuple_1,
            const Tuple2& tuple_2,
            std::integral_constant<std::size_t, index>
        )
        {
            if constexpr(index == std::tuple_size_v<Tuple1> && index < std::tuple_size_v<Tuple2>)
            {
                return -1;
            }
            else
            if constexpr(index == std::tuple_size_v<Tuple2> && index < std::tuple_size_v<Tuple1>)
            {
                return 1;
            }
            else
            if constexpr (index == std::tuple_size_v<Tuple1> && index == std::tuple_size_v<Tuple2>)
            {
                return 0;
            }
            else
            if (std::get<index>(tuple_1) < std::get<index>(tuple_2))
            {
                return -1;
            }
            else
            if (std::get<index>(tuple_2) < std::get<index>(tuple_1))
            {
                return 1;
            }
            else
            {
                return tuple_lexicographical_compare_three_way_impl(
                    tuple_1, tuple_2, std::integral_constant<std::size_t, index + 1>{}
                );
            }
        }

    }

    ZOLLSTOCK_MODULE_EXPORT template <typename Tuple1, typename Tuple2>
    [[nodiscard]] consteval int tuple_lexicographical_compare_three_way(
        const Tuple1& tuple_1, const Tuple2& tuple_2
    )
    {
        return detail::tuple_lexicographical_compare_three_way_impl(
            tuple_1, tuple_2, std::integral_constant<std::size_t, 0>{}
        );
    }

}


#endif //__ZOLLSTOCK_TUPLE_UTILS_HPP__
