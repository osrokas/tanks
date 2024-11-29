#include "Sprites.h"
#include <cstddef>

Sprite::Sprite(std::string img_path, int w, int h)
    : path{img_path}, width{w}, height{h}, img(nullptr) {}

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
  texr.w = width;
  texr.h = height;
  
  SDL_RenderCopyEx(renderer, img, NULL, &texr, angle, NULL,
                                   SDL_FLIP_NONE);

  SDL_RenderPresent(renderer);
}

// Player::Player(std::string img_path, SDL_Renderer *ren, int w, int h,
//                std::string name)
//     : Sprite(img_path, ren, w, h), player_name{name} 
// {}

// Enemy::Enemy(std::string img_path, SDL_Renderer *ren, int w, int h,
//              std::string name)
//     : Sprite(img_path, ren, w, h), enemy_name{name}
// {}

// void Enemy::movement(){
// }