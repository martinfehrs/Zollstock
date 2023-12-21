#ifndef __ZOLLSTOCK_UNIT_SYMBOLS_HPP__
#define __ZOLLSTOCK_UNIT_SYMBOLS_HPP__


#include "unit_symbol.hpp"
#include "unit_data_concept.hpp"

#include <cstddef>


namespace zollstock
{

    struct unit_symbols
    {
        unit_symbol length;
        unit_symbol time;
        unit_symbol angle;
    };

    template <std::size_t pos>
    [[nodiscard]] constexpr unit_symbol select_symbol_entry(const unit_exponents& exponents, const unit_symbols& symbols_1, const unit_symbols& symbols_2)
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
    [[nodiscard]] constexpr auto select_symbols(
        const unit_exponents& exponents,
        const unit_symbols& symbols_1,
        const unit_symbols& symbols_2,
        std::index_sequence<indices...>
    ) noexcept
    {
        return unit_symbols{ select_symbol_entry<indices>(exponents, symbols_1, symbols_2)... };
    }

    [[nodiscard]] constexpr inline auto select_symbols(
        const unit_exponents& exponents,
        const unit_symbols& symbols_1,
        const unit_symbols& symbols_2
    ) noexcept
    {
        return select_symbols(
            exponents,
            symbols_1,
            symbols_2,
            make_dimension_index_sequence{}
        );
    }

}


#endif //__ZOLLSTOCK_UNIT_SYMBOLS_HPP__
