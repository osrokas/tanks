#pragma once
#include "stb_image.h"
#include <fstream>
#include "glad/glad.h"
#include <iostream>
#include <sstream>

class Texture {
public:
  std::string texturePath;
  Texture(std::string textPath);
  void load_texture();
  void draw_texture();

private:
  unsigned int texture;
};