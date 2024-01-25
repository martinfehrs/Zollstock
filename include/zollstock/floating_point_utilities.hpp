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


    template <arithmetic_c Candidate, typename = void>
    struct min_int_range
    {
        static constexpr int_range value{ 0, 0 };
    };

    template <arithmetic_c Candidate>
    struct min_int_range<Candidate, std::enable_if_t<std::is_integral_v<Candidate>>>
    {
        static constexpr int_range value{
            std::numeric_limits<Candidate>::min(),
            std::numeric_limits<Candidate>::max()
        };
    };

    template <>
    struct min_int_range<float, std::enable_if_t<is_iec559_v<float>>>
    {
        static constexpr int_range value{ -16777216LL, 16777216LL };
    };

    template <>
    struct min_int_range<double, std::enable_if_t<is_iec559_v<double>>>
    {
        static constexpr int_range value{ -9'007'199'254'740'992LL, 9'007'199'254'740'992LL };
    };

    // Muss überarbeitet werden
    template <>
    struct min_int_range<long double, std::enable_if_t<is_iec559_v<double>>>
    {
        static constexpr int_range value{ -9'007'199'254'740'992LL, 9'007'199'254'740'992LL };
    };

    template <typename Candidate>
    inline constexpr auto min_int_range_v = min_int_range<Candidate>::value;



    template <arithmetic_c Source, std::floating_point Target>
    inline constexpr bool lossless_convertible_v = false;

    template <std::floating_point Float>
    inline constexpr bool lossless_convertible_v<Float, Float> = true;

    template <>
    inline constexpr bool lossless_convertible_v<float, double> = true;

    template <>
    inline constexpr bool lossless_convertible_v<float, long double> = true;

    template <>
    inline constexpr bool lossless_convertible_v<double, long double> = true;

    template <std::integral Int>
    inline constexpr bool lossless_convertible_v<Int, float> =
        min_int_range_v<float>.contains(min_int_range_v<Int>);

    template <std::integral Int>
    inline constexpr bool lossless_convertible_v<Int, double> =
        min_int_range_v<double>.contains(min_int_range_v<Int>);

    template <std::integral Int>
    inline constexpr bool lossless_convertible_v<Int, long double> =
        min_int_range_v<long double>.contains(min_int_range_v<Int>);



    template <std::floating_point Target, arithmetic_c Source>
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

            return target;
        }
    }

}


#endif //__ZOLLSTOCK_FLOATING_POINT_UTILITIES_HPP__
