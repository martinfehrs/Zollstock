#ifndef __ZOLLSTOCK_UNIT_SYMBOL_HPP__
#define __ZOLLSTOCK_UNIT_SYMBOL_HPP__


#include <cstddef>


namespace zollstock
{

    class unit_symbol
    {

    public:

        using value_type = char;
        using size_type = std::size_t;
        using const_pointer = const value_type*;

    private:

        static constexpr size_type storage_size = 8;

    public:

        constexpr unit_symbol() noexcept
            : data{}
            , size_{}
        {}

        constexpr unit_symbol(const_pointer str, std::size_t size) noexcept
            : data{}
            , size_{ size }
        {
            for(size_type i = 0; i < size; ++i)
                this->data[i] = str[i];
        }

        constexpr unit_symbol(const unit_symbol& that) noexcept = default;

        [[nodiscard]] constexpr size_type size() const noexcept
        {
            return this->size_;
        }

        [[nodiscard]] constexpr const_pointer c_str() const noexcept
        {
            return this->data;
        }

        /*[[nodiscard]]*/ constexpr bool operator==(const unit_symbol& that) const noexcept
        {
            bool equal = true;

            for(size_type i = 0; i < this->size_; ++i)
                equal = equal && (this->data[i] == that.data[i]);

            return equal;
        }

        [[nodiscard]] constexpr unit_symbol operator+(const unit_symbol& that) const noexcept
        {
            unit_symbol result{ *this };

            for(size_type i = 0; i < that.size_; ++i)
                result.data[i + result.size_] = that.data[i];

            result.size_ += that.size_;

            return result;
        }

    private:

        value_type data[storage_size];
        size_type size_;

    };

    [[nodiscard]] constexpr unit_symbol operator""_us(const char* str, std::size_t size) noexcept
    {
        return { str, size };
    }

}


#endif //__ZOLLSTOCK_UNIT_SYMBOL_HPP__
