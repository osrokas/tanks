// For proper sdl initialization
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "window.h"
#include <SDL2/SDL.h> // Windows sdl library
#include <SDL2/SDL_image.h>
#include "Sprites.h"
#define IMG_PATH "C:\\dev\\tanks\\asssets\\tank.png"


int main(){

  // Variable declarations
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  bool running = true; // Running state
  SDL_Event event;     // initialize sdl events

  int x = 20;
  int y = 20;
  double angle = 0;

  // Creating window
  window =
      SDL_CreateWindow("Tanks", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       screen_width, screen_height, SDL_WINDOW_OPENGL);

  // Create renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  Sprite tank(IMG_PATH, renderer, 50, 50);
  tank.loadImage();

  // SDL loop
  while (running) {
    // Check event inputs
    while (SDL_PollEvent(&event)) { // Pointing to memory address
      if (event.type == SDL_QUIT) {
        running = false;
      }
      //   Get keyboard input
      else if (event.type == SDL_KEYDOWN) {
        keyboardMovement(event, &x, &y, &angle);
      }
    }
    // Clear screen
    SDL_RenderClear(renderer);
    //  Load texture
    tank.loadSprite(angle, x, y);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyRenderer(renderer);
  return 0;
}