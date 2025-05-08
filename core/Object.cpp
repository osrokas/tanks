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
void Objects::draw(float angle, float startX, float startY, Extent bounds) {

  for (int i = 0; i < openglModels.size(); i++) {
    openglModels[i].draw_model();
    unsigned int shader = openglModels[i].getShaderProgram();
    Transformation movement(shader);
    movement.move(angle, startX, startY, bounds);
    };
};
