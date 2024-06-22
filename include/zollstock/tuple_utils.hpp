#ifndef __ZOLLSTOCK_TUPLE_UTILS_HPP__
#define __ZOLLSTOCK_TUPLE_UTILS_HPP__


#include <cstddef>
#include <functional>
#include <tuple>


namespace zollstock
{

    namespace detail
    {

        template <typename Tuple1, typename Tuple2, typename BinaryPred, std::size_t... indices>
        [[nodiscard]] constexpr bool tuple_equal_impl(
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

    template <typename Tuple1, typename Tuple2, typename BinaryPred>
    [[nodiscard]] constexpr bool tuple_equal(
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

    [[nodiscard]] constexpr bool tuple_equal(const auto& tuple_1, const auto& tuple_2) noexcept
    {
        return tuple_equal(
            tuple_1, tuple_2, [](const auto& lhs, const auto& rhs){ return lhs == rhs; }
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
        [[nodiscard]] constexpr T tuple_transform_reduce_impl(
            Tuple&& tuple,
            T init,
            BinaryOp reduce,
            UnaryOp transform,
            std::integral_constant<std::size_t, index>
        )
        {
            if constexpr(index == std::tuple_size_v<Tuple>)
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

    template <typename Tuple, typename T, typename BinaryOp, typename UnaryOp>
    [[nodiscard]] constexpr T tuple_transform_reduce(
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

        template <typename Tuple, typename T, std::size_t... indices>
        [[nodiscard]] constexpr bool tuple_contains_impl(
            const Tuple& tuple, const T& value, std::index_sequence<indices...>
        )
        {
            return (false || ... || (std::get<indices>(tuple) == value));
        }

    }

    template <typename Tuple, typename T>
    [[nodiscard]] constexpr bool tuple_contains(const Tuple& tuple, const T& value)
    {
        return detail::tuple_contains_impl(
            tuple,
            value,
            std::make_index_sequence<std::tuple_size_v<Tuple>>{}
        );
    }

}


#endif //___ZOLLSTOCK_TUPLE_UTILS_HPP__
