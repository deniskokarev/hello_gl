cmake_minimum_required(VERSION 3.31)
project(hello_gl)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
link_libraries(${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(hello_gl main.cpp)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
