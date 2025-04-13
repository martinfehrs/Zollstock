#ifndef __ZOLLSTOCK_TESTS_PREPROCESSOR_UTILS_HPP__
#define __ZOLLSTOCK_TESTS_PREPROCESSOR_UTILS_HPP__


#define COUNT_ARGS_(_10, _9, _8, _7, _6, _5, _4, _3, _2, _1, N, ...) N
#define COUNT_ARGS(...) COUNT_ARGS_(__VA_ARGS__ __VA_OPT__(,) 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define CONCAT_(a, b) a##b
#define CONCAT(a, b) CONCAT_(a, b)


#endif //__ZOLLSTOCK_TESTS_PREPROCESSOR_UTILS_HPP__
