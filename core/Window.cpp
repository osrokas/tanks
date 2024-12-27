#include "Window.h"
#include <cstddef>


SDL::SDL(const char *title, int width, int height)
    : 
    sdl_tile(title), 
    screen_width(width), 
    screen_height(height),
    window(nullptr), 
    renderer(nullptr), 
    img(nullptr),
    opengl_context(NULL),
    textures()  // empty vector should be only defined like this. textures(nullptr) ->inocrrect
  {}

bool SDL::initalize(){

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  window =
      SDL_CreateWindow("Tanks", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       screen_width, screen_height, SDL_WINDOW_OPENGL);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // Create an OpenGL context associated with the window.
  opengl_context = SDL_GL_CreateContext(window);
  
  gladLoadGLLoader(SDL_GL_GetProcAddress);

  SDL_GetWindowSize(window, &screen_width, &screen_height);
  glViewport(0, 0, screen_width, screen_height);
  return true;
}

void SDL::clearWindow() { 
        SDL_RenderClear(renderer); 
}

void SDL::destroyWindow() { 
    SDL_DestroyRenderer(renderer); 
}

void SDL::renderOpenGL() { SDL_GL_SwapWindow(window);}