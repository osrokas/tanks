// For proper sdl initialization
#include "Rotate.h"
#include <vector>
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "Models.h"
#include "Sprites.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Object.h"

int main() {
  const char *vertexShaderPath("C:\\dev\\tanks\\shaders\\v_rotate_shader.vert");
  const char *fragmentShaderPath("C:\\dev\\tanks\\shaders\\f_shader.vert");
  const char *wallTexturePath1 = "C:\\dev\\tanks\\asssets\\tank.JPG";

  Sprite sprite1 = {0.5f, 0.2f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f};
  Sprite sprite2 = {0.5f, 0.3f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};
  Sprite sprite3 = {0.3f, 0.3f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
  Sprite sprite4 = {0.3f, 0.2f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f};

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

  std::vector<Object> objects;

  Object objectTank = {
    vertexShaderPath, fragmentShaderPath, wallTexturePath1, spritesVector, indecies
  };

  objects.push_back(objectTank);

  ObjectsList objArray;
  objArray.ojbectsArray = objects;

  bool running; // Running state
  SDL_Event event; // initialize sdl events

  // Creating window
  SDL window("Tanks", 1200, 800);
  
  running = window.initalize();

  Objects openGlModels;

  unsigned int rotationShader;

  for (int i = 0; i <  objArray.ojbectsArray.size(); i++){

    BaseModel object1(objArray.ojbectsArray[i].vertexShaderPath,
                      objArray.ojbectsArray[i].fragmentShaderPath,
                      objArray.ojbectsArray[i].wallTexturePath1);
    for (int j = 0; j < objArray.ojbectsArray[i].spritesVector.size(); j++) {
      object1.addVector(objArray.ojbectsArray[i].spritesVector[j]);
      std::cout << objArray.ojbectsArray[i].spritesVector[j].r << std::endl;
      std::cout << objArray.ojbectsArray[i].spritesVector[j].g << std::endl;
      std::cout << objArray.ojbectsArray[i].spritesVector[j].b << std::endl;
    }

    for (int j = 0; j < objArray.ojbectsArray[i].indecies.size(); j++) {
      object1.addIndex(objArray.ojbectsArray[i].indecies[j]);
    }

    object1.createSprite();
    object1.create_model();

    openGlModels.openglModels.push_back(object1);
  };

  rotationShader = openGlModels.openglModels[0].getShaderProgram();
  Rotate rotation(rotationShader);

  while (running) {
    while (SDL_PollEvent(&event)) { // Pointing to memory address
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
        running = false;
      }

      if (event.type == SDL_WINDOWEVENT) {
        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {


          // Update OpenGL viewport
          
        }
      }
        }
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        for (int i = 0; i < openGlModels.openglModels.size(); i++){
          openGlModels.openglModels[i].draw_model();
        };
        rotation.rotate_z();
        // object1.draw_model();
        // object2.draw_model();
        window.renderOpenGL();
  }
  window.destroyWindow();
}
