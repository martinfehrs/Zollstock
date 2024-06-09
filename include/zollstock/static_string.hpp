#ifndef __ZOLLSTOCK_STATIC_STRING_HPP__
#define __ZOLLSTOCK_STATIC_STRING_HPP__


#include <cstddef>


namespace zollstock
{

    class static_string
    {

    public:

        using value_type = char;
        using size_type = std::size_t;
        using const_pointer = const value_type*;

    private:

        static constexpr size_type storage_size = 8;

    public:

        constexpr static_string() noexcept
            : data_{}
            , size_{}
        {}

        constexpr static_string(const_pointer str, std::size_t size) noexcept
            : data_{}
            , size_{ size }
        {
            for(size_type i = 0; i < size; ++i)
                this->data_[i] = str[i];
        }

        template <std::size_t size>
        constexpr static_string(const value_type (&str)[size]) noexcept
            : static_string{ str, size - 1 }
        { }

        [[nodiscard]] constexpr size_type size() const noexcept
        {
            return this->size_;
        }

        [[nodiscard]] constexpr const_pointer c_str() const noexcept
        {
            return this->data_;
        }

        [[nodiscard]] constexpr bool operator==(const static_string& that) const noexcept
        {
            if(this->size_ != that.size_)
                return false;

            bool equal = true;

            for(size_type i = 0; i < this->size_; ++i)
                equal = equal && (this->data_[i] == that.data_[i]);

            return equal;
        }

        [[nodiscard]] constexpr static_string operator+(const static_string& that) const noexcept
        {
            static_string result{ *this };

            for(size_type i = 0; i < that.size_; ++i)
                result.data_[i + result.size_] = that.data_[i];

            result.size_ += that.size_;

            return result;
        }

        value_type data_[storage_size];
        size_type size_;

    };

}


#endif //__ZOLLSTOCK_STATIC_STRING_HPP__
