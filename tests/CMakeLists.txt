cmake_minimum_required(VERSION 3.8)

project(server_test)

# get GTest from github
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        server_test

        index_test.cpp
        server_tests.cpp
        ${CMAKE_SOURCE_DIR}/src/InvertedIndex.cpp
        ${CMAKE_SOURCE_DIR}/src/server.cpp
)


target_link_libraries(server_test PRIVATE gtest_main)
