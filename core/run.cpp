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


int run(bool wireframe, std::vector<Object> objects, std::vector<Object> enemies) {

  // Get the objects from the vector
      // Variable declarations
  bool running; // Running state
  SDL_Event event; // initialize sdl events
  
  // Creating window
  SDL window("Tanks", 600, 600);

  running = window.initalize();

  // Define user input models
  Objects openGlModels;
  // Define enemies models
  Objects enemiesModels;

  unsigned int rotationShader;
  unsigned int enemyShader;

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

  for (int i = 0; i < enemies.size(); i++) {
    // Dereference the pointer to get the value
    BaseModel enemy(enemies[i].vertexShaderPath,
                      enemies[i].fragmentShaderPath,
                      enemies[i].wallTexturePath1);

    // Dereference the pointer to get the value
    for (int j = 0; j < enemies[i].spritesVector.size(); j++) {
      enemy.addVector(enemies[i].spritesVector[j]);
    }

    for (int j = 0; j < enemies[i].indecies.size(); j++) {
      enemy.addIndex(enemies[i].indecies[j]);
    }
    enemy.createSprite();
    enemy.create_model();
    enemiesModels.openglModels.push_back(enemy);
  };

  rotationShader = openGlModels.openglModels[0].getShaderProgram();

  enemyShader = enemiesModels.openglModels[0].getShaderProgram();
  
  Transformation enemyMovement(enemyShader);
  Transformation movement(rotationShader);

  float angle = 0.0f;
  float x = 0.0f;
  float y = 0.0f;

  float enemyAngle = 0.2f;
  float enemyX = 0.1f;
  float enemyY = 0.4f;

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

      movement.move(angle, x, y, bounds);
    };

    for (int i=0; i < enemiesModels.openglModels.size(); i++) {
      enemiesModels.openglModels[i].draw_model();
      std::cout << enemyX << std::endl;
      enemyMovement.move(enemyAngle, enemyX, enemyY, bounds);
    };
    
    window.renderOpenGL();
  }
  window.destroyWindow();
  return 0;
}