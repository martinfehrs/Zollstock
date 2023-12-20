#ifndef __ZOLLSTOCK_UNIT_DATA_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_DATA_CONCEPT_HPP__


#include <utility>
#include <type_traits>


namespace zollstock
{

    inline constexpr std::size_t base_dimension_count = 2;
    inline constexpr std::size_t derived_dimension_count = 1;
    inline constexpr std::size_t dimension_count = base_dimension_count + derived_dimension_count;


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
    inline constexpr bool is_unit_data_v = has_length_member_v<Candidate>
                                        && has_time_member_v<Candidate>
                                        && has_angle_member_v<Candidate>;


    template <
        std::size_t pos,
        typename UnitData,
        typename = std::enable_if_t<(pos < dimension_count)>,
        typename = std::enable_if_t<is_unit_data_v<UnitData>>
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


    template<std::size_t pos, typename UnitData>
    struct unit_data_element
    {
        using type = std::remove_const_t<std::remove_reference_t<decltype(get<pos>(std::declval<UnitData>()))>>;
    };

    template<std::size_t pos, typename UnitData>
    using unit_data_element_t = typename unit_data_element<pos, UnitData>::type;


    template <
        std::size_t pos,
        typename UnitData,
        typename = std::enable_if_t<(pos < dimension_count)>,
        typename = std::enable_if_t<is_unit_data_v<UnitData>>
    >
    [[nodiscard]] constexpr auto& get(UnitData& data) noexcept
    {
        return const_cast<unit_data_element_t<pos, UnitData>&>(get<pos>(std::as_const(data)));
    }

    template <typename IndexSequence, std::size_t offset>
    struct shift_right;

    template <template <typename, std::size_t...> typename IndexSequence, std::size_t... indices, std::size_t offset>
    struct shift_right<IndexSequence<std::size_t, indices...>, offset>
    {
        using type = IndexSequence<std::size_t, (indices + offset)...>;
    };

    template <typename IndexSequence, std::size_t offset>
    using shift_right_t = typename shift_right<IndexSequence, offset>::type; 


    template <std::size_t count, std::size_t first = 0U>
    using make_index_sequence = shift_right_t<std::make_index_sequence<count>, first>;

    using make_base_dimension_index_sequence = make_index_sequence<base_dimension_count>;
    using make_derived_dimension_index_sequence = make_index_sequence<derived_dimension_count, base_dimension_count>;
    using make_dimension_index_sequence = make_index_sequence<dimension_count>;

}


#endif //__ZOLLSTOCK_UNIT_DATA_CONCEPT_HPP__