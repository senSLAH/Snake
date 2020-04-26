cmake_minimum_required(VERSION 3.16)
project(snake)

set(CMAKE_CXX_STANDARD 14)

add_executable(snake main.cpp)

add_compile_options(-Wall -Wextra)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(snake sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
