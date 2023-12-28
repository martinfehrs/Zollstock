#ifndef __ZOLLSTOCK_LENGTH_UNITS_HPP__
#define __ZOLLSTOCK_LENGTH_UNITS_HPP__


#include "scalar.hpp"
#include "unit_prefix_concept.hpp"
#include "si_prefixes.hpp"


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            template <typename Prefix>
            struct basic_meter
            {
                static_assert(is_prefix_v<Prefix>);

                static constexpr quantity_exponents exponents{ 1, 0, 0 };
                static constexpr quantity_factors factors{ Prefix::factor, 0.0L, 0.0L };
                static constexpr quantity_symbols symbols{ Prefix::symbol + "m"_us, ""_us, ""_us };
            };

            using quektometer = basic_meter<quekto    >;
            using rontometer  = basic_meter<ronto     >;
            using yoktometer  = basic_meter<yokto     >;
            using zeptometer  = basic_meter<zepto     >;
            using attometer   = basic_meter<atto      >;
            using femtometer  = basic_meter<femto     >;
            using picometer   = basic_meter<pico      >;
            using nanometer   = basic_meter<nano      >;
            using micrometer  = basic_meter<micro     >;
            using millimeter  = basic_meter<milli     >;
            using centimeter  = basic_meter<centi     >;
            using decimeter   = basic_meter<deci      >;
            using meter       = basic_meter<unprefixed>;
            using decameter   = basic_meter<deca      >;
            using hectometer  = basic_meter<hecto     >;
            using kilometer   = basic_meter<kilo      >;
            using megameter   = basic_meter<mega      >;
            using gigameter   = basic_meter<giga      >;
            using terameter   = basic_meter<tera      >;
            using petameter   = basic_meter<peta      >;
            using exameter    = basic_meter<exa       >;
            using zettameter  = basic_meter<zetta     >;
            using yottameter  = basic_meter<yotta     >;
            using ronnameter  = basic_meter<ronna     >;
            using quettameter = basic_meter<quetta    >;

        }

        inline namespace constants
        {

            inline constexpr quektometer qm   {};
            inline constexpr rontometer  rm   {};
            inline constexpr yoktometer  ym   {};
            inline constexpr zeptometer  zm   {};
            inline constexpr attometer   am   {};
            inline constexpr femtometer  fm   {};
            inline constexpr picometer   pm   {};
            inline constexpr nanometer   nm   {};
            inline constexpr micrometer  micm {};
            inline constexpr millimeter  mm   {};
            inline constexpr centimeter  cm   {};
            inline constexpr decimeter   dm   {};
            inline constexpr meter       m    {};
            inline constexpr decameter   dam  {};
            inline constexpr hectometer  hm   {};
            inline constexpr kilometer   km   {};
            inline constexpr megameter   Mm   {};
            inline constexpr gigameter   Gm   {};
            inline constexpr terameter   Tm   {};
            inline constexpr petameter   Pm   {};
            inline constexpr exameter    Em   {};
            inline constexpr zettameter  Zm   {};
            inline constexpr yottameter  Ym   {};
            inline constexpr ronnameter  Rm   {};
            inline constexpr quettameter Qm   {};

        }

        inline namespace literals
        {

            [[nodiscard]] constexpr auto operator""_qm(long double val) noexcept
            {
                return scalar<quektometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_qm(unsigned long long int val) noexcept
            {
                return scalar<quektometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_rm(long double val) noexcept
            {
                return scalar<rontometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_rm(unsigned long long int val) noexcept
            {
                return scalar<rontometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_ym(long double val) noexcept
            {
                return scalar<yoktometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_ym(unsigned long long int val) noexcept
            {
                return scalar<yoktometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_zm(long double val) noexcept
            {
                return scalar<zeptometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_zm(unsigned long long int val) noexcept
            {
                return scalar<zeptometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_am(long double val) noexcept
            {
                return scalar<attometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_am(unsigned long long int val) noexcept
            {
                return scalar<attometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_fm(long double val) noexcept
            {
                return scalar<femtometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_fm(unsigned long long int val) noexcept
            {
                return scalar<femtometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_pm(long double val) noexcept
            {
                return scalar<picometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_pm(unsigned long long int val) noexcept
            {
                return scalar<picometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_nm(long double val) noexcept
            {
                return scalar<nanometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_nm(unsigned long long int val) noexcept
            {
                return scalar<nanometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_micm(long double val) noexcept
            {
                return scalar<micrometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_micm(unsigned long long int val) noexcept
            {
                return scalar<micrometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_mm(long double val) noexcept
            {
                return scalar<millimeter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_mm(unsigned long long int val) noexcept
            {
                return scalar<millimeter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_cm(long double val) noexcept
            {
                return scalar<centimeter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_cm(unsigned long long int val) noexcept
            {
                return scalar<centimeter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_dm(long double val) noexcept
            {
                return scalar<decimeter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_dm(unsigned long long int val) noexcept
            {
                return scalar<decimeter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_m(long double val) noexcept
            {
                return scalar<meter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_m(unsigned long long int val) noexcept
            {
                return scalar<meter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_dam(long double val) noexcept
            {
                return scalar<decameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_dam(unsigned long long int val) noexcept
            {
                return scalar<decameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_hm(long double val) noexcept
            {
                return scalar<hectometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_hm(unsigned long long int val) noexcept
            {
                return scalar<hectometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_km(long double val) noexcept
            {
                return scalar<kilometer>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_km(unsigned long long int val) noexcept
            {
                return scalar<kilometer>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Mm(long double val) noexcept
            {
                return scalar<megameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Mm(unsigned long long int val) noexcept
            {
                return scalar<megameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Gm(long double val) noexcept
            {
                return scalar<gigameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Gm(unsigned long long int val) noexcept
            {
                return scalar<gigameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Tm(long double val) noexcept
            {
                return scalar<terameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Tm(unsigned long long int val) noexcept
            {
                return scalar<terameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Pm(long double val) noexcept
            {
                return scalar<petameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Pm(unsigned long long int val) noexcept
            {
                return scalar<petameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Em(long double val) noexcept
            {
                return scalar<exameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Em(unsigned long long int val) noexcept
            {
                return scalar<exameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Zm(long double val) noexcept
            {
                return scalar<zettameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Zm(unsigned long long int val) noexcept
            {
                return scalar<zettameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Ym(long double val) noexcept
            {
                return scalar<yottameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Ym(unsigned long long int val) noexcept
            {
                return scalar<yottameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Rm(long double val) noexcept
            {
                return scalar<ronnameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Rm(unsigned long long int val) noexcept
            {
                return scalar<ronnameter>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Qm(long double val) noexcept
            {
                return scalar<quettameter>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Qm(unsigned long long int val) noexcept
            {
                return scalar<quettameter>{ static_cast<double>(val) };
            }

        }

    }

}


#endif //__ZOLLSTOCK_LENGTH_UNITS_HPP__
