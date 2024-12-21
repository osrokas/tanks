// For proper sdl initialization
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "Shaders.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Shader vertexShader("C:\\dev\\tanks\\shaders\\v_shader.vert");
Shader fragmentShader("C:\\dev\\tanks\\shaders\\f_shader.vert");

int main() {
  Geometry triangle;
  unsigned int vShader;
  unsigned int fShader;
  triangle.vertices.insert(triangle.vertices.end(),{
                            0.1f, 0.1f, 0.0f,               
                            0.5f, -0.8f, 0.0f,  
                           -0.5f, -0.5f, 0.0f, 
                           -0.1f, 0.4f, 0.0f   } );

  triangle.indecies.insert(triangle.indecies.end(),{ 0, 1, 3,
                           1, 2, 3}                           
  );
  int nrAttributes;

  // Variable declarations
  bool running;    // Running state
  SDL_Event event; // initialize sdl events

  // Creating window
  SDL window("Tanks", 600, 600);

  running = window.initalize();

  vShader = vertexShader.compileShader(GL_VERTEX_SHADER);
  fShader = fragmentShader.compileShader(GL_FRAGMENT_SHADER);

  ShaderProgram shader_program(vShader, fShader);

  shader_program.create();

  Buffer triangle_buffer(triangle);
  triangle_buffer.loadToBuffer(false);
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
