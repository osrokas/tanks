// For proper sdl initialization
#include <vector>
  // For proper sdl initialization
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "Object.h"
#include "Sprites.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


int run(bool wireframe, std::vector<Sprite> &sprites,
        std::vector<unsigned int> &indecies,
        const char *texture_path, const char *vertexShader,
        const char *fragmentShader) {

  std::vector<Object> objects;

  Object objectTank = {vertexShader, fragmentShader, texture_path, sprites, indecies};

  objects.push_back(objectTank);

  ObjectsList objArray;
  objArray.ojbectsArray = objects;

  // Variable declarations
  bool running;    // Running state
  SDL_Event event; // initialize sdl events

  // Creating window
  SDL window("Tanks", 600, 600);

  running = window.initalize();

  Objects openGlModels;

  for (int i = 0; i < objArray.ojbectsArray.size(); i++) {

    BaseModel object1(objArray.ojbectsArray[i].vertexShaderPath,
                      objArray.ojbectsArray[i].fragmentShaderPath,
                      objArray.ojbectsArray[i].wallTexturePath1);
    for (int j = 0; j < objArray.ojbectsArray[i].spritesVector.size(); j++) {
      object1.addVector(objArray.ojbectsArray[i].spritesVector[j]);
    }

    for (int j = 0; j < objArray.ojbectsArray[i].indecies.size(); j++) {
      object1.addIndex(objArray.ojbectsArray[i].indecies[j]);
    }

    object1.createSprite();
    object1.create_model();

    openGlModels.openglModels.push_back(object1);
  };

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
    for (int i = 0; i < openGlModels.openglModels.size(); i++) {
      openGlModels.openglModels[i].draw_model();
    };
    window.renderOpenGL();
  }
  window.destroyWindow();
  return 0;
}