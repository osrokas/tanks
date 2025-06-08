#pragma once
#include "Buffer.h"
#include "Geometry.h"
#include "Shaders.h"
#include "Sprites.h"
#include "Texture.h"
#include "Transformations.h"
#include <cstddef>

struct Coords{
  float x;
  float y;
};

class BaseModel{
  std::vector<Sprite> spritesVector;
  std::string vertexShaderPath;
  std::string fragmentShaderPath;
  std::string texturePath;
  
  std::vector<unsigned int> &indecies;

public:
  float width;
  float length;

  float right;
  float left;
  float top;
  float bottom;

  BaseModel(float w, float l, std::string vShaderPath, std::string fShaderPath, std::string tPath, std::vector<unsigned int> &ind);

  virtual void draw_model();
  void create_object();
  unsigned int getShaderProgram();

  // Coords getPosition();
  float angle = 0.0f;
  float init_x = 0.0f;
  float init_y = 0.0f;
  void setCoords(float x, float y);
  void setModelBoundry();

private:
  Shader vertexShader;
  Shader fragmentShader;
  std::vector<Sprite> geometry;
  std::vector<float> vertices;
  Geometry geomObject;
  Geometry2D *geometry2d = NULL;
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
  void createGeometry();
  void create_model();
  void createSprite();
  void set_positions();
  void createBoundry();
 

  Extent bounds = {0.8f, 0.8f, -0.8f, -0.8f};
  float speed;
};

// float angle, float x, float y, Extent bounds

class PlayerModel : public BaseModel {
  public:
    PlayerModel(float w, float h, std::string vShaderPath, std::string fShaderPath, std::string tPath, std::vector<unsigned int> &ind);

    using BaseModel::draw_model;
    void draw_model() override;
    void draw_model(float angle, float startX, float startY);
};

class EnemyModel : public BaseModel {
  public:
    EnemyModel(float w, float h, std::string vShaderPath, std::string fShaderPath,
                std::string tPath,
                std::vector<unsigned int> &ind);
    using BaseModel::draw_model;
    void draw_model() override;
    void draw_model(Extent bounds);
    float get_position();

  protected:
      int state = 0;
      int dir_count = 0;
      float speed = 0.00004f;
      void movement(Extent bounds);
      void random_state();
};