// For proper sdl initialization
#include "SDL2/SDL_keycode.h"
#include "Transformations.h"
#include <iostream>
#include <vector>
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "Models.h"
#include "Sprites.h"
#include "Window.h"
#include "glad/glad.h"
#include "Geometry.h"
#include "Collisions.h"

int main() {
  const char *vertexShaderPath("C:\\Projects\\tanks\\shaders\\v_rotate_shader.vert");
  const char *fragmentShaderPath("C:\\Projects\\tanks\\shaders\\f_shader.vert");
  const char *wallTexturePath1 = "C:\\Projects\\tanks\\asssets\\tank.JPG";
  const char *txt = "C:\\Projects\\tanks\\asssets\\wall.jpg";

  // Creating indecies for the sprites
  std::vector<unsigned int> indecies;
  indecies.push_back(0);
  indecies.push_back(1);
  indecies.push_back(3);
  indecies.push_back(1);
  indecies.push_back(2);
  indecies.push_back(3);

  bool running; // Running state
  SDL_Event event; // initialize sdl events

  // Creating window
  SDL window("Tanks", 600, 600);

  running = window.initalize();

  PlayerModel object1 = {0.1f, 0.2f, vertexShaderPath, fragmentShaderPath, wallTexturePath1,
                        indecies};

  EnemyModel object2 = {0.1f, 0.2f, vertexShaderPath, fragmentShaderPath, wallTexturePath1,
                        indecies};

  EnemyModel object3 = {0.1f, 0.2f, vertexShaderPath, fragmentShaderPath, wallTexturePath1,
                        indecies};

  object1.create_object();

  std::vector<EnemyModel> enemies;
  enemies.push_back(object2);
  enemies.push_back(object3);
  
  for (int i = 0; i < enemies.size(); i++){
    enemies[i].create_object();
  }

  // Set initial coordinates for player
  float angle = 0.0f;
  float x = 0.0f;
  float y = 0.0f;
  
  Extent bounds = {0.8f, 0.8f, -0.8f, -0.8f};
      // Game loop

  EnemyModel &enem = enemies[1];
  PlayerModel &pl = object1;

  Collision cols(pl, enem);
  while (running) {

    // Handling inputs
    while (SDL_PollEvent(&event)) {
      // Quit
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
        running = false;
      }
      // Player movement
      if (event.type == SDL_KEYDOWN) {
        keyboardMovement(event, &angle, &x, &y);
      }
      // Resizing window
      if (event.type == SDL_WINDOWEVENT) {
        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
          // Update OpenGL viewport
        }
      }

    }
    // Render updates
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw objects
    object1.draw_model(angle, x, y, bounds);

    for (int i = 0; i < enemies.size(); i++) {
      enemies[i].draw_model();
    }
    cols.detect();

    window.renderOpenGL();
  }
  // Destroy window
  window.destroyWindow();
  return 0;
}