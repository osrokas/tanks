#include "Sprites.h"

Sprite::Sprite(std::string img_path, SDL_Renderer *ren, int w, int h)
    : path{img_path},
    renderer(ren),
    widht{w},
    height{h},
    img(nullptr)
{}

void Sprite::printPath() {
    std::cout << path << std::endl;
}

void Sprite::loadImage() { 
  img = IMG_LoadTexture(renderer, path.c_str()); 
}

void Sprite::loadSprite(float angle, int x, int y) {
  // Render sprite to renderer object
  SDL_Rect texr;
  texr.x = x;
  texr.y = y;
  texr.w = widht;
  texr.h = height;

  SDL_RenderCopyEx(renderer, img, NULL, &texr, angle, NULL,
                                   SDL_FLIP_NONE);
}
