#ifndef __ZOLLSTOCK_STATIC_STRING_HPP__
#define __ZOLLSTOCK_STATIC_STRING_HPP__


#include <cstddef>


namespace zollstock
{

    struct unterminated_string : std::exception
    {
        const char* what() const noexcept override
        {
            return "unterminated string";
        }
    };

    class static_string
    {

    public:

        using value_type = char;
        using size_type = std::size_t;
        using const_pointer = const value_type*;

    private:

        static constexpr size_type storage_size = 8;

        template <std::size_t size>
        [[nodiscard]] static constexpr size_type strlen(const value_type (&str)[size]) noexcept
        {
            for(size_type i = 0; i < size; ++i)
                if(str[i] == '\0')
                    return i;

            return size;
        }

    public:

        constexpr static_string() noexcept
            : data_{}
            , size_{}
        {}

        template <std::size_t size> requires(size <= storage_size)
        constexpr static_string(const value_type (&str)[size])
            : data_{}
            , size_{ strlen(str) }
        {
            if(this->size_ == size)
                throw unterminated_string{};

            for(size_type i = 0; i < size_; ++i)
                this->data_[i] = str[i];
        }

        [[nodiscard]] constexpr size_type size() const noexcept
        {
            return this->size_;
        }

        [[nodiscard]] constexpr const_pointer c_str() const noexcept
        {
            return this->data_;
        }

        [[nodiscard]] constexpr int compare(const static_string& that) const noexcept
        {
            return std::char_traits<char>::compare(
                this->data_, that.data_, std::min(this->size_, that.size_)
            );
        }

        [[nodiscard]] constexpr bool operator==(const static_string& that) const noexcept
        {
            if(this->size_ != that.size_)
                return false;

            return this->compare(that) == 0;
        }

        [[nodiscard]] constexpr bool operator!=(const static_string& that) const noexcept
        {
            return !(*this == that);
        }

        [[nodiscard]] constexpr bool operator<(const static_string& that) const noexcept
        {
            const int comparison_result = this->compare(that);

            return comparison_result < 0 || comparison_result == 0 && this->size_ < that.size_;
        }

        [[nodiscard]] constexpr static_string operator+(const static_string& that) const noexcept
        {
            static_string result{ *this };

            for (size_type i = 0; i < that.size_; ++i)
                result.data_[i + result.size_] = that.data_[i];

            result.size_ += that.size_;

            return result;
        }

        value_type data_[storage_size];
        size_type size_;

    };

}


#endif //__ZOLLSTOCK_STATIC_STRING_HPP__
