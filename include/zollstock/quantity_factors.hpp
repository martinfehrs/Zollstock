#ifndef __ZOLLSTOCK_QUANTITY_FACTORS_HPP__
#define __ZOLLSTOCK_QUANTITY_FACTORS_HPP__


#include <zollstock/quantity_data_concept.hpp>


namespace zollstock
{

    struct quantity_factors
    {
        long double length;
        long double time;

        long double angle;
    };

    namespace detail
    {

        template<std::size_t... indices>
        [[nodiscard]] constexpr quantity_factors combined_impl(
            const quantity_factors& factors_1,
            const quantity_factors& factors_2,
            std::index_sequence<indices...>
        ) noexcept
        {
            return {
                ((get<indices>(factors_1) != 0) ?
                    get<indices>(factors_1) :
                    get<indices>(factors_2))...
            };
        }

    }

    [[nodiscard]] constexpr quantity_factors combined(
        const quantity_factors& factors_1,
        const quantity_factors& factors_2
    ) noexcept
    {
        return detail::combined_impl(
            factors_1,
            factors_2,
            make_quantity_index_sequence{}
        );
    }

}


#endif //__ZOLLSTOCK_QUANTITY_FACTORS_HPP__
