#pragma once
#include "stb_image.h"
#include <fstream>
#include <glad/glad.h>
#include <iostream>
#include <sstream>

class Texture {
public:
  const char *texturePath;
  Texture(const char *textPath);
  void load_texture();
  void draw_texture();

private:
  unsigned int texture;
};