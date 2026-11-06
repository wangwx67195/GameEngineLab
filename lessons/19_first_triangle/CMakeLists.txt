cmake_minimum_required(VERSION 3.16)
project(triangle)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(review review.cpp)

target_link_libraries(review PRIVATE glfw GLEW::GLEW OpenGL::GL)