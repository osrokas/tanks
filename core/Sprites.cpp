#include "Sprites.h"

Sprite::Sprite(std::string img_path, SDL_Renderer *ren, int w, int h)
    : path{img_path},
    renderer(ren),
    widht{w},
    height{h}
{}

void Sprite::printPath() {
    std::cout << path << std::endl;
}

void Sprite::loadImage(SDL_Texture *img, float angle) {
  img = IMG_LoadTexture(renderer, path.c_str());
  // SDL_QueryTexture(img, NULL, NULL, &widht, &height);
  SDL_Rect texr;
  texr.x = 20;
  texr.y = 20;
  texr.w = widht;
  texr.h = height;
  std::cout << widht << std::endl;
  std::cout << height << std::endl;
  SDL_RenderCopyEx(renderer, img, NULL, &texr, angle, NULL,
                                   SDL_FLIP_NONE);
}
