cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

project(AoD_RE VERSION 0.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET_NAME AoD_re)
set(PROJ_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJ_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(PROJ_ASSETS_DIR ${PROJ_BINARY_DIR})

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(${TARGET_NAME} ${SOURCES})
target_include_directories(${TARGET_NAME} PUBLIC src)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:${TARGET_NAME}>
    ${PROJ_BINARY_DIR}/AoD_re.exe
)

# add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
#                 COMMAND ${CMAKE_COMMAND} -E copy_directory
#                 ${PROJ_ROOT_DIR}/assets 
#                 ${PROJ_ASSETS_DIR})

set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_COMPILER_IS_GNUCC)
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
endif()

set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -g")

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
