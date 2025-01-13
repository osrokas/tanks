#include "KeyboardEvents.h"


void keyboardMovement(SDL_Event event, float *angle, float *x, float *y) {
  switch (event.key.keysym.sym) {

    case SDLK_LEFT:
      *angle = 270.0f;
      *x = *x -0.01;
      return;

    case SDLK_RIGHT:
      *angle = 90.0f;
      *x = *x + 0.01;
      return;

    case SDLK_UP:
      *angle = 180.0f;
      *y = *y + 0.01;
      return;

    case SDLK_DOWN:
      *angle = 0.0f;
      *y = *y - 0.01;
      return;
  }
}