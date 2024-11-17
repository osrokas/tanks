// For proper sdl initialization
#include <string>
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
  SDL_Texture* img;
  bool running = true; // Running state
  SDL_Event event;     // initialize sdl events

  int w, h; // texture width & height
  
  // Creating window
  window =
      SDL_CreateWindow("Tanks", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       screen_width, screen_height, SDL_WINDOW_OPENGL);

  // Create renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  Sprite tank(IMG_PATH, renderer, 200, 200);
  
      // SDL loop
  while (running) {
    // Check event inputs
    while (SDL_PollEvent(&event)) { // Pointing to memory address
      if (event.type == SDL_QUIT) {
        running = false;
      }
  //     //   Get keyboard input
  //     else if (event.type == SDL_KEYDOWN) {
  //       keyboardMovement(event, &texr.x, &texr.y, &angle);
  //     }
    }

    // Clear screen
    SDL_RenderClear(renderer);
    //  Load texture 
    tank.loadImage(img, 0);
    SDL_RenderPresent(renderer);
  // // }
  SDL_DestroyTexture(img);
  SDL_DestroyRenderer(renderer);
  }
  return 0;
}