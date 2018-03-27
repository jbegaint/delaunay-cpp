project(delaunay-demo)
cmake_minimum_required(VERSION 3.2)

add_compile_options(-std=c++11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

if (NOT BUILD_SHARED_LIBS)
	find_package(JPEG REQUIRED)
	find_package(OpenSSL REQUIRED)
	find_package(PNG REQUIRED)
	find_package(ZLIB REQUIRED)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR} OpenGL::OpenGL)

add_executable(demo demo.cpp)
target_link_libraries(demo OpenGL::OpenGL OpenGL::GLU GLUT::GLUT)
target_compile_options(demo PRIVATE -std=c++14)
