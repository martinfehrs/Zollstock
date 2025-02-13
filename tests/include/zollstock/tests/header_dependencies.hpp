#ifndef __ZOLLSTOCK_TESTS_HEADER_DEPENDENCIES_HPP__
#define __ZOLLSTOCK_TESTS_HEADER_DEPENDENCIES_HPP__


#include <algorithm>
#include <filesystem>
#include <set>
#include <map>


struct compare_paths
{
    [[nodiscard]] bool operator()(std::filesystem::path path_1, std::filesystem::path path_2) const
    {
        return path_1.replace_extension() > path_2.replace_extension();
    }
};

using header_set = std::set<std::filesystem::path>;

template <typename Element>
[[nodiscard]] std::set<Element> set_union(
    const std::set<Element>& set_1, const std::set<Element>& set_2
)
{
    std::set<Element> result;

    std::ranges::set_union(set_1, set_2, std::inserter(result, std::end(result)));

    return result;
}

template <typename Element>
[[nodiscard]] std::set<Element> operator&(
    const std::set<Element>& set_1, const std::set<Element>& set_2
)
{
    return set_union(set_1, set_2);
}

[[nodiscard]] inline header_set header_dir(
    const std::filesystem::path& base_dir,
    std::initializer_list<std::filesystem::path> relative_header_paths
)
{
    header_set result;

    for(const auto& relative_header_path : relative_header_paths)
        result.insert(base_dir/relative_header_path);

    return result;
}


using header_dependencies = std::map<std::filesystem::path, header_set, compare_paths>;


#endif //__ZOLLSTOCK_TESTS_HEADER_DEPENDENCIES_HPP__
