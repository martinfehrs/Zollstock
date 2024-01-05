#ifndef __ZOLLSTOCK_ANGLE_UNIT_CONSTANTS_HPP__
#define __ZOLLSTOCK_ANGLE_UNIT_CONSTANTS_HPP__


#include <zollstock/angle_unit_types.hpp>
#include <zollstock/definition_helpers.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace constants
        {

            ZOLLSTOCK_DEFINE_SI_CONSTANTS(,radian, rad)

            inline constexpr degree         deg   {};
            inline constexpr arcminute      arcmin{};
            inline constexpr arcsecond      arcsec{};
            inline constexpr milliarcsecond mas   {};
            inline constexpr microarcsecond micas {};

        }

    }


}


#endif //__ZOLLSTOCK_ANGLE_UNIT_CONSTANTS_HPP__
