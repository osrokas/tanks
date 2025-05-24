#pragma once
#include <vector>
#include <iostream>
#include "Sprites.h"

struct Geometry{
  std::vector<float> vertices;
  std::vector<unsigned int> indecies;
};


class Geometry2D {
  float x_pos;
  float y_pos;
  public:

    Geometry2D(float width, float length);
    std::vector<Sprite> create_sprite();
  private:
    std::vector<Sprite> spriteVector;
};