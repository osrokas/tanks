// For proper sdl initialization
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "window.h"
#include <SDL2/SDL.h> // Windows sdl library
#include <SDL2/SDL_image.h>
#include "Sprites.h"
#define IMG_PATH "C:\\dev\\tanks\\asssets\\tank.png"
#define ENEMY_TANK "C:\\dev\\tanks\\asssets\\enemy_tank.png"

int main(){

  // Variable declarations
  bool running; // Running state
  SDL_Event event;     // initialize sdl events
  int x = 20;
  int y = 20;
  double angle = 0;
  
  // Creating window
  SDL window("Tanks", 600, 600);

  running = window.initalize();

  Sprite tank(IMG_PATH, 100, 100);
  tank.loadImage();
  while (running) {

    while (SDL_PollEvent(&event)) { // Pointing to memory address
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }
    tank.loadSprite(45.2, 50, 50);
  }

  // Creating window

  // // Create renderer
  // renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);



  // Enemy enemy_tank_1(ENEMY_TANK, renderer, 50, 50, "enemy1");
  // enemy_tank_1.loadImage();

  // Enemy enemy_tank_2(ENEMY_TANK, renderer, 50, 50, "enemy2");
  // enemy_tank_2.loadImage();

  // // SDL loop
  // while (running) {
  //   // Check event inputs
  //   while (SDL_PollEvent(&event)) { // Pointing to memory address
  //     if (event.type == SDL_QUIT) {
  //       running = false;
  //     }
  //     //   Get keyboard input
  //     else if (event.type == SDL_KEYDOWN) {
  //       keyboardMovement(event, &x, &y, &angle);
  //     }
  //   }
  //   // Clear screen
  //   SDL_RenderClear(renderer);
  //   //  Load texture
  //   tank.loadSprite(angle, x, y);
  //   enemy_tank_1.loadSprite(45.0, 200, 300);
  //   enemy_tank_2.loadSprite(90.0, 600, 400);
    // SDL_RenderPresent(renderer);
  // SDL_DestroyRenderer(renderer);
  return 0;
}