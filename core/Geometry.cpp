#include "Geometry.h"
#include "Sprites.h"
#include <vector>

Geometry2D::Geometry2D(float width, float length)
    : x_pos(width), y_pos(length), spriteVector() {}

std::vector<Sprite> Geometry2D::create_sprite() {
  Sprite sprite1 = {
      0.0f - x_pos, 0.0f - y_pos, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f};
  Sprite sprite2 = {0.0f + x_pos, 0.0f - y_pos, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};
  Sprite sprite3 = {0.0f + x_pos, 0.0f + y_pos, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
  Sprite sprite4 = {0.0f - x_pos, 0.0f + y_pos, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f};
  spriteVector.push_back(sprite1);
  spriteVector.push_back(sprite2);
  spriteVector.push_back(sprite3);
  spriteVector.push_back(sprite4);
  return spriteVector;
};