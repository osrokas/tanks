#include "Transformations.h"
#include <iostream>
#include <ostream>
#include <vector>
#define SDL_MAIN_HANDLED // For proper sdl initialization
#include "KeyboardEvents.h"
#include "Object.h"
#include "Window.h"


int run(bool wireframe, std::vector<Object> objects, std::vector<Object> enemies) {

  bool running; // Running state
  SDL_Event event; // initialize sdl events
  
  // Creating window
  SDL window("Tanks", 600, 600);

  running = window.initalize();

  // Create players object
  Objects players(objects);
  Objects enmiesObjects(enemies);

  // Add data to object
  players.add_data();
  enmiesObjects.add_data();

  // Set initial coordinates for player
  float angle = 0.0f;
  float x = 0.0f;
  float y = 0.0f;

  Extent bounds = {0.8f, 0.8f, -0.8f, -0.8f}; // Game loop
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
        std::cout << angle << std::endl;
      }
      // Resizing window
      if (event.type == SDL_WINDOWEVENT) {
        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
          // Update OpenGL viewport
        }
      }
    
    // Updating game view 
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Drawing objects on the screen
    players.draw(angle, x, y, bounds);
    enmiesObjects.draw(angle, 0.1f, 0.4f, bounds);
    
    // Render updates
    window.renderOpenGL();
    }
  }
  // Destroy window
  window.destroyWindow();
  return 0;
}