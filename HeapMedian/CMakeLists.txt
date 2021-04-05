cmake_minimum_required(VERSION 3.16)

add_library(HeapMedian SHARED ${CMAKE_CURRENT_SOURCE_DIR}/HeapMedian.cpp)

target_include_directories(HeapMedian PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(HeapMedian Heap)
