#include "Window.h"

SDL::SDL(const char *title, int width, int height)
    : sdl_tile(title), screen_width(width), screen_height(height),
      window(nullptr), renderer(nullptr), img(nullptr) {}


bool SDL::initalize(){

    window = SDL_CreateWindow("Tanks", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, screen_width,
                              screen_height, SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    return true;
}

void SDL::load_image(std::string image_path){
  img = IMG_LoadTexture(renderer, image_path.c_str());
}

void SDL::render_texture(float angle, int x, int y, int sprite_width, int sprite_height){
  SDL_Rect texr;
  texr.x = x;
  texr.y = y;
  texr.w = sprite_width;
  texr.h = sprite_height;

  SDL_RenderCopyEx(renderer, img, NULL, &texr, angle, NULL, SDL_FLIP_NONE);
  SDL_RenderPresent(renderer);
}

void SDL::clearWindow() { 
        SDL_RenderClear(renderer); 
}

void SDL::destroyWindow() { 
    SDL_DestroyRenderer(renderer); 
}

// class Renderer {
//     public:
//       Renderer(SDL_Window *window) {
//         renderer = SDL_CreateRenderer(window, -1,
//         SDL_RENDERER_ACCELERATED);
//       }
//     private:
//     SDL_Renderer *renderer = NULL;
// };