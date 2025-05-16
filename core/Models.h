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

  virtual void draw_model();
  void create_object();
  unsigned int getShaderProgram();

private:
  Shader vertexShader;
  Shader fragmentShader;
  std::vector<Sprite> geometry;
  std::vector<float> vertices;
  Geometry geomObject;
  unsigned int vShader;
  unsigned int fShader;

protected:
  Texture texture;
  ShaderProgram *shaderProgram = NULL;
  Transformation *tranformormation = NULL;
  Buffer *buffering = NULL;
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

// float angle, float x, float y, Extent bounds

class PlayerModel : public BaseModel {
  public:
    PlayerModel(std::string vShaderPath, std::string fShaderPath, std::string tPath,
              std::vector<struct Sprite> &spritV, std::vector<unsigned int> &ind);

    using BaseModel::draw_model;
    void draw_model() override;
    void draw_model(float angle, float startX, float startY, Extent bounds);
};

class EnemyModel : public BaseModel {
  public:
    EnemyModel(std::string vShaderPath, std::string fShaderPath,
                std::string tPath, std::vector<struct Sprite> &spritV,
                std::vector<unsigned int> &ind);

    void draw_model() override;

  protected:
      int state = 0;
      int dir_count = 0;
      float speed = 0.00004f;
      void movement();
      void random_state();
};