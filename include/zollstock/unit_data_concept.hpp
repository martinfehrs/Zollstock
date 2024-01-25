#ifndef __ZOLLSTOCK_UNIT_DATA_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_DATA_CONCEPT_HPP__


#include <utility>
#include <type_traits>


namespace zollstock
{

    inline constexpr std::size_t base_unit_count = 2;
    inline constexpr std::size_t derived_unit_count = 1;
    inline constexpr std::size_t unit_count = base_unit_count + derived_unit_count;

    template <typename Candidate>
    concept unit_data_c = requires(const Candidate& candidate)
    {
        candidate.length;
        candidate.time;
        candidate.angle;
    };

    template <
        std::size_t pos,
        unit_data_c UnitData,
        typename = std::enable_if_t<(pos < unit_count)>
    >
    [[nodiscard]] constexpr const auto& get(const UnitData& data)
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

    template<std::size_t pos, unit_data_c UnitData>
    struct unit_data_element
    {
        using type = std::remove_cvref_t<decltype(get<pos>(std::declval<UnitData>()))>;
    };

    template<std::size_t pos, unit_data_c UnitData>
    using unit_data_element_t = typename unit_data_element<pos, UnitData>::type;


    template <
        std::size_t pos,
        unit_data_c UnitData,
        typename = std::enable_if_t<(pos < unit_count)>
    >
    [[nodiscard]] constexpr auto& get(UnitData& data) noexcept
    {
        return const_cast<unit_data_element_t<pos, UnitData>&>(
            get<pos>(std::as_const(data))
        );
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

    using make_base_unit_index_sequence = make_index_sequence<base_unit_count>;

    using make_derived_unit_index_sequence = make_index_sequence<
        derived_unit_count, base_unit_count
    >;

    using make_unit_index_sequence = make_index_sequence<unit_count>;

    namespace detail
    {
        template <unit_data_c UnitData, std::size_t... indices>
        [[nodiscard]] constexpr bool equal(
            const UnitData& data_1, const UnitData& data_2, std::index_sequence<indices...>
        ) noexcept
        {
            return (... && (get<indices>(data_1) == get<indices>(data_2)));
        }
    }

    template <unit_data_c UnitData>
    [[nodiscard]] constexpr bool operator==(
        const UnitData& data_1, const UnitData& data_2
    ) noexcept
    {
        return detail::equal(data_1, data_2, make_unit_index_sequence{});
    }

}


#endif //__ZOLLSTOCK_UNIT_DATA_CONCEPT_HPP__
