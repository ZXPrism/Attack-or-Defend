cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(AoD VERSION 0.0.0 LANGUAGES C CXX)
set(PROJ_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(AoD ${SOURCES})
target_include_directories(AoD PUBLIC src)
