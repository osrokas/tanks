#include "Models.h"
#include "Buffer.h"
#include "Geometry.h"
#include "Shaders.h"


BaseModel::BaseModel(float w, float l, std::string vShaderPath, std::string fShaderPath,
                     std::string tPath,
                     std::vector<unsigned int> &ind)
    : width(w), length(l), vertexShaderPath(vShaderPath.c_str()),
      fragmentShaderPath(fShaderPath.c_str()), texturePath(tPath.c_str()),
      vertexShader(vShaderPath.c_str()), fragmentShader(fShaderPath.c_str()),
      indecies(ind),
      texture(tPath.c_str()), shaderProgram(nullptr), buffering(nullptr),
      tranformormation(nullptr), geometry2d(nullptr){};

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
  spritesVector = geometry2d->create_sprite();
  for (int i = 0; i < spritesVector.size(); i++) {
    addVector(spritesVector[i]);
  }
};

void BaseModel::set_positions(){
  unsigned int shader_id = shaderProgram->getShaderProgram();
  tranformormation = new Transformation(shader_id);
  tranformormation->move(angle, init_x, init_y);
};

void BaseModel::draw_model(){
  std::cout << "DO NOTHING" << std::endl;
};

void BaseModel::setCoords(float x, float y) {
    init_x = x;
    init_y = y;
};


void BaseModel::create_object(){
  createGeometry();
  addVectors();
  createSprite();
  create_model();
  set_positions();
  createBoundry();
};

void BaseModel::createGeometry() {
  geometry2d = new Geometry2D(width, length);
};

void BaseModel::createBoundry() {
    left_i = init_x + width;
    right_i = init_x - width;
    top_i = init_y - length;
    bottom_i = init_y + length;
}

void BaseModel::transform_boundry(float angle) {
    glm::vec3 transformedCoords = getTransformedCoordinates(angle, 0, 0, right_i, top_i);
    float right = transformedCoords.x + init_x;
    float top = transformedCoords.y + init_y;

    transformedCoords = getTransformedCoordinates(angle, 0, 0, left_i, bottom_i);
    float left = transformedCoords.x + init_x;
    float bottom = transformedCoords.y + init_y;
};

PlayerModel::PlayerModel(float w, float l, std::string vShaderPath, std::string fShaderPath,
                         std::string tPath,
                         std::vector<unsigned int> &ind)
  : BaseModel(w, l, vShaderPath, fShaderPath, tPath, ind) {}

void PlayerModel::draw_model(){};

void PlayerModel::draw_model(float angle, float x, float y) {
      texture.draw_texture();
      shaderProgram->useShader();
      buffering->drawShader();
      tranformormation->move(angle, x, y);
      init_x = x;
      init_y = y;
      transform_boundry(angle);
};



EnemyModel::EnemyModel(float w, float l, std::string vShaderPath, std::string fShaderPath,
                       std::string tPath, 
                       std::vector<unsigned int> &ind)
  : BaseModel(w, l, vShaderPath, fShaderPath, tPath, ind) {}

void EnemyModel::draw_model() {};

void EnemyModel::draw_model(Extent bounds) {
  texture.draw_texture();
  shaderProgram->useShader();
  buffering->drawShader();
  tranformormation->move(angle, init_x, init_y);
  random_state();
  movement(bounds);
  transform_boundry(angle);
};

void EnemyModel::random_state(){
  if (dir_count > 20000) {
    state = 0 + std::rand() % 4;
    dir_count = 0;
  }
  else {
    dir_count +=1;
  }
};

void EnemyModel::movement(Extent bounds){

  if (state == 0 && init_x < bounds.maxX) {
    init_x += speed;
    angle = 90.0f;
  } else if (state == 1 && init_x > bounds.minX) {
    init_x -= speed;
    angle = 270.0f;
  } else if (state == 2 && init_y < bounds.maxY) {
    init_y += speed;
    angle = 180.0f;
  } else if (state == 3 && init_y > bounds.minY) {
    init_y -= speed;
    angle = 0.0f;
  } else {
  };
};


StaticModel::StaticModel(float w, float h, std::string vShaderPath, std::string fShaderPath,
                           std::string tPath,
                           std::vector<unsigned int> &ind)
    : BaseModel(w, h, vShaderPath, fShaderPath, tPath, ind) {}

void StaticModel::draw_model() {
    texture.draw_texture();
    shaderProgram->useShader();
    buffering->drawShader();
    tranformormation->move(0, init_x, init_y);
};