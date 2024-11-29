#pragma once
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class SDL {
    public:
      int screen_width; 
      int screen_height;
      const char *sdl_tile; 
      bool running = true;
      SDL(const char *title, int width, int height);
      bool initalize();
      void sdlRunning();
      void load_image(std::string image_path);
      void render_texture(float angle, int x, int y, int sprite_width,
                          int sprite_height);
      void clearWindow();
      void destroyWindow();

    private:
      SDL_Window* window = NULL;
      SDL_Renderer* renderer = NULL;
      SDL_Texture* img = NULL;
};