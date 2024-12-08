#include "Window.h"
#include "Sprites.h"

SDL::SDL(const char *title, int width, int height)
    : 
    sdl_tile(title), 
    screen_width(width), 
    screen_height(height),
    window(nullptr), 
    renderer(nullptr), 
    img(nullptr), 
    textures()  // empty vector should be only defined like this. textures(nullptr) ->inocrrect
  {}

bool SDL::initalize(){

    window = SDL_CreateWindow("Tanks", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, screen_width,
                              screen_height, SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    return true;
}

void SDL::load_sprites(Sprite *sprites, int n){
  for (int i = 0; i < n; i++) {
    img = IMG_LoadTexture(renderer, sprites[i].img_path.c_str());
    textures.push_back(img);
    }
}

void SDL::render_texture(Sprite *sprites, int n) {

  for (int i = 0; i < n; i++){
    SDL_Rect texr;
    texr.x = sprites[i].start_x;
    texr.y = sprites[i].start_y;
    texr.w = sprites[i].width;
    texr.h = sprites[i].height;
    SDL_RenderCopyEx(renderer, textures[i], NULL, &texr, sprites[i].angle, NULL, SDL_FLIP_NONE);
  }

  SDL_RenderPresent(renderer);
}

void SDL::clearWindow() { 
        SDL_RenderClear(renderer); 
}

void SDL::destroyWindow() { 
    SDL_DestroyRenderer(renderer); 
}