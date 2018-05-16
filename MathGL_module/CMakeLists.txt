cmake_minimum_required(VERSION 3.10)
project(MathGL_module)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall -std=gnu++11")

add_executable(MathGL_module main.cpp functionArg.cpp functionArg.h mathGL_graphics.cpp mathGL_graphics.h mathGL_graphics_object.cpp mathGL_graphics_object.h mathGL_graphics_frame_properties.cpp mathGL_graphics_frame_properties.h)

target_link_libraries(MathGL_module mgl)
target_link_libraries(MathGL_module mgl-qt5)