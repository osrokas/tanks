// For proper sdl initialization
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "Shaders.h"
#include "Sprites.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

Shader vertexShader("C:\\dev\\tanks\\shaders\\v_shader.vert");
Shader fragmentShader("C:\\dev\\tanks\\shaders\\f_shader.vert");

Sprite sprite1;
Sprite sprite2;
Sprite sprite3;

Sprite sprite4;
Sprite sprite5;
Sprite sprite6;


int main() {

  sprite1.x_pos = 0.5f;
  sprite1.y_pos = 0.5f;
  sprite1.z_pos = 0.0f;

  sprite2.x_pos = 0.5f;
  sprite2.y_pos = -0.5f;
  sprite2.z_pos = 0.0f;

  sprite3.x_pos = -0.3f;
  sprite3.y_pos = 0.3f;
  sprite3.z_pos = 0.0f;

  sprite4.x_pos = 0.5f;
  sprite4.y_pos = -0.5f;
  sprite4.z_pos = 0.0f;

  sprite5.x_pos = -0.5f;
  sprite5.y_pos = -0.5f;
  sprite5.z_pos = 0.0f;

  sprite6.x_pos = -0.6f;
  sprite6.y_pos = 0.6f;
  sprite6.z_pos = 0.0f;

  std::vector<Sprite> sprites;

  sprites.push_back(sprite1);
  sprites.push_back(sprite2);
  sprites.push_back(sprite3);
  sprites.push_back(sprite4);
  sprites.push_back(sprite5);
  sprites.push_back(sprite6);

  std::cout << sprites.size() << std::endl;
  Geometry triangle;

  for (int i = 0; i < sprites.size()+1; i++) {
    triangle.vertices.insert(
        triangle.vertices.end(),
        {sprites[i].x_pos, sprites[i].y_pos, sprites[i].z_pos});
    triangle.indecies.insert(triangle.indecies.end(), i);
  };
  int nrAttributes;

  // Variable declarations
  bool running;    // Running state
  SDL_Event event; // initialize sdl events

  // Creating window
  SDL window("Tanks", 600, 600);

  running = window.initalize();
  unsigned int vShader;
  unsigned int fShader;
  vShader = vertexShader.compileShader(GL_VERTEX_SHADER);
  fShader = fragmentShader.compileShader(GL_FRAGMENT_SHADER);

  ShaderProgram shader_program(vShader, fShader);

  shader_program.create();

  Buffer triangle_buffer(triangle);
  triangle_buffer.loadToBuffer(true);
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
        triangle_buffer.clearShader();
        shader_program.useShader();
        triangle_buffer.drawShader();
        window.renderOpenGL();

      }
  window.destroyWindow();
}
