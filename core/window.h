#pragma once
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class SDL {
    public:
      int screen_width; 
      int screen_height;
      const char *sdl_tile; 
      bool running = true;
      SDL(const char *title, int width, int height);
      bool initalize();
      void sdlRunning();
      void *getRenderer();

    private:
      SDL_Window* window = NULL;
      SDL_Renderer* renderer = NULL;
};