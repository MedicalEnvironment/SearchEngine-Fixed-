cmake_minimum_required(VERSION 3.8)

# get JSON from github
include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)

FetchContent_MakeAvailable(json)

add_executable(search_server main.cpp ConverterJSON.cpp InvertedIndex.cpp server.cpp)

target_include_directories(search_server PUBLIC ${INCLUDE_DIR})

target_link_libraries(search_server PRIVATE nlohmann_json::nlohmann_json)
