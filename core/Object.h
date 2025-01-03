#pragma once
#include <vector>
#include <string>
#include <glad/glad.h>
#include "Models.h"

struct Object {
  std::string vertexShaderPath;
  std::string fragmentShaderPath;
  std::string wallTexturePath1;
  std::vector<Sprite> spritesVector;
  std::vector<unsigned int> indecies;
};

struct ObjectsList {
  std::vector<Object> ojbectsArray;
};

struct Objects {
    std::vector<BaseModel> openglModels;
};