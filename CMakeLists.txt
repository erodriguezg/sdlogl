# PAQUETES UBUNTU:
#SDL
#sudo apt-get install libsdl2-dev
#sudo apt-get install libsdl2-image-dev
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
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_executable(sdlogl main.cpp Display.cpp Display.h Shader.cpp Shader.h Mesh.cpp Mesh.h Texture.cpp Texture.h Transform.h Camera.cpp Camera.h obj_loader.h obj_loader.cpp)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR} ${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES_FIX)
target_link_libraries(sdlogl ${SDL2_LIBRARIES_FIX} ${SDL2_IMAGE_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

#copy resources
file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

