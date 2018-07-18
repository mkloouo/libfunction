cmake_minimum_required(VERSION 3.11)
project(function)

set(CXXFLAGS "-Wall -Werror -Wextra -pedantic")
set(CMAKE_CXX_COMPILE_FEATURES)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

enable_testing()

include_directories(test)
include_directories(libfunction)

add_subdirectory(test)
add_subdirectory(libfunction)