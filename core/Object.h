#pragma once
#include <vector>
#include <string>
#include <glad/glad.h>
#include "Models.h"

struct Object {
  const char *vertexShaderPath;
  const char *fragmentShaderPath;
  const char *wallTexturePath1;
  std::vector<Sprite> spritesVector;
  std::vector<unsigned int> indecies;
};

struct ObjectsList {
  std::vector<Object> ojbectsArray;
};

struct Objects {
    std::vector<BaseModel> openglModels;
};