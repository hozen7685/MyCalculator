cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER "g++")
project(mycalc LANGUAGES CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lvgl)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lvgl/lib)
link_libraries(lvgl)

file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(mycalc ${SRCS})
