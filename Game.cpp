#include "Game.hpp"

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int x, int y, int width, int height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "Subsystems initialized!..." << std::endl;

    window = SDL_CreateWindow(title, x, y, width, height, 0);
  }
}
void Game::handleEvents() {}

void Game::update() {}

void Game::render() {}

void Game::clean() {}