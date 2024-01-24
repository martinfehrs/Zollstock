#ifndef __ZOLLSTOCK_FLOATING_POINT_UTILITIES_HPP__
#define __ZOLLSTOCK_FLOATING_POINT_UTILITIES_HPP__


#include <concepts>


namespace zollstock
{

    template <std::floating_point Source, std::floating_point Target>
    inline constexpr bool fits_into_v = false;

    template <std::floating_point Float>
    inline constexpr bool fits_into_v<Float, Float> = true;

    template <>
    inline constexpr bool fits_into_v<float, double> = true;

    template <>
    inline constexpr bool fits_into_v<float, long double> = true;

    template <>
    inline constexpr bool fits_into_v<double, long double> = true;



    template <std::floating_point Target, std::floating_point Source>
    [[nodiscard]] constexpr Target narrow(Source source) noexcept(fits_into_v<Source, Target>)
    {
        if constexpr(fits_into_v<Source, Target>)
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
