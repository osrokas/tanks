#include "Models.h"
#include "Transformations.h"
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

  Object playerObject = objects[0];

  PlayerModel playerObjectModel(
      playerObject.width, playerObject.length,
      playerObject.vertexShaderPath, playerObject.fragmentShaderPath,
      playerObject.wallTexturePath1,
      playerObject.indecies);

  std::vector<EnemyModel> enemiesModel;

  for (int i = 0; i < enemies.size(); i++){
    EnemyModel object(enemies[i].width, enemies[i].length,
                      enemies[i].vertexShaderPath,
                      enemies[i].fragmentShaderPath,
                      enemies[i].wallTexturePath1,
                      enemies[i].indecies);

    enemiesModel.push_back(object);
  };

  playerObjectModel.create_object();

  for (int i = 0; i < enemiesModel.size(); i++) {
    enemiesModel[i].create_object();
  };

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
        keyboardMovement(event, &angle, &x, &y, bounds);
      }
      // Resizing window
      if (event.type == SDL_WINDOWEVENT) {
        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
          // Update OpenGL viewport
        }
      }
    }
    // Updating game view 
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Drawing objects on the screen
    playerObjectModel.draw_model(angle, x, y);
    for (int i = 0; i < enemiesModel.size(); i++) {
      enemiesModel[i].draw_model();
    };
    // Render updates
    window.renderOpenGL();
  }
  // Destroy window
  window.destroyWindow();
  return 0;
}