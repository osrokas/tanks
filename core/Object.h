#pragma once
#include <vector>
#include <string>
#include "glad/glad.h"
#include "Models.h"


struct Object {
  float width;
  float length;
  std::string vertexShaderPath;
  std::string fragmentShaderPath;
  std::string wallTexturePath1;
  std::vector<unsigned int> indecies;
};