#ifndef __ZOLLSTOCK_QANTITY_LIMITS_HPP__
#define __ZOLLSTOCK_QANTITY_LIMITS_HPP__


#include <zollstock/quantity.hpp>

#include <limits>


namespace std
{

    template <zollstock::unit_c auto unit, zollstock::number_c Number>
    class numeric_limits<zollstock::quantity<unit, Number>>
    {

    private:

        using quantity_type = zollstock::quantity<unit, Number>;
        using underlying_limits = std::numeric_limits<Number>;

    public:

        static constexpr auto is_specialized    = underlying_limits::is_specialized;
        static constexpr auto is_signed         = underlying_limits::is_signed;
        static constexpr auto is_integer        = underlying_limits::is_integer;
        static constexpr auto is_exact          = underlying_limits::is_exact;
        static constexpr auto has_infinity      = underlying_limits::has_infinity;
        static constexpr auto has_quiet_NaN     = underlying_limits::has_quiet_NaN;
        static constexpr auto has_signaling_NaN = underlying_limits::has_signaling_NaN;
        static constexpr auto has_denorm        = underlying_limits::has_denorm;
        static constexpr auto has_denorm_loss   = underlying_limits::has_denorm_loss;
        static constexpr auto round_style       = underlying_limits::round_style;
        static constexpr auto is_iec559         = underlying_limits::is_iec559;
        static constexpr auto is_bounded        = underlying_limits::is_bounded;
        static constexpr auto is_modulo         = underlying_limits::is_modulo;
        static constexpr auto digits            = underlying_limits::digits;
        static constexpr auto digits10          = underlying_limits::digits10;
        static constexpr auto max_digits10      = underlying_limits::max_digits10;
        static constexpr auto radix             = underlying_limits::radix;
        static constexpr auto min_exponent      = underlying_limits::min_exponent;
        static constexpr auto min_exponent10    = underlying_limits::min_exponent10;
        static constexpr auto max_exponent      = underlying_limits::max_exponent;
        static constexpr auto max_exponent10    = underlying_limits::max_exponent10;
        static constexpr auto traps             = underlying_limits::traps;
        static constexpr bool tinyness_before   = underlying_limits::tinyness_before;

        [[nodiscard]] static constexpr auto min() noexcept
        {
            return quantity_type{ underlying_limits::min() };
        }

        [[nodiscard]] static constexpr auto lowest() noexcept
        {
            return quantity_type{ underlying_limits::lowest() };
        }

        [[nodiscard]] static constexpr auto max() noexcept
        {
            return quantity_type{ underlying_limits::max() };
        }

        [[nodiscard]] static constexpr auto epsilon() noexcept
        {
            return quantity_type{ underlying_limits::epsilon() };
        }

        [[nodiscard]] static constexpr auto round_error() noexcept
        {
            return quantity_type{ underlying_limits::round_error() };
        }

        [[nodiscard]] static constexpr auto infinity() noexcept
        {
            return quantity_type{ underlying_limits::infinity() };
        }

        [[nodiscard]] static constexpr auto quiet_NaN() noexcept
        {
            return quantity_type{ underlying_limits::quiet_NaN() };
        }

        [[nodiscard]] static constexpr auto signaling_NaN() noexcept
        {
            return quantity_type{ underlying_limits::signaling_NaN() };
        }

        [[nodiscard]] static constexpr auto denorm_min() noexcept
        {
            return quantity_type{ underlying_limits::denorm_min() };
        }

    };

    template <zollstock::unit_c auto unit, zollstock::number_c Number>
    class numeric_limits<const zollstock::quantity<unit, Number>>
        : numeric_limits<zollstock::quantity<unit, Number>>
    { };

    template <zollstock::unit_c auto unit, zollstock::number_c Number>
    class numeric_limits<volatile zollstock::quantity<unit, Number>>
        : numeric_limits<zollstock::quantity<unit, Number>>
    { };

    template <zollstock::unit_c auto unit, zollstock::number_c Number>
    class numeric_limits<const volatile zollstock::quantity<unit, Number>>
        : numeric_limits<zollstock::quantity<unit, Number>>
    { };

}


#endif //__ZOLLSTOCK_QANTITY_LIMITS_HPP__
