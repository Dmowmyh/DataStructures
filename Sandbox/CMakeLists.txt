cmake_minimum_required(VERSION 3.16)

add_executable(unit_tests ${CMAKE_CURRENT_SOURCE_DIR}/unit_tests.cpp)
target_include_directories(unit_tests PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(unit_tests PRIVATE ${CMAKE_SOURCE_DIR}/3rdparty/catch2/single_include)
target_link_libraries(unit_tests Heap)
target_link_libraries(unit_tests HeapMedian)

add_executable(sandbox ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_include_directories(sandbox PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(sandbox Heap)
target_link_libraries(sandbox HeapMedian)
