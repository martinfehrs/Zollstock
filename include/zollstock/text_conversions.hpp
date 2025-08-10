#ifndef __ZOLLSTOCK_TEXT_CONVERSIONS_HPP__
#define __ZOLLSTOCK_TEXT_CONVERSIONS_HPP__


#ifndef ZOLLSTOCK_USE_MODULES
#  include <zollstock/config.hpp>

#  include <algorithm>
#  include <concepts>
#  include <iterator>
#  include <string>
#endif


namespace zollstock
{

    ZOLLSTOCK_MODULE_EXPORT template <typename T>
    concept character_c = std::same_as<T, char> || std::same_as<T, wchar_t>;



    template <character_c Char>
    struct transcoder;

    template <>
    struct transcoder<char>
    {
        [[nodiscard]] static std::string transcode(std::string source)
        {
            return source;
        }
    };

    template <>
    struct transcoder<wchar_t>
    {
        [[nodiscard]] static std::wstring transcode(std::string_view source)
        {
            std::wstring target;

            std::ranges::transform(
                source,
                std::back_inserter(target),
                [](char c){ return static_cast<wchar_t>(c); }
            );

            return target;
        }
    };



    ZOLLSTOCK_MODULE_EXPORT template <character_c Char>
    [[nodiscard]] std::basic_string<Char> transcode_to(std::string text)
    {
        return transcoder<Char>::transcode(std::move(text));
    }

    ZOLLSTOCK_MODULE_EXPORT template <character_c Char>
    [[nodiscard]] std::basic_string<Char> transcode_to(const char* text)
    {
        return transcoder<Char>::transcode(text);
    }

}


#endif //__ZOLLSTOCK_TEXT_CONVERSIONS_HPP__
