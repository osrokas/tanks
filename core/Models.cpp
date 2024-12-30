#include "Models.h"
#include "Buffer.h"
#include "Geometry.h"

BaseModel::BaseModel(const char *vShaderPath, const char *fShaderPath,
                     const char *tPath)
    : vertexShaderPath(vShaderPath), fragmentShaderPath(fShaderPath),
      texturePath(tPath), vertexShader(vShaderPath),
      fragmentShader(fShaderPath), texture(texturePath),
       shaderProgram(nullptr), buffering(nullptr) {};

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


void BaseModel::draw_model(){
    buffering->clearShader(); 
    texture.draw_texture();
    shaderProgram->useShader();
    buffering->drawShader();
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

void BaseModel::addIndex(unsigned int index){
  indecies.push_back(index);
};

void BaseModel::createSprite(){
  geomObject.indecies = indecies;
  geomObject.vertices = vertices;
};