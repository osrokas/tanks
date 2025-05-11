#include "Object.h"
#include "Transformations.h"


Objects::Objects(std::vector<Object> ob) : objects(ob) {}

void Objects::add_data() {
  // Creating objects by shaders, vectors and indecies
  for (int i = 0; i < objects.size(); i++) {
    BaseModel object(objects[i].vertexShaderPath, objects[i].fragmentShaderPath,
                     objects[i].wallTexturePath1);

    // Dereference the pointer to get the value
    for (int j = 0; j < objects[i].spritesVector.size(); j++) {
      object.addVector(objects[i].spritesVector[j]);
    }

    for (int j = 0; j < objects[i].indecies.size(); j++) {
      object.addIndex(objects[i].indecies[j]);
    }
    object.createSprite();
    object.create_model();
    openglModels.push_back(object);
  }
};

void Objects::set_positions(){
  for (int i = 0; i < openglModels.size(); i++) {
    unsigned int shader_id = openglModels[i].getShaderProgram();
    Transformation tranform(shader_id);
    transformations.push_back(tranform);
    tranform.move(angle, startX, startY, bounds);
  };
}

void Objects::draw(){
  std::cout << "DO NOTHING" << std::endl;
}


Players::Players(std::vector<Object> ob) : Objects(ob) {}

void Players::draw(){};

void Players::draw(float angle, float x, float y, Extent extent) {

  for (int i = 0; i < openglModels.size(); i++) {
    transformations[i].move(angle, x,y ,extent);
    openglModels[i].draw_model();
    };
};

Enemies::Enemies(std::vector<Object> ob) : Objects(ob) {}

void Enemies::draw() {
  for (int i = 0; i < openglModels.size(); i++) {
    transformations[i].move(angle, startX, startY, bounds);
    openglModels[i].draw_model();
  };
  startX = startX +0.001;
  startY = startY +0.001;
  std::cout << startX << std::endl;
};
