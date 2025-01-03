#pragma once
#include "Geometry.h"
#include <fstream>
#include <glad/glad.h>
#include <iostream>
#include <sstream>

class Buffer {

public:
  Geometry geom;
  Buffer(Geometry geomtry);
  void loadToBuffer(bool wireframe);
  void drawShader();

private:
  GLuint VBO;
  GLuint VAO;
  GLuint EBO;
};