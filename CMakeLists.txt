cmake_minimum_required(VERSION 3.16)

project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-Ddebug=${debug})
if("${debug}" STREQUAL "on")
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

add_compile_options(-Wall -Wextra -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-unknown-pragmas -O3 -mavx)

add_subdirectory(Heap)
add_subdirectory(HeapMedian)
add_subdirectory(CacheLRU)
add_subdirectory(Sandbox)
