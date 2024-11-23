#define SDL_MAIN_HANDLED
// #include "window.h"
// #include "KeyboardEvents.h"
// #include "Sprites.h"
#include <SDL2/SDL.h> // Windows sdl library
// #include <SDL2/SDL_image.h>

// #define IMG_PATH "C:\\dev\\tanks\\asssets\\tank.png"
// #define ENEMY_TANK "C:\\dev\\tanks\\asssets\\enemy_tank.png"


class SDL {
    public:
      SDL(const char *title, int screen_width, int screen_height) {
        window = SDL_CreateWindow(
            title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width,
            screen_height, SDL_WINDOW_OPENGL);
      }

        ~SDL() { SDL_DestroyWindow(window); 
      }
      private:
      SDL_Window *window = NULL;
};

class Renderer {
    public:
      Renderer(SDL_Window *window) {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
      }
    private:
    SDL_Renderer *renderer = NULL;
}