cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(AoD VERSION 0.0.0 LANGUAGES C CXX)
set(TARGET_NAME AoD)
set(PROJ_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJ_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(${TARGET_NAME} ${SOURCES})
target_include_directories(${TARGET_NAME} PUBLIC src)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:${TARGET_NAME}>
    ${PROJ_BINARY_DIR}/AoD.exe
)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${PROJ_ROOT_DIR}/cards.db
    ${PROJ_BINARY_DIR}/cards.db
)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
