// For proper sdl initialization
#include <iostream>
#include <ostream>
#include <vector>
  // For proper sdl initialization
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "Object.h"
#include "Transformations.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


int run(bool wireframe, std::vector<Object> objects) {

  // Get the objects from the vector
      // Variable declarations
  bool running; // Running state
  SDL_Event event; // initialize sdl events
  
  // Creating window
  SDL window("Tanks", 600, 600);

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

    for (int j = 0; j <objects[i].indecies.size(); j++) {
      object1.addIndex(objects[i].indecies[j]);
    }
    object1.createSprite();
    object1.create_model();
    openGlModels.openglModels.push_back(object1);
  };

  rotationShader = openGlModels.openglModels[0].getShaderProgram();

  Transformation movement(rotationShader);

  float angle = 0.0f;
  float x = 0.0f;
  float y = 0.0f;

  Extent bounds = {0.8f, 0.8f, -0.8f, -0.8f};
  while (running) {
    while (SDL_PollEvent(&event)) { // Pointing to memory address
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
        running = false;
      }

      if (event.type == SDL_KEYDOWN) {
        keyboardMovement(event, &angle, &x, &y);
        std::cout << angle << std::endl;
      }
      

      if (event.type == SDL_WINDOWEVENT) {
        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {

          // Update OpenGL viewport
        }
      }
    }

    // TODO  Create object coordinates limits and after shader transformation 
    // update object coordinates
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i < openGlModels.openglModels.size(); i++) {
      openGlModels.openglModels[i].draw_model();
      std::cout << x << std::endl;

      movement.move(angle, x, y, bounds);
    };
    
    window.renderOpenGL();
  }
  window.destroyWindow();
  return 0;
}