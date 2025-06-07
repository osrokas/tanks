#include "SDL2/SDL.h" // Windows sdl library
#include <iostream>
#include "..\core\Sprites.h"
#include "Transformations.h"

void keyboardMovement(SDL_Event event, float *angle, float *x, float *y, Extent bounds);
