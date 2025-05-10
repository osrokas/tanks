#pragma once
#include <cstddef>
#define SDL_MAIN_HANDLED
#include "Sprites.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "glad/glad.h"
#include <iostream>
#include <vector>


class SDL {
    public:
      int screen_width; 
      int screen_height;
      const char *sdl_tile; 
      bool running = true;
      SDL(const char *title, int width, int height);
      bool initalize();
      void sdlRunning();
      void load_sprites(Sprite sprites[], int n);
      void render_texture(Sprite *sprites, int n);
      void clearWindow();
      void destroyWindow();
      void renderOpenGL();

    private:
      SDL_Window* window = NULL;
      SDL_Renderer* renderer = NULL;
      SDL_Texture* img = NULL;
      SDL_GLContext opengl_context = NULL;
      std::vector<SDL_Texture *> textures;
};