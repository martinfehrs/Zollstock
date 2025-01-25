#ifndef __ZOLLSTOCK_TESTS_HEADER_DEPENDENCIES_HPP__
#define __ZOLLSTOCK_TESTS_HEADER_DEPENDENCIES_HPP__


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
using header_dependencies = std::map<std::filesystem::path, header_set, compare_paths>;


#endif //__ZOLLSTOCK_TESTS_HEADER_DEPENDENCIES_HPP__
