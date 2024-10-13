#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>

class Game {

  // Public methods
public:
  // Constructor
  Game();
  // Destructor
  ~Game();

  // Initialize method
  void init(const char *title, int x, int y, int width, int height);
  void handleEvents();
  void update();
  void render();
  void clean();

  bool running();

private:
  bool isRunning;
  SDL_Winow *window;
  SDL_Renderer *renderer;
};

#endif /* Game_hpp */