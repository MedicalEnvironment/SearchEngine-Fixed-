cmake_minimum_required(VERSION 3.14)

project(search_server)

set(CMAKE_CXX_STANDARD 17)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(RESOURCES ${CMAKE_SOURCE_DIR}/res)

add_subdirectory(src)
add_subdirectory(tests)
