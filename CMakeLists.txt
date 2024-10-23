cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
project(mycalc LANGUAGES CXX)
set(CMAKE_SYSROOT "/")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lvgl)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lvgl/lib)
link_libraries(lvgl sdl2)

file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(mycalc ${SRCS})
