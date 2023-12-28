#ifndef __ZOLLSTOCK_VOLUME_UNITS_HPP__
#define __ZOLLSTOCK_VOLUME_UNITS_HPP__


#include "unit_concept.hpp"
#include "scalar.hpp"
#include "length_units.hpp"
#include "area_units.hpp"


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            using cubic_quektometer = unit_product<square_quektometer, quektometer>;
            using cubic_rontometer  = unit_product<square_rontometer , rontometer >;
            using cubic_yoktometer  = unit_product<square_yoktometer , yoktometer >;
            using cubic_zeptometer  = unit_product<square_zeptometer , zeptometer >;
            using cubic_attometer   = unit_product<square_attometer  , attometer  >;
            using cubic_femtometer  = unit_product<square_femtometer , femtometer >;
            using cubic_picometer   = unit_product<square_picometer  , picometer  >;
            using cubic_nanometer   = unit_product<square_nanometer  , nanometer  >;
            using cubic_micrometer  = unit_product<square_micrometer , micrometer >;
            using cubic_millimeter  = unit_product<square_millimeter , millimeter >;
            using cubic_centimeter  = unit_product<square_centimeter , centimeter >;
            using cubic_decimeter   = unit_product<square_decimeter  , decimeter  >;
            using cubic_meter       = unit_product<square_meter      , meter      >;
            using cubic_decameter   = unit_product<square_decameter  , decameter  >;
            using cubic_hectometer  = unit_product<square_hectometer , hectometer >;
            using cubic_kilometer   = unit_product<square_kilometer  , kilometer  >;
            using cubic_megameter   = unit_product<square_megameter  , megameter  >;
            using cubic_gigameter   = unit_product<square_gigameter  , gigameter  >;
            using cubic_terameter   = unit_product<square_terameter  , terameter  >;
            using cubic_petameter   = unit_product<square_petameter  , petameter  >;
            using cubic_exameter    = unit_product<square_exameter   , exameter   >;
            using cubic_zettameter  = unit_product<square_zettameter , zettameter >;
            using cubic_yottameter  = unit_product<square_yottameter , yottameter >;
            using cubic_ronnameter  = unit_product<square_ronnameter , ronnameter >;
            using cubic_quettameter = unit_product<square_quettameter, quettameter>;

        }

        inline namespace constants
        {

            inline constexpr cubic_quektometer qm3  {};
            inline constexpr cubic_rontometer  rm3  {};
            inline constexpr cubic_yoktometer  ym3  {};
            inline constexpr cubic_zeptometer  zm3  {};
            inline constexpr cubic_attometer   am3  {};
            inline constexpr cubic_femtometer  fm3  {};
            inline constexpr cubic_picometer   pm3  {};
            inline constexpr cubic_nanometer   nm3  {};
            inline constexpr cubic_micrometer  micm3{};
            inline constexpr cubic_millimeter  mm3  {};
            inline constexpr cubic_centimeter  cm3  {};
            inline constexpr cubic_decimeter   dm3  {};
            inline constexpr cubic_meter       m3   {};
            inline constexpr cubic_decameter   dam3 {};
            inline constexpr cubic_hectometer  hm3  {};
            inline constexpr cubic_kilometer   km3  {};
            inline constexpr cubic_megameter   Mm3  {};
            inline constexpr cubic_gigameter   Gm3  {};
            inline constexpr cubic_terameter   Tm3  {};
            inline constexpr cubic_petameter   Pm3  {};
            inline constexpr cubic_exameter    Em3  {};
            inline constexpr cubic_zettameter  Zm3  {};
            inline constexpr cubic_yottameter  Ym3  {};
            inline constexpr cubic_ronnameter  Rm3  {};
            inline constexpr cubic_quettameter Qm3  {};


        }

        inline namespace literals
        {

            [[nodiscard]] constexpr auto operator""_qm3(long double val) noexcept
            {
                return scalar<cubic_quektometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_qm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_quektometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_rm3(long double val) noexcept
            {
                return scalar<cubic_rontometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_rm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_rontometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_ym3(long double val) noexcept
            {
                return scalar<cubic_yoktometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_ym3(unsigned long long int val) noexcept
            {
                return scalar<cubic_yoktometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_zm3(long double val) noexcept
            {
                return scalar<cubic_zeptometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_zm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_zeptometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_am3(long double val) noexcept
            {
                return scalar<cubic_attometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_am3(unsigned long long int val) noexcept
            {
                return scalar<cubic_attometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_fm3(long double val) noexcept
            {
                return scalar<cubic_femtometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_fm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_femtometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_pm3(long double val) noexcept
            {
                return scalar<cubic_picometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_pm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_picometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_nm3(long double val) noexcept
            {
                return scalar<cubic_nanometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_nm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_nanometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_micm3(long double val) noexcept
            {
                return scalar<cubic_micrometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_micm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_micrometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_mm3(long double val) noexcept
            {
                return scalar<cubic_millimeter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_mm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_millimeter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_cm3(long double val) noexcept
            {
                return scalar<cubic_centimeter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_cm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_centimeter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_dm3(long double val) noexcept
            {
                return scalar<cubic_decimeter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_dm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_decimeter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_m3(long double val) noexcept
            {
                return scalar<cubic_meter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_m3(unsigned long long int val) noexcept
            {
                return scalar<cubic_meter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_dam3(long double val) noexcept
            {
                return scalar<cubic_decameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_dam3(unsigned long long int val) noexcept
            {
                return scalar<cubic_decameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_hm3(long double val) noexcept
            {
                return scalar<cubic_hectometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_hm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_hectometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_km3(long double val) noexcept
            {
                return scalar<cubic_kilometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_km3(unsigned long long int val) noexcept
            {
                return scalar<cubic_kilometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Mm3(long double val) noexcept
            {
                return scalar<cubic_megameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Mm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_megameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Gm3(long double val) noexcept
            {
                return scalar<cubic_gigameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Gm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_gigameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Tm3(long double val) noexcept
            {
                return scalar<cubic_terameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Tm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_terameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Pm3(long double val) noexcept
            {
                return scalar<cubic_petameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Pm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_petameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Em3(long double val) noexcept
            {
                return scalar<cubic_exameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Em3(unsigned long long int val) noexcept
            {
                return scalar<cubic_exameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Zm3(long double val) noexcept
            {
                return scalar<cubic_zettameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Zm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_zettameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Ym3(long double val) noexcept
            {
                return scalar<cubic_yottameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Ym3(unsigned long long int val) noexcept
            {
                return scalar<cubic_yottameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Rm3(long double val) noexcept
            {
                return scalar<cubic_ronnameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Rm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_ronnameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Qm3(long double val) noexcept
            {
                return scalar<cubic_quettameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Qm3(unsigned long long int val) noexcept
            {
                return scalar<cubic_quettameter>{ static_cast<double>(val) };
            }

        }

    }

}


#endif //__ZOLLSTOCK_VOLUME_UNITS_HPP__
