#ifndef __ZOLLSTOCK_FLOATING_POINT_UTILITIES_HPP__
#define __ZOLLSTOCK_FLOATING_POINT_UTILITIES_HPP__


#include <concepts>
#include <limits>
#include <sstream>
#include <utility>


namespace zollstock
{

    template <typename Candidate>
    concept number_c = std::same_as<Candidate, unsigned             char>
                    || std::smae_as<Candidate, signed               char>
                    || std::same_as<Candidate, unsigned              int>
                    || std::same_as<Candidate, signed                int>
                    || std::same_as<Candidate, unsigned short        int>
                    || std::same_as<Candidate, signed   short        int>
                    || std::same_as<Candidate, unsigned long         int>
                    || std::same_as<Candidate, signed   long         int>
                    || std::same_as<Candidate, unsigned long long    int>
                    || std::same_as<Candidate, signed   long long    int>
                    || std::same_as<Candidate,                     float>
                    || std::same_as<Candidate,                    double>
                    || std::same_as<Candidate,          long      double>;


    template <number_c Number>
    [[nodiscard]] consteval const char* number_type_name() noexcept
    {
        if constexpr(std::same_as<Number, short int>)
        {
            return "short int";
        }
        else
        if constexpr(std::same_as<Number, int>)
        {
            return "int";
        }
        else
        if constexpr(std::same_as<Number, long int>)
        {
            return "long int";
        }
        else
        if constexpr(std::same_as<Number, long long int>)
        {
            return "long long int";
        }
        else
        if constexpr(std::same_as<Number, unsigned short int>)
        {
            return "unsigned short int";
        }
        else
        if constexpr(std::same_as<Number, unsigned int>)
        {
            return "unsigned int";
        }
        else
        if constexpr(std::same_as<Number, unsigned long int>)
        {
            return "unsigned long int";
        }
        else
        if constexpr(std::same_as<Number, unsigned long long int>)
        {
            return "unsigned long long int";
        }
        else
        if constexpr(std::same_as<Number, float>)
        {
            return "float";
        }
        else
        if constexpr(std::same_as<Number, double>)
        {
            return "double";
        }
        else
        if constexpr(std::same_as<Number, long double>)
        {
            return "long double";
        }
        else
        {
            return "unknown";
        }
    }


    template <number_c Candidate>
    inline constexpr bool is_iec559_v = std::numeric_limits<Candidate>::is_iec559;


    template <std::integral Int>
    struct int_range
    {
        Int min = 0;
        Int max = 0;

        [[nodiscard]] constexpr bool contains(std::integral auto val) const noexcept
        {
            return std::cmp_greater_equal(val, this->min) &&
                   std::cmp_less_equal   (val, this->max);
        }

        template <typename Int2>
        [[nodiscard]] constexpr bool contains(const int_range<Int2>& that) const noexcept
        {
            return this->contains(that.min) && this->contains(that.max);
        }
    };

    template <std::integral Int>
    int_range(Int, Int) -> int_range<Int>;

    namespace detail
    {

        template <number_c Number>
        [[nodiscard]] consteval auto continous_int_range() noexcept
        {
            if constexpr(std::integral<Number>)
            {
                return int_range{
                    std::numeric_limits<Number>::min(),
                    std::numeric_limits<Number>::max()
                };
            }
            else if constexpr(is_iec559_v<Number> && std::same_as<Number, float>)
            {
                return int_range{ -16777216LL, 16777216LL };
            }
            else if constexpr(is_iec559_v<Number> && std::same_as<Number, double>)
            {
                return int_range{ -9'007'199'254'740'992LL, 9'007'199'254'740'992LL };
            }
            else if constexpr(is_iec559_v<Number> && std::same_as<Number, long double>)
            {
                return int_range{ -9'007'199'254'740'992LL, 9'007'199'254'740'992LL };
            }
            else
            {
                return int_range{ 0, 0 };
            }
        }

    }

    template <typename Candidate>
    inline constexpr auto continous_int_range_v = detail::continous_int_range<Candidate>();


    namespace detail
    {

