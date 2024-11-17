#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h> /* Windows-specific SDL2 library */

/* Sets constants */
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char **argv) {

  // Creating window
  SDL_Window *window =
      SDL_CreateWindow("Tanks", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       SCREEN_WIDTH, SCREEN_HEIGHT, 0);

  // Creating renderer
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

  // bool running = true;
  // while (running) {
  //   SDL_Event event;
  //   while (SDL_PollEvent(&event)) {
  //     switch (event.type) {
  //     case SDL_QUIT:
  //       running = false;
  //       break;

  //     default:
  //       break;
  //     }
  //   }

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);
  SDL_Delay(3000);

  return 0;
}