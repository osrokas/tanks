// For proper sdl initialization
#define SDL_MAIN_HANDLED
#include "KeyboardEvents.h"
#include "window.h"
#include <SDL2/SDL.h> // Windows sdl library
#include <SDL2/SDL_image.h>
// #include <string>
#define IMG_PATH "C:\\dev\\tanks\\asssets\\tank.png"

// class Image {
//     public:
//         std::string& img_path;
//         // Loading texture
//         SDL_Texture loadImgTexture(SDL_Renderer *renderer, SDL_Texture *img) {
//           IMG_LoadTexture(renderer, img_path);
//         }
// };

int main(){
  // Variable declarations
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture *img = NULL;
  bool running = true; // Running state
  SDL_Event event;     // initialize sdl events
  int w, h; // texture width & height
  int value;
  // Creating window
  window =
      SDL_CreateWindow("Tanks", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       screen_width, screen_height, SDL_WINDOW_OPENGL);

  // Create renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

//   tank.img_path = "C:\\dev\\tanks\\asssets\\tank.png";
  img = IMG_LoadTexture(renderer, IMG_PATH);
//   img = tank.loadImgTexture(renderer, img);

  SDL_QueryTexture(img, NULL, NULL, &w, &h);
  SDL_Rect texr;
  texr.x = screen_width / 2;
  texr.y = screen_height / 2;
  texr.w = w / 6;
  texr.h = h / 6;
  double angle = 0;

      // SDL loop
  while (running) {
    // Check event inputs
    while (SDL_PollEvent(&event)) { // Pointing to memory address
      if (event.type == SDL_QUIT) {
        running = false;
      }
      //   Get keyboard input
      else if (event.type == SDL_KEYDOWN) {
        keyboardMovement(event, &texr.x, &texr.y, &angle);
      }
    }

    // Clear screen
    SDL_RenderClear(renderer);
    SDL_RenderCopyEx(renderer, img, NULL, &texr, angle, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyTexture(img);
  SDL_DestroyRenderer(renderer);
  
  return 0;
}