        template <number_c Source, number_c Target>
        [[nodiscard]] consteval bool lossless_convertible() noexcept
        {
            if constexpr(std::same_as<Source, Target>)
            {
                return true;
            }
            else if constexpr(std::floating_point<Source> && std::integral<Target>)
            {
                return false;
            }
            else if constexpr(std::same_as<Source, float> && std::same_as<Target, double>)
            {
                return true;
            }
            else if constexpr(std::same_as<Source, float> && std::same_as<Target, long double>)
            {
                return true;
            }
            else if constexpr(std::same_as<Source, double> && std::same_as<Target, long double>)
            {
                return true;
            }
            else if constexpr(std::integral<Source>)
            {
                return continous_int_range_v<Target>.contains(continous_int_range_v<Source>);
            }
            else
            {
                return false;
            }
        }

    }

    template <number_c Source, number_c Target>
    inline constexpr bool lossless_convertible_v = detail::lossless_convertible<Source, Target>();

    template <number_c Source, number_c Target>
    class narrowing_conversion : public std::exception
    {

    public:

        narrowing_conversion(Source source, Target target)
            : source{ source }
            , target{ target }
            , message{ build_message(source, target) }
        { }

        [[nodiscard]] const char* what() const noexcept override
        {
            return this->message.c_str();
        }

        Source source;
        Target target;

    private:

        static std::string build_message(Source source, Target target) noexcept
        {
            std::stringstream ss;

            ss << "Narrowing conversion from "
               << number_type_name<Source>()
               << " "
               << source
               << " to "
               << number_type_name<Target>()
               << " "
               << target;

            return ss.str();
        }

        std::string message;

    };

    template <number_c Target, number_c Source>
    [[nodiscard]] constexpr Target narrow(
        Source source
    ) noexcept(lossless_convertible_v<Source, Target>)
    {
        if constexpr(lossless_convertible_v<Source, Target>)
        {
            return static_cast<Target>(source);
        }
        else
        {
            auto target = static_cast<Target>(source);

            if(static_cast<Source>(target) != source)
                throw narrowing_conversion{ source, target };

            if (
                std::is_signed_v<Source> != std::is_signed_v<Target> &&
                (target < Target{}) != (source < Source{})
            )
            {
                throw narrowing_conversion{ source, target };
            }

            return target;
        }
    }



    template <number_c Number1, number_c Number2>
    [[nodiscard]] constexpr bool cmp_equal(Number1 number_1, Number2 number_2) noexcept
    {
        if constexpr(std::integral<Number1> && std::integral<Number2>)
        {
            return std::cmp_equal(number_1, number_2);
        }
        else
        {
            return number_1 == number_2;
        }
    }

    template <number_c Number1, number_c Number2>
    [[nodiscard]] constexpr bool cmp_not_equal(Number1 number_1, Number2 number_2) noexcept
    {
        if constexpr(std::integral<Number1> && std::integral<Number2>)
        {
            return std::cmp_not_equal(number_1, number_2);
        }
        else
        {
            return number_1 != number_2;
        }
    }

    template <number_c Number1, number_c Number2>
    [[nodiscard]] constexpr bool cmp_less(Number1 number_1, Number2 number_2) noexcept
    {
        if constexpr(std::integral<Number1> && std::integral<Number2>)
        {
            return std::cmp_less(number_1, number_2);
        }
        else
        {
            return number_1 < number_2;
        }
    }

    template <number_c Number1, number_c Number2>
    [[nodiscard]] constexpr bool cmp_greater(Number1 number_1, Number2 number_2) noexcept
    {
        if constexpr(std::integral<Number1> && std::integral<Number2>)
        {
            return std::cmp_greater(number_1, number_2);
        }
        else
        {
            return number_1 > number_2;
        }
    }

    template <number_c Number1, number_c Number2>
    [[nodiscard]] constexpr bool cmp_less_equal(Number1 number_1, Number2 number_2) noexcept
    {
        if constexpr(std::integral<Number1> && std::integral<Number2>)
        {
            return std::cmp_less_equal(number_1, number_2);
        }
        else
        {
            return number_1 <= number_2;
        }
    }

    template <number_c Number1, number_c Number2>
    [[nodiscard]] constexpr bool cmp_greater_equal(Number1 number_1, Number2 number_2) noexcept
    {
        if constexpr(std::integral<Number1> && std::integral<Number2>)
        {
            return std::cmp_greater_equal(number_1, number_2);
        }
        else
        {
            return number_1 >= number_2;
        }
    }

}


#endif //__ZOLLSTOCK_FLOATING_POINT_UTILITIES_HPP__
