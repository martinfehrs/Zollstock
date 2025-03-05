#ifndef __ZOLLSTOCK_TESTS_STREAM_UTILS_HPP__
#define __ZOLLSTOCK_TESTS_STREAM_UTILS_HPP__


#include <fstream>
#include <string>
#include <vector>


[[nodiscard]] inline auto read_lines(std::ifstream& ifs)
{
    std::vector<std::string> lines;

    std::string line;

    while(std::getline(ifs, line))
        lines.push_back(std::move(line));

    return lines;
}


#endif //__ZOLLSTOCK_TESTS_STREAM_UTILS_HPP__
