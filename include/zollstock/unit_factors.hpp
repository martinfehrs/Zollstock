#ifndef __ZOLLSTOCK_UNIT_FACTORS_HPP__
#define __ZOLLSTOCK_UNIT_FACTORS_HPP__


#include "unit_data_concept.hpp"


namespace zollstock
{

    struct unit_factors
    {
        long double length;
        long double time;
        
        long double angle;
    };


    template<std::size_t... indices>
    [[nodiscard]] constexpr unit_factors combined_impl(
        const unit_factors& factors_1,
        const unit_factors& factors_2,
        std::index_sequence<indices...>
    ) noexcept
    {
        return { ((get<indices>(factors_1) != 0) ? get<indices>(factors_1) : get<indices>(factors_2))... };
    }

    [[nodiscard]] constexpr unit_factors combined(
        const unit_factors& factors_1,
        const unit_factors& factors_2
    ) noexcept
    {
        return combined_impl(
            factors_1,
            factors_2,
            make_dimension_index_sequence{}
        );
    }

}


#endif //__ZOLLSTOCK_UNIT_FACTORS_HPP__