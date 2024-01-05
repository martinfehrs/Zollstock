#ifndef __ZOLLSTOCK_QUANTITY_DATA_CONCEPT_HPP__
#define __ZOLLSTOCK_QUANTITY_DATA_CONCEPT_HPP__


#include <utility>
#include <type_traits>


namespace zollstock
{

    inline constexpr std::size_t base_quantity_count = 2;
    inline constexpr std::size_t derived_quantity_count = 1;
    inline constexpr std::size_t quantity_count = base_quantity_count + derived_quantity_count;


    template<typename Candidate, typename = void>
    inline constexpr bool has_length_member_v = false;

    template<typename Candidate>
    inline constexpr bool has_length_member_v<Candidate, std::void_t<decltype(std::declval<Candidate>().length)>> = true;


    template<typename Candidate, typename = void>
    inline constexpr bool has_time_member_v = false;

    template<typename Candidate>
    inline constexpr bool has_time_member_v<Candidate, std::void_t<decltype(std::declval<Candidate>().time)>> = true;


    template<typename Candidate, typename = void>
    inline constexpr bool has_angle_member_v = false;

    template<typename Candidate>
    inline constexpr bool has_angle_member_v<Candidate, std::void_t<decltype(std::declval<Candidate>().angle)>> = true;


    template <typename Candidate>
    inline constexpr bool is_quantity_data_v = has_length_member_v<Candidate>
                                            && has_time_member_v<Candidate>
                                            && has_angle_member_v<Candidate>;


    template <
        std::size_t pos,
        typename QuantityData,
        typename = std::enable_if_t<(pos < quantity_count)>,
        typename = std::enable_if_t<is_quantity_data_v<QuantityData>>
    >
    [[nodiscard]] constexpr const auto& get(const QuantityData& data)
    {
        if constexpr(pos == 0)
        {
            return data.length;
        }
        else if constexpr(pos == 1)
        {
            return data.time;
        }
        else if constexpr(pos == 2)
        {
            return data.angle;
        }
    }

    namespace detail
    {

        template <typename T>
        using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

    }


    template<std::size_t pos, typename QuantityData>
    struct quantity_data_element
    {
        using type = detail::remove_cvref_t<decltype(get<pos>(std::declval<QuantityData>()))>;
    };

    template<std::size_t pos, typename QuantityData>
    using quantity_data_element_t = typename quantity_data_element<pos, QuantityData>::type;


    template <
        std::size_t pos,
        typename QuantityData,
        typename = std::enable_if_t<(pos < quantity_count)>,
        typename = std::enable_if_t<is_quantity_data_v<QuantityData>>
    >
    [[nodiscard]] constexpr auto& get(QuantityData& data) noexcept
    {
        return const_cast<quantity_data_element_t<pos, QuantityData>&>(get<pos>(std::as_const(data)));
    }

    template <typename IndexSequence, std::size_t offset>
    struct shift_right;

    template <std::size_t... indices, std::size_t offset>
    struct shift_right<std::index_sequence<indices...>, offset>
    {
        using type = std::index_sequence<(indices + offset)...>;
    };

    template <typename IndexSequence, std::size_t offset>
    using shift_right_t = typename shift_right<IndexSequence, offset>::type;


    template <std::size_t count, std::size_t first = 0U>
    using make_index_sequence = shift_right_t<std::make_index_sequence<count>, first>;

    using make_base_quantity_index_sequence = make_index_sequence<base_quantity_count>;

    using make_derived_quantity_index_sequence = make_index_sequence<
        derived_quantity_count, base_quantity_count
    >;

    using make_quantity_index_sequence = make_index_sequence<quantity_count>;

    namespace detail
    {
        template <
            typename QuantityData,
            std::size_t... indices,
            typename = std::enable_if_t<is_quantity_data_v<QuantityData>>
        >
        [[nodiscard]] constexpr bool equal(
            const QuantityData& data_1, const QuantityData& data_2, std::index_sequence<indices...>
        ) noexcept
        {
            return (... && (get<indices>(data_1) == get<indices>(data_2)));
        }
    }

    template <typename QuantityData, typename = std::enable_if_t<is_quantity_data_v<QuantityData>>>
    [[nodiscard]] constexpr bool operator==(
        const QuantityData& data_1, const QuantityData& data_2
    ) noexcept
    {
        return detail::equal(data_1, data_2, make_quantity_index_sequence{});
    }

}


#endif //__ZOLLSTOCK_QUANTITY_DATA_CONCEPT_HPP__
