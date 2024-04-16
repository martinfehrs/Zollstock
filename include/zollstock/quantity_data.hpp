#ifndef __ZOLLSTOCK_QUANTITY_DATA_HPP__
#define __ZOLLSTOCK_QUANTITY_DATA_HPP__


#include <zollstock/unit_symbol.hpp>

#include <cstddef>


namespace zollstock
{

    enum class quantity
    {
        angle,
        length,
        time,
        mass,
    };



    struct quantity_data
    {
        quantity quantity_;
        int exponent;
        long double factor;
        unit_symbol symbol;

        [[nodiscard]] consteval bool operator==(const quantity_data&) const noexcept = default;

        [[nodiscard]] consteval quantity_data operator*(const quantity_data& that) const
        {
            if(this->quantity_ != that.quantity_)
                throw "incompatible quantities";

            return {
                this->quantity_,
                this->exponent + that.exponent,
                this->factor != 0 ? this->factor : that.factor,
                this->select_symbol(that)
            };
        }

        [[nodiscard]] consteval const quantity_data& operator()() const noexcept
        {
            return *this;
        }

    private:

        [[nodiscard]] consteval unit_symbol select_symbol(const quantity_data& that) const
        {
            if (this->exponent + that.exponent == 0)
            {
                return ""_us;
            }
            else if (this->symbol.size() == 0)
            {
                return that.symbol;
            }
            else if (that.symbol.size() == 0)
            {
                return this->symbol;
            }
            else if (this->symbol == that.symbol)
            {
                return this->symbol;
            }
            else
            {
                throw "incompatible symbols";
            }
        }

    };

    [[nodiscard]] consteval quantity_data pow(const quantity_data& udat, int exponent) noexcept
    {
        return { udat.quantity_, udat.exponent * exponent, udat.factor, udat.symbol };
    }

    [[nodiscard]] consteval quantity_data operator/(
        const quantity_data& udat_1,const quantity_data& udat_2
    ) noexcept
    {
        return udat_1 * pow(udat_2, -1);
    }

}


#endif //__ZOLLSTOCK_QUANTITY_DATA_HPP__
