#include "Models.h"
#include "Buffer.h"
#include "Geometry.h"
#include "Shaders.h"
// #include "Transformations.h"

BaseModel::BaseModel(std::string vShaderPath, std::string fShaderPath,
                     std::string tPath, std::vector<struct Sprite> &spritV,
                     std::vector<unsigned int> &ind)
    : vertexShaderPath(vShaderPath.c_str()),
      fragmentShaderPath(fShaderPath.c_str()), texturePath(tPath.c_str()),
      vertexShader(vShaderPath.c_str()), fragmentShader(fShaderPath.c_str()),
      spritesVector(spritV), indecies(ind),
      texture(tPath.c_str()), shaderProgram(nullptr), buffering(nullptr),
      tranformormation(nullptr){};

void BaseModel::create_model(){
  unsigned int vShader;
  unsigned int fShader;
  vShader = vertexShader.compileShader(GL_VERTEX_SHADER);
  fShader = fragmentShader.compileShader(GL_FRAGMENT_SHADER);

  shaderProgram = new ShaderProgram(vShader, fShader);
  buffering = new Buffer(geomObject);
  
  shaderProgram->create();
  buffering->loadToBuffer(false);
  texture.load_texture();
};

void BaseModel::draw_model(float angle, float x, float y, Extent bounds) {
  texture.draw_texture();
  shaderProgram->useShader();
  buffering->drawShader();
  tranformormation->move(angle, x, y, bounds);
};

void BaseModel::addVector(Sprite &spriteVector) {
  vertices.push_back(spriteVector.x_pos);
  vertices.push_back(spriteVector.y_pos);
  vertices.push_back(spriteVector.z_pos);
  vertices.push_back(spriteVector.r);
  vertices.push_back(spriteVector.g);
  vertices.push_back(spriteVector.b);
  vertices.push_back(spriteVector.tx1);
  vertices.push_back(spriteVector.tx2);
};

void BaseModel::createSprite(){
  geomObject.indecies = indecies;
  geomObject.vertices = vertices;
};

unsigned int BaseModel::getShaderProgram() {
  return shaderProgram->getShaderProgram();
};

void BaseModel::addVectors(){
  for (int i = 0; i < spritesVector.size(); i++) {
    addVector(spritesVector[i]);
  }
};

void BaseModel::set_positions(){
  unsigned int shader_id = shaderProgram->getShaderProgram();
  tranformormation = new Transformation(shader_id);
  tranformormation->move(angle, startX, startY, bounds);
};

void BaseModel::create_object(){
  addVectors();
  createSprite();
  create_model();
  set_positions();
};