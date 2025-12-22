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
  const char *vertexShaderPath("/home/osrokas/projects/tanks/shaders/v_rotate_shader.vert");
  const char *fragmentShaderPath("/home/osrokas/projects/tanks/shaders/f_shader.vert");
  const char *wallTexturePath1 = "/home/osrokas/projects/tanks/asssets/tank.JPG";
  const char *txt = "/home/osrokas/projects/tanks/asssets/wall.jpg";

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

  running = window.initialize();

  PlayerModel object1 = {0.1f, 0.2f, vertexShaderPath, fragmentShaderPath, wallTexturePath1,
                        indecies};

  EnemyModel object2 = {0.1f, 0.2f, vertexShaderPath, fragmentShaderPath, wallTexturePath1,
                        indecies};

  EnemyModel object3 = {0.1f, 0.2f, vertexShaderPath, fragmentShaderPath, wallTexturePath1,
                        indecies};

  // Create player object
  object1.create_object();

  // Creating enemy objects vector
  std::vector<EnemyModel> enemies;
  enemies.push_back(object2);
  // enemies.push_back(object3);
    
  // Create enemy objects and set initial coordinates
  for (int i = 0; i < enemies.size(); i++){
    enemies[i].create_object();
    float initial_x (rand()/ (RAND_MAX/(0.8f - 0.1f)));
    float initial_y (rand()/ (RAND_MAX/(0.8f - 0.1f)));
    std::cout << "Initial X: " << initial_x << " Initial Y: " << initial_y << std::endl;
    enemies[i].setCoords(initial_x, initial_y);
  }

  // Set initial coordinates for player
  float angle = 0.0f;
  float x = 0.0f;
  float y = 0.0f;

  // Define movement bounds
  Extent bounds = {0.8f, 0.8f, -0.8f, -0.8f};

  // References to models for collision detection
  // EnemyModel &enem1 = enemies[0];
  // EnemyModel &enem2 = enemies[1];
  // PlayerModel &pl = object1;

  // // Creating collision objects
  // Collision cols1(object1, enem1);
  // Collision cols2(pl, enem2);
  // Collision cols3(enem1, enem2);

  // Storing collisions in a vector
  // std::vector<Collision> cols;
  // cols.push_back(cols1);
  // cols.push_back(cols2);
  // cols.push_back(cols3);

  // Defining collision detected flag
  bool collisionDetected = false;

  // Game loop
  while (running) {

    // Handling inputs
    while (SDL_PollEvent(&event)) {
      // Quit
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
        running = false;
      }
      // Player movement
      if (event.type == SDL_KEYDOWN) {
        keyboardMovement(event, &angle, &x, &y, bounds);
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
    object1.draw_model(angle, x, y);

    for (int i = 0; i < enemies.size(); i++) {
      enemies[i].draw_model(bounds);
    };
    
    // // Collision detection
    // for (int i =0; i < cols.size(); i++) {
    //   collisionDetected = cols[i].nearObject(0.3f);
    //   if (collisionDetected) {
    //     std::cout << "Collision detected between objects!" << std::endl;
    //   }
    //   else {
    //     std::cout << "No collision." << std::endl;
    //   }
    // };
    // std::cout << "------------------------" << std::endl;

    // Update window
    window.renderOpenGL();
  }

  // Destroy window
  window.destroyWindow();
  return 0;
}