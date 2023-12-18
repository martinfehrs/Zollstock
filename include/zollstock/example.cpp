#include <iostream>

#include "zollstock.hpp"


namespace zs = zollstock;
using namespace zs::unit;
using namespace zs::math_constants;


int main()
{
    constexpr zs::scalar<milliradian> a = pi;
    constexpr zs::scalar<centiradian> b = a;
    constexpr zs::scalar c = b.as<deciradian>();
    constexpr zs::scalar d = c.as<one>();

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    //constexpr zs::scalar a0 = 3_cm/s;
    //constexpr zs::scalar a1 = -pi/3*cm;
    //constexpr zs::scalar a2 = 2.0_mm2;
    //constexpr zs::scalar a3 = 2*pi;
 //
    //std::wcout << a0 * a1 << '\n';
//
    //std::wcout << a0 << '\n';
    //std::wcout << a1 << '\n';
    //std::wcout << a2 << '\n';
    //std::wcout << a3 << '\n';

    return 0;
}