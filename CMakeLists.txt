# PAQUETES UBUNTU:
#SDL
#sudo apt-get install libsdl2-dev
#OPENGL
#sudo apt install mesa-utils
#GLUT
#sudo apt-get install freeglut3-dev
#GLEW
#sudo apt-get install libglew-dev
#GL MATH
#sudo apt-get install libglm-dev

cmake_minimum_required(VERSION 3.10)
project(sdlogl)

set(CMAKE_CXX_STANDARD 17)

add_executable(sdlogl main.cpp Display.cpp Display.h)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES_FIX)
target_link_libraries(sdlogl ${SDL2_LIBRARIES_FIX} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

