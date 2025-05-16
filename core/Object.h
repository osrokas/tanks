#pragma once
#include <vector>
#include <string>
#include "glad/glad.h"
#include "Models.h"
#include "Transformations.h"

struct Object {
  std::string vertexShaderPath;
  std::string fragmentShaderPath;
  std::string wallTexturePath1;
  std::vector<Sprite> spritesVector;
  std::vector<unsigned int> indecies;
};

class Object_{
  public:
    Transformation transform;
    Object_(std::string vertexShaderPath, std::string fragmentShaderPath, std::string texturePath);
    void add_data();
    void set_positions();
    virtual void draw();
  protected:
    std::string vertexShaderPath;
    std::string fragmentShaderPath;
    std::string texturePath;
    std::vector<Sprite> spritesVector;
    std::vector<unsigned int> indecies;
};

class Player_ : public Object_{
  Player_(std::string vertexShaderPath, std::string fragmentShaderPath,std::string texturePath);
  using Object_::draw;
  void draw() override;
  void draw(float angle, float x, float y, Extent extent);
};

// Define base class
class Objects {
  std::vector<Object> objects;
  

public:
  Objects(std::vector<struct Object> ob);
  void add_data();
  void set_positions();
  virtual void draw();

  std::vector<BaseModel> openglModels;
  std::vector<Transformation> transformations;
  // Using protected because private could not be used in child classes
  protected:
    float angle=0.0f;
    float startX=0.0f;
    float startY=0.0f;
    Extent bounds = {0.8f, 0.8f, -0.8f, -0.8f};
    float speed;
};

// // Define child class
// class Players : public Objects {
//   public:
//     Players(std::vector<struct Object> ob);
//     using Objects::draw; // Bring draw from Objects class
//     void draw() override; // and when override 
//     void draw(float angle, float x, float y, Extent extent); // and finally overload it
// };

// class Enemies : public Objects {
//   public:
//       Enemies(std::vector<struct Object> ob);
//       void draw() override;

//     protected:
//       int state = 0;
//       int dir_count = 0;
//       void movement();
//       void random_state();
//       float speed = 0.00004f;

// };