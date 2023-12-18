#ifndef __ZOLLSTOCK_AREA_UNITS_HPP__
#define __ZOLLSTOCK_AREA_UNITS_HPP__


#include "length_units.hpp"
#include "scalar.hpp"


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            using square_picometer  = unit_product<picometer , picometer >;
            using square_nanometer  = unit_product<nanometer , nanometer >;
            using square_micrometer = unit_product<micrometer, micrometer>;
            using square_millimeter = unit_product<millimeter, millimeter>;
            using square_centimeter = unit_product<centimeter, centimeter>;
            using square_decimeter  = unit_product<decimeter , decimeter >;
            using square_meter      = unit_product<meter     , meter     >;
            using square_decameter  = unit_product<decameter , decameter >;
            using square_hectometer = unit_product<hectometer, hectometer>;
            using square_kilometer  = unit_product<kilometer , kilometer >;
            using square_megameter  = unit_product<megameter , megameter >;
            using square_gigameter  = unit_product<gigameter , gigameter >;
            using square_terameter  = unit_product<terameter , terameter >;
        
        }

        inline namespace constants
        {

            inline constexpr square_picometer  pm2   {};
            inline constexpr square_nanometer  nm2   {};
            inline constexpr square_micrometer micm2 {};
            inline constexpr square_millimeter mm2   {};
            inline constexpr square_centimeter cm2   {};
            inline constexpr square_decimeter  dm2   {};
            inline constexpr square_meter      m2    {};
            inline constexpr square_decameter  dam2  {};
            inline constexpr square_hectometer hm2   {};
            inline constexpr square_kilometer  km2   {};
            inline constexpr square_megameter  Mm2   {};
            inline constexpr square_gigameter  Gm2   {};
            inline constexpr square_terameter  Tm2   {};

        }

        inline namespace literals
        {

            [[nodiscard]] constexpr auto operator""_pm2(long double val) noexcept
            {
                return scalar<square_picometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_pm2(unsigned long long int val) noexcept
            {
                return scalar<square_picometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_nm2(long double val) noexcept
            {
                return scalar<square_nanometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_nm2(unsigned long long int val) noexcept
            {
                return scalar<square_nanometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_micm2(long double val) noexcept
            {
                return scalar<square_micrometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_micm2(unsigned long long int val) noexcept
            {
                return scalar<square_micrometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_mm2(long double val) noexcept
            {
                return scalar<square_millimeter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_mm2(unsigned long long int val) noexcept
            {
                return scalar<square_millimeter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_cm2(long double val) noexcept
            {
                return scalar<square_centimeter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_cm2(unsigned long long int val) noexcept
            {
                return scalar<square_centimeter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_dm2(long double val) noexcept
            {
                return scalar<square_decimeter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_dm2(unsigned long long int val) noexcept
            {
                return scalar<square_decimeter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_m2(long double val) noexcept
            {
                return scalar<square_meter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_m2(unsigned long long int val) noexcept
            {
                return scalar<square_meter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_dam2(long double val) noexcept
            {
                return scalar<square_decameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_dam2(unsigned long long int val) noexcept
            {
                return scalar<square_decameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_hm2(long double val) noexcept
            {
                return scalar<square_hectometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_hm2(unsigned long long int val) noexcept
            {
                return scalar<square_hectometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_km2(long double val) noexcept
            {
                return scalar<square_kilometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_km2(unsigned long long int val) noexcept
            {
                return scalar<square_kilometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Mm2(long double val) noexcept
            {
                return scalar<square_megameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Mm2(unsigned long long int val) noexcept
            {
                return scalar<square_megameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Gm2(long double val) noexcept
            {
                return scalar<square_gigameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Gm2(unsigned long long int val) noexcept
            {
                return scalar<square_gigameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Tm2(long double val) noexcept
            {
                return scalar<square_terameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Tm2(unsigned long long int val) noexcept
            {
                return scalar<square_terameter>{ static_cast<double>(val) };
            }

        }

    }

}


#endif //__ZOLLSTOCK_AREA_UNITS_HPP__