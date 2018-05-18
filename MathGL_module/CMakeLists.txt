cmake_minimum_required(VERSION 3.10)
project(MathGL_module)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall -std=gnu++11")

add_executable(MathGL_module main.cpp src/functionArg.cpp include/functionArg.h src/mathGL_graphics.cpp include/mathGL_graphics.h src/mathGL_graphics_object.cpp include/mathGL_graphics_object.h src/mathGL_graphics_frame_properties.cpp include/mathGL_graphics_frame_properties.h)

target_link_libraries(MathGL_module mgl)
target_link_libraries(MathGL_module mgl-qt5)