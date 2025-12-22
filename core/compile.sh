#!/bin/bash
g++ main.cpp Collisions.cpp KeyboardEvents.cpp Window.cpp Shaders.cpp Models.cpp Geometry.cpp Texture.cpp Buffer.cpp stb_image.h stb_image.cpp Transformations.cpp /home/osrokas/projects/tanks/glad/src/glad.c -I/home/osrokas/projects/tanks -I/home/osrokas/projects/tanks/glad/include -I/usr/include/SDL2 -g -pedantic -o tanks -lSDL2 -lSDL2_image -lGL -std=c++17

if [ $? -eq 0 ]; then
    echo "Compilation successful!"
else
    echo "Compilation failed!"
fi