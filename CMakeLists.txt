cmake_minimum_required(VERSION 3.5)
project(simplePathTracer)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

#Required installations
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
include_directories(include 3rdparty/stb-master 3rdparty/tinyobjloader-master)
file(GLOB SOURCES "src/*.cpp")
add_executable(simplePathTracer ${SOURCES})
target_link_libraries(simplePathTracer ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} glfw)
