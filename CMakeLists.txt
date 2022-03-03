#
# CMake file for color
#
cmake_minimum_required (VERSION 3.10)
project(color)

add_library(color INTERFACE)
target_include_directories(color INTERFACE src)

