cmake_minimum_required(VERSION 3.19)
project(map_generation)

set(CMAKE_CXX_STANDARD 14)

add_executable(map_generation main.cpp TextureLoader.cpp TextureLoader.h HexagonTexture.cpp HexagonTexture.h Renderer.h OpenGLRenderer.cpp OpenGLRenderer.h)
target_link_libraries(map_generation -lglut -lSOIL -lGL -lGLU)