// For proper sdl initialization
#include <vector>
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "window.h"
#include <SDL2/SDL.h> // Windows sdl library
#include <SDL2/SDL_image.h>
#include "Sprites.h"


int run(std::vector<Sprite>& sprites) {

  // Variable declarations
  bool running; // Running state
  SDL_Event event;     // initialize sdl events

  // Creating window
  SDL window("Tanks", 600, 600);

  running =  window.initalize();

  window.load_sprites(sprites.data(), sprites.size());

  while (running) {
    while (SDL_PollEvent(&event)) { // Pointing to memory address
      if (event.type == SDL_QUIT) {
        running = false;
      }
      //   Get keyboard input
      else if (event.type == SDL_KEYDOWN) {
        keyboardMovement(event, &sprites[0]);
          }
        }     
      window.render_texture(sprites.data(), sprites.size());
      window.clearWindow();
    }
    window.destroyWindow();
    return 0;
  }




 