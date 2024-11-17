#include "KeyboardEvents.h"

void keyboardMovement(SDL_Event event, int *x, int *y, double *angle){
  switch (event.key.keysym.sym) {

    case SDLK_LEFT:
      *x = *x - 1;
      *angle = -90.0;
      return;

    case SDLK_RIGHT:
      *x = *x + 1;
      *angle = 90.0;
      return;

    case SDLK_UP:
      *y = *y - 1;
      *angle = 0.0;
      return;

    case SDLK_DOWN:
      *y = *y + 1;
      *angle = -180.0;
      return;

    default:
      *x = *x;
      *y = *y;
      *angle = *angle;
      return;
  }
}