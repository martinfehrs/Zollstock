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

                static constexpr unit_exponents exponents{ 1, 0, 0 };
                static constexpr unit_factors factors{ Prefix::factor, 0.0L, 0.0L };
                static constexpr unit_symbols symbols{ Prefix::symbol + "m"_us, ""_us, ""_us };
            };

            using picometer  = basic_meter<pico      >;
            using nanometer  = basic_meter<nano      >;
            using micrometer = basic_meter<micro     >;
            using millimeter = basic_meter<milli     >;
            using centimeter = basic_meter<centi     >;
            using decimeter  = basic_meter<deci      >;
            using meter      = basic_meter<unprefixed>;
            using decameter  = basic_meter<deca      >;
            using hectometer = basic_meter<hecto     >;
            using kilometer  = basic_meter<kilo      >;
            using megameter  = basic_meter<mega      >;
            using gigameter  = basic_meter<giga      >;
            using terameter  = basic_meter<tera      >;

        }

        inline namespace constants
        {

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

        }

        inline namespace literals
        {

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

        }

    }

}


#endif //__ZOLLSTOCK_LENGTH_UNITS_HPP__