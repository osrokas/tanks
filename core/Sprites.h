#ifndef SPRITES_H
#define SPRITES_H
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h> // Windows sdl library
#include <SDL2/SDL_image.h>

class Sprite {
public:
    std::string path;
    int width;
    int height;
    Sprite(std::string img_path, SDL_Renderer *ren, int w, int h);
    void printPath();
    void loadImage();
    void loadSprite(float angle, int x, int y);

  private:
    SDL_Renderer *renderer;
    SDL_Texture *img;
    SDL_Rect texr;
};

class Player : public Sprite {
  std::string player_name;
};

#endif
