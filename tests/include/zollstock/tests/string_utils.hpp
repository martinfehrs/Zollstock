#ifndef __ZOLLSTOCK_TESTS_STRING_UTILS_HPP__
#define __ZOLLSTOCK_TESTS_STRING_UTILS_HPP__


#include <string>
#include <ranges>
#include <iterator>


[[nodiscard]] inline auto toupper(const std::string& text)
{
    std::string uppercase_text;

    std::ranges::transform(
        text,
        std::back_inserter(uppercase_text),
        [](char c){ return std::toupper(c); }
    );

    return uppercase_text;
}


#endif //__ZOLLSTOCK_TESTS_STRING_UTILS_HPP__
