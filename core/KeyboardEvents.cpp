#include "KeyboardEvents.h"
#include "Sprites.h"

// void keyboardMovement(SDL_Event event, Sprite *sprite) {
//   switch (event.key.keysym.sym) {

//     case SDLK_LEFT:
//       sprite->start_x = sprite->start_x - 1;
//       sprite->angle = -90.0;
//       return;

//     case SDLK_RIGHT:
//       sprite->start_x = sprite->start_x + 1;
//       sprite->angle = 90;
//       return;

//     case SDLK_UP:
//       sprite->start_y = sprite->start_y - 1;
//       sprite->angle = 0;
//       return;

//     case SDLK_DOWN:
//       sprite->start_y = sprite->start_y + 1;
//       sprite->angle = 180;
//       return;

//     default:
//       sprite->start_y = sprite->start_y;
//       sprite->start_x = sprite->start_x;
//       sprite->angle = sprite->angle;
//       return;
//   }
// }