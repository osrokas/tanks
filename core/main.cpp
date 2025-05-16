// For proper sdl initialization
#include "SDL2/SDL_keycode.h"
#include "Transformations.h"
#include <vector>
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "Models.h"
#include "Sprites.h"
#include "Window.h"
#include "glad/glad.h"

int main() {
  const char *vertexShaderPath("C:\\dev\\tanks\\shaders\\v_rotate_shader.vert");
  const char *fragmentShaderPath("C:\\dev\\tanks\\shaders\\f_shader.vert");
  const char *wallTexturePath1 = "C:\\dev\\tanks\\asssets\\tank.JPG";
  const char *txt = "C:\\dev\\tanks\\asssets\\wall.jpg";

  Sprite sprite1 = {-0.1, -0.3, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0};
  Sprite sprite2 = {0.1, -0.3, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0};
  Sprite sprite3 = {0.1, 0.3, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
  Sprite sprite4 = {-0.1, 0.3, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0};

  Sprite sprite5 = {-0.1, -0.3, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0};
  Sprite sprite6 = {0.1, -0.3, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0};
  Sprite sprite7 = {0.1, 0.3, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
  Sprite sprite8 = {-0.1, 0.3, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0};

  Sprite sprite9 = {-0.5, -0.5, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0};
  Sprite sprite10 = {-0.4, -0.5, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0};
  Sprite sprite11 = {-0.4, -0.4, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
  Sprite sprite12 = {-0.5, -0.4, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0};

  // Creating indecies for the sprites
  std::vector<unsigned int> indecies2;
  indecies2.push_back(0);
  indecies2.push_back(1);
  indecies2.push_back(3);
  indecies2.push_back(1);
  indecies2.push_back(2);
  indecies2.push_back(3);

  std::vector<Sprite> spritesVector2;
  spritesVector2.push_back(sprite5);
  spritesVector2.push_back(sprite6);
  spritesVector2.push_back(sprite7);
  spritesVector2.push_back(sprite8);

  std::vector<Sprite> spritesVector;
  spritesVector.push_back(sprite1);
  spritesVector.push_back(sprite2);
  spritesVector.push_back(sprite3);
  spritesVector.push_back(sprite4);

  std::vector<unsigned int> indecies;
  indecies.push_back(0);
  indecies.push_back(1);
  indecies.push_back(3);
  indecies.push_back(1);
  indecies.push_back(2);
  indecies.push_back(3);

  // Add sprites into vector
  std::vector<Sprite> spritesVector3;
  spritesVector3.push_back(sprite9);
  spritesVector3.push_back(sprite10);
  spritesVector3.push_back(sprite11);
  spritesVector3.push_back(sprite12);

  

  bool running; // Running state
  SDL_Event event; // initialize sdl events

  // Creating window
  SDL window("Tanks", 600, 600);

  running = window.initalize();

  PlayerModel object1 = {vertexShaderPath, fragmentShaderPath, wallTexturePath1,
                       spritesVector, indecies};

  EnemyModel object2 = {vertexShaderPath, fragmentShaderPath, wallTexturePath1,
                       spritesVector2, indecies2};

  EnemyModel object3 = {vertexShaderPath, fragmentShaderPath, wallTexturePath1,
                        spritesVector3, indecies2};

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

    window.renderOpenGL();
  }
  // Destroy window
  window.destroyWindow();
  return 0;
}