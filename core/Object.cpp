#include "Object.h"


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
    openglModels[i].set_positions();
  };
}

void Objects::draw(){
  std::cout << "DO NOTHING" << std::endl;
}


// Players::Players(std::vector<Object> ob) : Objects(ob) {}

// void Players::draw(){};

// // Implement when extent reaced no increasing x and y values.
// void Players::draw(float angle, float x, float y, Extent extent) {

//   for (int i = 0; i < openglModels.size(); i++) {
//     transformations[i].move(angle, x,y ,extent);
//     openglModels[i].draw_model();
//     };
// };

// Enemies::Enemies(std::vector<Object> ob) : Objects(ob) {}
// // Implement when extent reaced no increasing x and y values.
// void Enemies::draw() {
//   for (int i = 0; i < openglModels.size(); i++) {
//     transformations[i].move(angle, startX, startY, bounds);
//     openglModels[i].draw_model();
//   };
//   random_state();
//   movement();
// };

// void Enemies::random_state(){
//   if (dir_count > 20000) {
//     state = 0 + std::rand() % 4;
//     dir_count = 0;
//   }
//   else {
//     dir_count +=1;
//   }
// };

// void Enemies::movement(){

//   if (state == 0 && startX < bounds.maxX) {
//     startX += speed;
//     angle = 90.0f;
//   } else if (state == 1 && startX > bounds.minX) {
//     startX -= speed;
//     angle = 270.0f;
//   } else if (state == 2 && startY < bounds.maxY) {
//     startY += speed;
//     angle = 180.0f;
//   } else if (state == 3 && startY > bounds.minY) {
//     startY -= speed;
//     angle = 0.0f;
//   } else {
//   };
// };