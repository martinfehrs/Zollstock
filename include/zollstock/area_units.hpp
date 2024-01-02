#ifndef __ZOLLSTOCK_AREA_UNITS_HPP__
#define __ZOLLSTOCK_AREA_UNITS_HPP__


#include <zollstock/length_units.hpp>
#include <zollstock/scalar.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            using square_quektometer = unit_product<quektometer, quektometer>;
            using square_rontometer  = unit_product<rontometer , rontometer >;
            using square_yoktometer  = unit_product<yoktometer , yoktometer >;
            using square_zeptometer  = unit_product<zeptometer , zeptometer >;
            using square_attometer   = unit_product<attometer  , attometer  >;
            using square_femtometer  = unit_product<femtometer , femtometer >;
            using square_picometer   = unit_product<picometer  , picometer  >;
            using square_nanometer   = unit_product<nanometer  , nanometer  >;
            using square_micrometer  = unit_product<micrometer , micrometer >;
            using square_millimeter  = unit_product<millimeter , millimeter >;
            using square_centimeter  = unit_product<centimeter , centimeter >;
            using square_decimeter   = unit_product<decimeter  , decimeter  >;
            using square_meter       = unit_product<meter      , meter      >;
            using square_decameter   = unit_product<decameter  , decameter  >;
            using square_hectometer  = unit_product<hectometer , hectometer >;
            using square_kilometer   = unit_product<kilometer  , kilometer  >;
            using square_megameter   = unit_product<megameter  , megameter  >;
            using square_gigameter   = unit_product<gigameter  , gigameter  >;
            using square_terameter   = unit_product<terameter  , terameter  >;
            using square_petameter   = unit_product<petameter  , petameter  >;
            using square_exameter    = unit_product<exameter   , exameter   >;
            using square_zettameter  = unit_product<zettameter , zettameter >;
            using square_yottameter  = unit_product<yottameter , yottameter >;
            using square_ronnameter  = unit_product<ronnameter , ronnameter >;
            using square_quettameter = unit_product<quettameter, quettameter>;

        }

        inline namespace constants
        {

            inline constexpr square_quektometer qm2  {};
            inline constexpr square_rontometer  rm2  {};
            inline constexpr square_yoktometer  ym2  {};
            inline constexpr square_zeptometer  zm2  {};
            inline constexpr square_attometer   am2  {};
            inline constexpr square_femtometer  fm2  {};
            inline constexpr square_picometer   pm2  {};
            inline constexpr square_nanometer   nm2  {};
            inline constexpr square_micrometer  micm2{};
            inline constexpr square_millimeter  mm2  {};
            inline constexpr square_centimeter  cm2  {};
            inline constexpr square_decimeter   dm2  {};
            inline constexpr square_meter       m2   {};
            inline constexpr square_decameter   dam2 {};
            inline constexpr square_hectometer  hm2  {};
            inline constexpr square_kilometer   km2  {};
            inline constexpr square_megameter   Mm2  {};
            inline constexpr square_gigameter   Gm2  {};
            inline constexpr square_terameter   Tm2  {};
            inline constexpr square_petameter   Pm2  {};
            inline constexpr square_exameter    Em2  {};
            inline constexpr square_zettameter  Zm2  {};
            inline constexpr square_yottameter  Ym2  {};
            inline constexpr square_ronnameter  Rm2  {};
            inline constexpr square_quettameter Qm2  {};

        }

        inline namespace literals
        {

            [[nodiscard]] constexpr auto operator""_qm2(long double val) noexcept
            {
                return scalar<square_quektometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_qm2(unsigned long long int val) noexcept
            {
                return scalar<square_quektometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_rm2(long double val) noexcept
            {
                return scalar<square_rontometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_rm2(unsigned long long int val) noexcept
            {
                return scalar<square_rontometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_ym2(long double val) noexcept
            {
                return scalar<square_yoktometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_ym2(unsigned long long int val) noexcept
            {
                return scalar<square_yoktometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_zm2(long double val) noexcept
            {
                return scalar<square_zeptometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_zm2(unsigned long long int val) noexcept
            {
                return scalar<square_zeptometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_am2(long double val) noexcept
            {
                return scalar<square_attometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_am2(unsigned long long int val) noexcept
            {
                return scalar<square_attometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_fm2(long double val) noexcept
            {
                return scalar<square_femtometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_fm2(unsigned long long int val) noexcept
            {
                return scalar<square_femtometer>{ static_cast<double>(val) };
            }


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


            [[nodiscard]] constexpr auto operator""_Pm2(long double val) noexcept
            {
                return scalar<square_petameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Pm2(unsigned long long int val) noexcept
            {
                return scalar<square_petameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Em2(long double val) noexcept
            {
                return scalar<square_exameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Em2(unsigned long long int val) noexcept
            {
                return scalar<square_exameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Zm2(long double val) noexcept
            {
                return scalar<square_zettameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Zm2(unsigned long long int val) noexcept
            {
                return scalar<square_zettameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Ym2(long double val) noexcept
            {
                return scalar<square_yottameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Ym2(unsigned long long int val) noexcept
            {
                return scalar<square_yottameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Rm2(long double val) noexcept
            {
                return scalar<square_ronnameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Rm2(unsigned long long int val) noexcept
            {
                return scalar<square_ronnameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Qm2(long double val) noexcept
            {
                return scalar<square_quettameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Qm2(unsigned long long int val) noexcept
            {
                return scalar<square_quettameter>{ static_cast<double>(val) };
            }

        }

    }

}


#endif //__ZOLLSTOCK_AREA_UNITS_HPP__
