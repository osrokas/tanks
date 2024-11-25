#include "Window.h"

SDL::SDL(const char *title, int width, int height)
    : sdl_tile(title), screen_width(width), screen_height(height),
      window(nullptr), renderer(nullptr) {}


bool SDL::initalize(){

    window = SDL_CreateWindow("Tanks", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, screen_width,
                              screen_height, SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    return true;
}

void *SDL::getRenderer() { return static_cast<void *>(renderer); }

void SDL::sdlRunning() { 
    while (running){
        running = true;
    };
    }

// class Renderer {
//     public:
//       Renderer(SDL_Window *window) {
//         renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//       }
//     private:
//     SDL_Renderer *renderer = NULL;
// };