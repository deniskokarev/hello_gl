cmake_minimum_required(VERSION 3.20)
project(hello_gl)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
link_libraries(${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

# suppress OpenGL deprecated warnings on Mac
if(APPLE)
    add_compile_options(-Wno-deprecated-declarations)
endif()

# src files as space-separated list
add_executable(${PROJECT_NAME} main.cpp)
