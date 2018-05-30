cmake_minimum_required(VERSION 3.9)
project(Bouncing_Ball)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/GLFW/include)

link_directories(${PROJECT_SOURCE_DIR}/GLFW/lib-mingw)

add_executable(Bouncing_Ball main.cpp)

target_link_libraries(Bouncing_Ball glfw3 glu32 opengl32)