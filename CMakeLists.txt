cmake_minimum_required(VERSION 3.22)

project(Zollstock VERSION 0.1.0)

add_library(zollstock MODULE)

target_include_directories(zollstock PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(zollstock PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sources/length_units_requirements.cpp)
target_compile_features(zollstock PUBLIC cxx_std_17)