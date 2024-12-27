// For proper sdl initialization
#include <vector>
  // For proper sdl initialization
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "Shaders.h"
#include "Sprites.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


int run(bool wireframe, std::vector<Sprite> &sprites, const char *texture_path) {
  Shader vertexShader("C:\\dev\\tanks\\shaders\\v_shader.vert");
  Shader fragmentShader("C:\\dev\\tanks\\shaders\\f_shader.vert");
  Geometry triangle;
  for (int i =0 ; i < sprites.size(); i++){
    triangle.vertices.insert(triangle.vertices.end(),
                             {sprites[i].x_pos, sprites[i].y_pos,
                              sprites[i].z_pos, sprites[i].r, sprites[i].g,
                              sprites[i].b, sprites[i].tx1, sprites[i].tx2});
    triangle.indecies.insert(triangle.indecies.end(), i);
  };


  unsigned int vShader;
  unsigned int fShader;
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
  triangle_buffer.loadToBuffer(wireframe);

  Texture triangle_texture(texture_path);

  triangle_texture.load_texture();

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
    triangle_texture.draw_texture();
    shader_program.useShader();
    triangle_buffer.drawShader();
    window.renderOpenGL();
  }
  window.destroyWindow();
  return 0;
}