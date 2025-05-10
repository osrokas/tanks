// For proper sdl initialization
#include "SDL2/SDL_keycode.h"
#include "Transformations.h"
#include <vector>
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "Object.h"
#include "Sprites.h"
#include "Window.h"
#include "glad/glad.h"

int main() {
  const char *vertexShaderPath("C:\\dev\\tanks\\shaders\\v_rotate_shader.vert");
  const char *fragmentShaderPath("C:\\dev\\tanks\\shaders\\f_shader.vert");
  const char *wallTexturePath1 = "C:\\dev\\tanks\\asssets\\tank.JPG";
  const char *txt = "C:\\dev\\tanks\\asssets\\wall.jpg";

  std::vector<Object>objects;
  std::vector<Object>enemies;

  Sprite sprite1 = {-0.1, -0.3, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0};
  Sprite sprite2 = {0.1, -0.3, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0};
  Sprite sprite3 = {0.1, 0.3, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
  Sprite sprite4 = {-0.1, 0.3, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0};

  // Sprite sprite5 = {-0.1, -0.3, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0};
  // Sprite sprite6 = {0.1, -0.3, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0};
  // Sprite sprite7 = {0.1, 0.3, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
  // Sprite sprite8 = {-0.1, 0.3, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0};

  Sprite sprite5 = {-0.5, -0.5, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0};
  Sprite sprite6 = {-0.4, -0.5, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0};
  Sprite sprite7 = {-0.4, -0.4, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
  Sprite sprite8 = {-0.5, -0.4, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0};

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

  Object object1 = {vertexShaderPath, fragmentShaderPath, wallTexturePath1,
                    spritesVector, indecies};

  // Creating object
  Object object2 = {vertexShaderPath, fragmentShaderPath, txt,
                    spritesVector2, indecies2};

  objects.push_back(object1);
  enemies.push_back(object2);

  bool running;    // Running state
  SDL_Event event; // initialize sdl events

  // Creating window
  SDL window("Tanks", 600, 600);

  running = window.initalize();

  // Create players object
  Objects players(objects);

  Objects enemiesObjects(enemies);

      // Add data to object
  players.add_data();
  enemiesObjects.add_data();
  // enemies.add_data();
  players.set_positions();
  enemiesObjects.set_positions();

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
      
      // Draw objects
      players.draw(angle, x, y, bounds);
      enemiesObjects.draw(angle, x, y, bounds);

      // Render updates
      window.renderOpenGL();
    }
  }
  // Destroy window
  window.destroyWindow();
  return 0;
}