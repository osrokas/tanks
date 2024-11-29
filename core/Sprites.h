#pragma once
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h> // Windows sdl library
#include <SDL2/SDL_image.h>

class Sprite {
public:
    std::string path;
    int width;
    int height;
    Sprite(std::string img_path, int w, int h);
    void printPath();
    void loadImage();
    void loadSprite(float angle, int x, int y);

  private:
    SDL_Rect texr;
};

// class Player : public Sprite {
// public:
//   std::string player_name;
//   Player(std::string img_path, SDL_Renderer *ren, int w, int h,
//          std::string name);
// };

// class Enemy : public Sprite {
// public:
//   std::string enemy_name;
//   Enemy(std::string img_path, SDL_Renderer *ren, int w, int h,
//         std::string name);
  
//   void movement();
// };