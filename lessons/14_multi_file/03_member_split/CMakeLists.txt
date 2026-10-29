cmake_minimum_required(VERSION 3.16)
project(Vec2Lab LANGUAGES CXX)

add_library(vec2 STATIC Vec2.cpp)
target_compile_features(vec2 PRIVATE cxx_std_17)
add_executable(vec2_demo main.cpp)
target_compile_features(vec2_demo PRIVATE cxx_std_17)

target_link_libraries(vec2_demo PRIVATE vec2)



