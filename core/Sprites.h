#ifndef SPRITES_H
#define SPRITES_H
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h> // Windows sdl library
#include <SDL2/SDL_image.h>

class Sprite {
public:
    std::string path;
    int widht, height;
    Sprite(std::string img_path, SDL_Renderer *ren, int w, int h);
    void printPath();
    void loadImage(SDL_Texture *image, float angle);

  private:
    SDL_Renderer *renderer;
    SDL_Texture *img;
    SDL_Rect texr;
};

#endif
