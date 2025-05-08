#pragma once
#include <vector>
#include <string>
#include <glad/glad.h>
#include "Models.h"
#include "Transformations.h"

struct Object {
  std::string vertexShaderPath;
  std::string fragmentShaderPath;
  std::string wallTexturePath1;
  std::vector<Sprite> spritesVector;
  std::vector<unsigned int> indecies;
};

class Objects {
  std::vector<Object> objects;

public:
  Objects(std::vector<struct Object> ob);
  void add_data();
  void draw(float angle, float startX, float startY, Extent bounds);

  std::vector<BaseModel> openglModels;
};