#ifndef __ZOLLSTOCK_FLOATING_POINT_UTILITIES_HPP__
#define __ZOLLSTOCK_FLOATING_POINT_UTILITIES_HPP__


#include <concepts>
#include <limits>

namespace zollstock
{

    template <typename Candidate>
    concept arithmetic_c = std::is_arithmetic_v<Candidate>;


    template <arithmetic_c Candidate>
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

        template <arithmetic_c Number>
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

        template <arithmetic_c Source, arithmetic_c Target>
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
            else if constexpr(std::same_as<Source, float>, std::same_as<Target, double>)
            {
                return true;
            }
            else if constexpr(std::same_as<Source, float>, std::same_as<Target, long double>)
            {
                return true;
            }
            else if constexpr(std::same_as<Source, double>, std::same_as<Target, long double>)
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

    template <arithmetic_c Source, arithmetic_c Target>
    inline constexpr bool lossless_convertible_v = detail::lossless_convertible<Source, Target>();



    template <arithmetic_c Target, arithmetic_c Source>
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
                throw "Narrowing conversion";

            if (
                std::is_signed_v<Source> != std::is_signed_v<Target> &&
                (target < Target{}) != (source < Source{})
            )
            {
                throw "Narrowing conversion";
            }

            return target;
        }
    }

}


#endif //__ZOLLSTOCK_FLOATING_POINT_UTILITIES_HPP__
