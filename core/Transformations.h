#pragma once
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <iostream>
#include <vector>


struct Extent{
  float maxX;
  float maxY;
  float minX;
  float minY;
};

class Transformation {
  public:
    unsigned int shaderProgramID;
    Transformation(unsigned int shaderID);
    void move(float angle, float x, float y);

  private:
    unsigned int transformLoc;
  };