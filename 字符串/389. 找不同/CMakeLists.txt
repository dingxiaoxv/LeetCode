cmake_minimum_required(VERSION 3.0.0)
project(findTheDifference VERSION 0.1.0)
add_compile_definitions(-std=c++11 -g -Wall)
include(CTest)
enable_testing()

add_executable(findTheDifference main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
