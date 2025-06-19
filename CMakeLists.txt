cmake_minimum_required(VERSION 3.28)

project(Zollstock VERSION 0.3.0)

option(USE_MODULES "Provide C++ Modules" OFF)

if(USE_MODULES)
    add_library(zollstock)
    target_include_directories(zollstock PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_compile_features(zollstock PUBLIC cxx_std_20)
else(USE_MODULES)
    add_library(zollstock INTERFACE)
    target_include_directories(zollstock INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_compile_features(zollstock INTERFACE cxx_std_20)
endif(USE_MODULES)

add_subdirectory(module)
add_subdirectory(dependencies/Catch2)

add_subdirectory(examples)

include(CTest)
add_subdirectory(tests)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

set(CPACK_SOURCE_IGNORE_FILES /build;/\\.git/)
set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${CMAKE_PROJECT_VERSION}")
include (CPack)
