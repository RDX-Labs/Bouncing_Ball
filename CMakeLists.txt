cmake_minimum_required(VERSION 3.9)
project(Bouncing_Ball)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/includes)

link_directories(${PROJECT_SOURCE_DIR}/libraries/lib-mingw)

add_executable(Bouncing_Ball main.cpp glad.c)

target_link_libraries(Bouncing_Ball glfw3 glu32 opengl32)