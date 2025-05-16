#pragma once
#include "Buffer.h"
#include "Geometry.h"
#include "Shaders.h"
#include "Sprites.h"
#include "Texture.h"
#include "Transformations.h"
#include <cstddef>

class BaseModel{

  std::string vertexShaderPath;
  std::string fragmentShaderPath;
  std::string texturePath;
  std::vector<Sprite> &spritesVector;
  std::vector<unsigned int> &indecies;

public:
  BaseModel(std::string vShaderPath, std::string fShaderPath, std::string tPath,
            std::vector<struct Sprite> &spritV, std::vector<unsigned int> &ind);

  void draw_model(float angle, float x, float y, Extent bounds);
  void create_object();
  unsigned int getShaderProgram();
  

private:
  Shader vertexShader;
  Shader fragmentShader;
  ShaderProgram *shaderProgram = NULL;
  Texture texture;
  std::vector<Sprite> geometry;
  std::vector<float> vertices;
  Buffer *buffering = NULL;
  Geometry geomObject;
  Transformation *tranformormation = NULL;
  unsigned int vShader;
  unsigned int fShader;

protected:
  void addVector(Sprite &spriteVector);
  void addIndex(unsigned int index);
  void addVectors();
  void addIndecies();
  void create_model();
  void createSprite();
  void set_positions();
  float angle = 0.0f;
  float startX = 0.0f;
  float startY = 0.0f;
  Extent bounds = {0.8f, 0.8f, -0.8f, -0.8f};
  float speed;
};