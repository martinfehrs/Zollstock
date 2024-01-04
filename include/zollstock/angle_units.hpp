#ifndef __ZOLLSTOCK_ANGLE_UNITS_HPP__
#define __ZOLLSTOCK_ANGLE_UNITS_HPP__


#include <zollstock/scalar.hpp>
#include <zollstock/unit_prefix_concept.hpp>
#include <zollstock/si_prefixes.hpp>


namespace zollstock
{

    inline namespace math_constants
    {

        inline constexpr long double pi{ 3.14159265358979323846264338327950288419716939937510L };

    }

    inline namespace unit
    {

        inline namespace types
        {

            template <typename Prefix>
            struct basic_radian
            {
                static_assert(is_prefix_v<Prefix>);

                static constexpr quantity_exponents exponents{ 0, 0, 1 };
                static constexpr quantity_factors factors{ 0.0L, 0.0L, Prefix::factor };
                static constexpr quantity_symbols symbols{ ""_us,  ""_us, Prefix::symbol + "rad"_us };
            };

            using quektoradian = basic_radian<quekto    >;
            using rontoradian  = basic_radian<ronto     >;
            using yoktoradian  = basic_radian<yokto     >;
            using zeptoradian  = basic_radian<zepto     >;
            using attoradian   = basic_radian<atto      >;
            using femtoradian  = basic_radian<femto     >;
            using picoradian   = basic_radian<pico      >;
            using nanoradian   = basic_radian<nano      >;
            using microradian  = basic_radian<micro     >;
            using milliradian  = basic_radian<milli     >;
            using centiradian  = basic_radian<centi     >;
            using deciradian   = basic_radian<deci      >;
            using radian       = basic_radian<unprefixed>;
            using decaradian   = basic_radian<deca      >;
            using hectoradian  = basic_radian<hecto     >;
            using kiloradian   = basic_radian<kilo      >;
            using megaradian   = basic_radian<mega      >;
            using gigaradian   = basic_radian<giga      >;
            using teraradian   = basic_radian<tera      >;
            using petaradian   = basic_radian<peta      >;
            using exaradian    = basic_radian<exa       >;
            using zettaradian  = basic_radian<zetta     >;
            using yottaradian  = basic_radian<yotta     >;
            using ronnaradian  = basic_radian<ronna     >;
            using quettaradian = basic_radian<quetta    >;

            struct degree
            {
                static constexpr quantity_exponents exponents{ 0, 0, 1 };
                static constexpr quantity_factors factors{ 0.0L, 0.0L, pi/180.0L };
                static constexpr quantity_symbols symbols{ ""_us, ""_us, "deg"_us };
            };

        }

        inline namespace constants
        {

            inline constexpr quektoradian qrad   {};
            inline constexpr rontoradian  rrad   {};
            inline constexpr yoktoradian  yrad   {};
            inline constexpr zeptoradian  zrad   {};
            inline constexpr attoradian   arad   {};
            inline constexpr femtoradian  frad   {};
            inline constexpr picoradian   prad   {};
            inline constexpr nanoradian   nrad   {};
            inline constexpr microradian  micrad {};
            inline constexpr milliradian  mrad   {};
            inline constexpr centiradian  crad   {};
            inline constexpr deciradian   drad   {};
            inline constexpr radian       rad    {};
            inline constexpr decaradian   darad  {};
            inline constexpr hectoradian  hrad   {};
            inline constexpr kiloradian   krad   {};
            inline constexpr megaradian   Mrad   {};
            inline constexpr gigaradian   Grad   {};
            inline constexpr teraradian   Trad   {};
            inline constexpr petaradian   Prad   {};
            inline constexpr exaradian    Erad   {};
            inline constexpr zettaradian  Zrad   {};
            inline constexpr yottaradian  Yrad   {};
            inline constexpr ronnaradian  Rrad   {};
            inline constexpr quettaradian Qrad   {};

            inline constexpr degree       deg    {};

        }

        inline namespace literals
        {

            [[nodiscard]] constexpr auto operator""_qrad(long double val) noexcept
            {
                return scalar<quektoradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_qrad(unsigned long long int val) noexcept
            {
                return scalar<quektoradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_rrad(long double val) noexcept
            {
                return scalar<rontoradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_rrad(unsigned long long int val) noexcept
            {
                return scalar<rontoradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_yrad(long double val) noexcept
            {
                return scalar<yoktoradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_yrad(unsigned long long int val) noexcept
            {
                return scalar<yoktoradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_zrad(long double val) noexcept
            {
                return scalar<zeptoradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_zrad(unsigned long long int val) noexcept
            {
                return scalar<zeptoradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_arad(long double val) noexcept
            {
                return scalar<attoradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_arad(unsigned long long int val) noexcept
            {
                return scalar<attoradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_frad(long double val) noexcept
            {
                return scalar<femtoradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_frad(unsigned long long int val) noexcept
            {
                return scalar<femtoradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_prad(long double val) noexcept
            {
                return scalar<picoradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_prad(unsigned long long int val) noexcept
            {
                return scalar<picoradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_nrad(long double val) noexcept
            {
                return scalar<nanoradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_nrad(unsigned long long int val) noexcept
            {
                return scalar<nanoradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_micrad(long double val) noexcept
            {
                return scalar<microradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_micrad(unsigned long long int val) noexcept
            {
                return scalar<microradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_mrad(long double val) noexcept
            {
                return scalar<milliradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_mrad(unsigned long long int val) noexcept
            {
                return scalar<milliradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_crad(long double val) noexcept
            {
                return scalar<centiradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_crad(unsigned long long int val) noexcept
            {
                return scalar<centiradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_drad(long double val) noexcept
            {
                return scalar<deciradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_drad(unsigned long long int val) noexcept
            {
                return scalar<deciradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_rad(long double val) noexcept
            {
                return scalar<radian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_rad(unsigned long long int val) noexcept
            {
                return scalar<radian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_darad(long double val) noexcept
            {
                return scalar<decaradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_darad(unsigned long long int val) noexcept
            {
                return scalar<decaradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_hrad(long double val) noexcept
            {
                return scalar<hectoradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_hrad(unsigned long long int val) noexcept
            {
                return scalar<hectoradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_krad(long double val) noexcept
            {
                return scalar<kiloradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_krad(unsigned long long int val) noexcept
            {
                return scalar<kiloradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Mrad(long double val) noexcept
            {
                return scalar<megaradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Mrad(unsigned long long int val) noexcept
            {
                return scalar<megaradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Grad(long double val) noexcept
            {
                return scalar<gigaradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Grad(unsigned long long int val) noexcept
            {
                return scalar<gigaradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Trad(long double val) noexcept
            {
                return scalar<teraradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Trad(unsigned long long int val) noexcept
            {
                return scalar<teraradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Prad(long double val) noexcept
            {
                return scalar<petaradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Prad(unsigned long long int val) noexcept
            {
                return scalar<petaradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Erad(long double val) noexcept
            {
                return scalar<exaradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Erad(unsigned long long int val) noexcept
            {
                return scalar<exaradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Zrad(long double val) noexcept
            {
                return scalar<zettaradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Zrad(unsigned long long int val) noexcept
            {
                return scalar<zettaradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Yrad(long double val) noexcept
            {
                return scalar<yottaradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Yrad(unsigned long long int val) noexcept
            {
                return scalar<yottaradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Rrad(long double val) noexcept
            {
                return scalar<ronnaradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Rrad(unsigned long long int val) noexcept
            {
                return scalar<ronnaradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Qrad(long double val) noexcept
            {
                return scalar<quettaradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Qrad(unsigned long long int val) noexcept
            {
                return scalar<quettaradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_deg(long double val) noexcept
            {
                return scalar<degree>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_deg(unsigned long long int val) noexcept
            {
                return scalar<degree>{ static_cast<double>(val) };
            }

        }

    }

    inline namespace math_constants
    {

        inline constexpr scalar<radian> pi_rad{ pi };

    }

}


#endif //__ZOLLSTOCK_ANGLE_UNITS_HPP__
