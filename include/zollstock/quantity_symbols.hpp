#ifndef __ZOLLSTOCK_QUANTITY_SYMBOLS_HPP__
#define __ZOLLSTOCK_QUANTITY_SYMBOLS_HPP__


#include <zollstock/unit_symbol.hpp>
#include <zollstock/quantity_data_concept.hpp>

#include <cstddef>


namespace zollstock
{

    struct quantity_symbols
    {
        unit_symbol length;
        unit_symbol time;

        unit_symbol angle;
    };

    namespace detail
    {

        template <std::size_t pos>
        [[nodiscard]] constexpr unit_symbol select_symbol_entry(
            const quantity_exponents& exponents,
            const quantity_symbols& symbols_1,
            const quantity_symbols& symbols_2
        )
        {
            const unit_symbol& symbol_1 = get<pos>(symbols_1);
            const unit_symbol& symbol_2 = get<pos>(symbols_2);

            if (get<pos>(exponents) == 0)
            {
                return ""_us;
            }
            else if (symbol_1.size() == 0)
            {
                return symbol_2;
            }
            else if (symbol_2.size() == 0)
            {
                return symbol_1;
            }
            else if (symbol_1 == symbol_2)
            {
                return symbol_1;
            }
            else
            {
                throw "incompatible symbols";
            }
        }

        template<std::size_t... indices>
        [[nodiscard]] constexpr auto select_symbols_impl(
            const quantity_exponents& exponents,
            const quantity_symbols& symbols_1,
            const quantity_symbols& symbols_2,
            std::index_sequence<indices...>
        ) noexcept
        {
            return quantity_symbols{
                select_symbol_entry<indices>(exponents, symbols_1, symbols_2)...
            };
        }

    }

    [[nodiscard]] constexpr inline auto select_symbols(
        const quantity_exponents& exponents,
        const quantity_symbols& symbols_1,
        const quantity_symbols& symbols_2
    ) noexcept
    {
        return detail::select_symbols_impl(
            exponents,
            symbols_1,
            symbols_2,
            make_quantity_index_sequence{}
        );
    }

}


#endif //__ZOLLSTOCK_QUANTITY_SYMBOLS_HPP__
