// For proper sdl initialization
#include "Rotate.h"
#include <vector>
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "Models.h"
#include "Object.h"
#include "Rotate.h"
#include "Sprites.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main() {
  const char *vertexShaderPath("C:\\dev\\tanks\\shaders\\v_rotate_shader.vert");
  const char *vertexShaderPath2("C:\\dev\\tanks\\shaders\\v_shader.vert");
  const char *fragmentShaderPath("C:\\dev\\tanks\\shaders\\f_shader.vert");
  const char *wallTexturePath1 = "C:\\dev\\tanks\\asssets\\tank.JPG";

  std::vector<Object> objects;

  Sprite sprite1 = {-0.1, -0.3, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0};
  Sprite sprite2 = {0.1, -0.3, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0};
  Sprite sprite3 = {0.1, 0.3, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
  Sprite sprite4 = {-0.1, 0.3, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0};

  std::vector<unsigned int> indecies;
  indecies.push_back(0);
  indecies.push_back(1);
  indecies.push_back(3);
  indecies.push_back(1);
  indecies.push_back(2);
  indecies.push_back(3);

  // Add sprites into vector
  std::vector<Sprite> spritesVector;
  spritesVector.push_back(sprite1);
  spritesVector.push_back(sprite2);
  spritesVector.push_back(sprite3);
  spritesVector.push_back(sprite4);

  Sprite sprite5 = {-0.5, -0.5, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0};
  Sprite sprite6 = {-0.4, -0.5, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0};
  Sprite sprite7 = {-0.4, -0.4, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
  Sprite sprite8 = {-0.5, -0.4, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0};

  std::vector<unsigned int> indecies2;
  indecies2.push_back(0);
  indecies2.push_back(1);
  indecies2.push_back(3);
  indecies2.push_back(1);
  indecies2.push_back(2);
  indecies2.push_back(3);


  // Add sprites into vector
  std::vector<Sprite> spritesVector2;
  spritesVector2.push_back(sprite5);
  spritesVector2.push_back(sprite6);
  spritesVector2.push_back(sprite7);
  spritesVector2.push_back(sprite8);

  Object objectTank = {
    vertexShaderPath, fragmentShaderPath, wallTexturePath1, spritesVector, indecies
  };

  Object objectTank2 = {vertexShaderPath2, fragmentShaderPath, wallTexturePath1,
                        spritesVector2, indecies2};

  objects.push_back(objectTank);
  objects.push_back(objectTank2);

  ObjectsList objArray;
  objArray.ojbectsArray = objects;

  bool running; // Running state
  SDL_Event event; // initialize sdl events

  // Creating window
  SDL window("Tanks", 1200, 800);
  
  running = window.initalize();

  Objects openGlModels;

  unsigned int rotationShader;

  for (int i = 0; i < objects.size(); i++) {
    // Dereference the pointer to get the value
    BaseModel object1(objects[i].vertexShaderPath,
                      objects[i].fragmentShaderPath,
                      objects[i].wallTexturePath1);

    // Dereference the pointer to get the value
    for (int j = 0; j < objects[i].spritesVector.size(); j++) {
      object1.addVector(objects[i].spritesVector[j]);
    }

    for (int j = 0; j < objects[i].indecies.size(); j++) {
      object1.addIndex(objects[i].indecies[j]);
    }
    object1.createSprite();
    object1.create_model();
    openGlModels.openglModels.push_back(object1);
  };

  rotationShader = openGlModels.openglModels[0].getShaderProgram();
  Rotate rotation(rotationShader);
  std::cout << "Shader program: " << rotationShader << std::endl;

  float angle = 0.0f;
  float x = 0.0f;
  float y = 0.0f;

  while (running) {
    while (SDL_PollEvent(&event)) { // Pointing to memory address
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
        running = false;
      }

      if (event.type == SDL_KEYDOWN) {
        keyboardMovement(event, &angle, &x, &y);
      }

      if (event.type == SDL_WINDOWEVENT) {
        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
        }
      }
        }
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        for (int i = 0; i < openGlModels.openglModels.size(); i++){
          openGlModels.openglModels[i].draw_model();
          // rotationShader = openGlModels.openglModels[0].getShaderProgram();
          // Rotate rotation(rotationShader);
        };
        rotation.rotate_z(angle, x, y);

        window.renderOpenGL();
  }
  window.destroyWindow();
}
