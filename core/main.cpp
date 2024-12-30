// For proper sdl initialization
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "Models.h"
#include "Shaders.h"
#include "Sprites.h"
#include "Texture.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>




int main() {
  const char *vertexShaderPath("C:\\dev\\tanks\\shaders\\v_shader.vert");
  const char *fragmentShaderPath("C:\\dev\\tanks\\shaders\\f_shader.vert");

  Sprite sprite1;
  Sprite sprite2;
  Sprite sprite3;
  Sprite sprite4;
  Sprite sprite5;
  Sprite sprite6;


  sprite1.x_pos = 0.5f;
  sprite1.y_pos = 0.5f;
  sprite1.z_pos = 0.0f;
  sprite1.r = 1.0f;
  sprite1.g = 0.0f;
  sprite1.b = 0.0f;
  sprite1.tx1 = 1.0f;
  sprite1.tx2 = 1.0f;

  sprite2.x_pos = 0.5f;
  sprite2.y_pos = -0.5f;
  sprite2.z_pos = 0.0f;
  sprite2.r = 0.0f;
  sprite2.g = 1.0f;
  sprite2.b = 0.0f;
  sprite2.tx1 = 1.0f;
  sprite2.tx2 = 0.0f;

  sprite3.x_pos = -0.3f;
  sprite3.y_pos = 0.3f;
  sprite3.z_pos = 0.0f;
  sprite3.r = 0.0f;
  sprite3.g = 0.0f;
  sprite3.b= 1.0f;
  sprite3.tx1 = 0.0f;
  sprite3.tx2 = 1.0f;

  sprite4.x_pos = 0.5f;
  sprite4.y_pos = -0.5f;
  sprite4.z_pos = 0.0f;
  sprite4.r = 0.0f;
  sprite4.g = 1.0f;
  sprite4.b = 0.0f;
  sprite4.tx1 = 1.0f;
  sprite4.tx2 = 0.0f;



  sprite5.x_pos = -0.5f;
  sprite5.y_pos = -0.5f;
  sprite5.z_pos = 0.0f;
  sprite5.r = 0.0f;
  sprite5.g = 1.0f;
  sprite5.b = 0.0f;
  sprite5.tx1 = 0.0f;
  sprite5.tx2 = 0.0f;


  sprite6.x_pos = -0.6f;
  sprite6.y_pos = 0.6f;
  sprite6.z_pos = 0.0f;
  sprite6.r = 0.0f;
  sprite6.g = 1.0f;
  sprite6.b = 0.0f;
  sprite6.tx1 = 0.0f;
  sprite6.tx2 = 1.0f;

  int nrAttributes;

  const char *wallTexturePath = "C:\\dev\\tanks\\asssets\\back.jpg";

  BaseModel object(vertexShaderPath, fragmentShaderPath, wallTexturePath);

  object.addVector(sprite1);
  object.addVector(sprite2);
  object.addVector(sprite3);
  object.addVector(sprite4);
  object.addVector(sprite5);
  object.addVector(sprite6);
  

  object.addIndex(0);
  object.addIndex(1);
  object.addIndex(2);
  object.addIndex(3);
  object.addIndex(4);
  object.addIndex(5);
  

  object.createSprite();
  // Variable declarations
  bool running; // Running state
  SDL_Event event; // initialize sdl events

  // Creating window
  SDL window("Tanks", 600, 600);

  running = window.initalize();

  object.create_model();
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
        object.draw_model();
        window.renderOpenGL();

      }
  window.destroyWindow();
}
