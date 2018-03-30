project(delaunay-demo)
cmake_minimum_required(VERSION 3.2)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} OpenGL::OpenGL)

add_executable(demo demo.cpp)
target_link_libraries(demo OpenGL::OpenGL OpenGL::GLU GLUT::GLUT)
target_compile_options(demo PRIVATE -std=c++14)
