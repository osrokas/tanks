#include "KeyboardEvents.h"

int keyboardEvent(SDL_Event event, SDL_Rect texr) {
  int value;
  if (event.key.keysym.sym == SDLK_LEFT) {
    value = texr.x - 1; 
    std::cout << "You press left arrow" << std::endl;
    std::cout << texr.x << std::endl;
  } 
  else if (event.key.keysym.sym == SDLK_RIGHT) {
    std::cout << "You press right arrow" << std::endl;
    value = texr.y - 1;
  }
  return value;
  }
  
