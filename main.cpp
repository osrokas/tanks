#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "core/Window.cpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;


int main(int argc, char **argv) { 

  SDL("Tanks", 100, 100);

  return 0;
}

// Expose the function to Python
PYBIND11_MODULE(sdltest, m) {
  py::class_<SDL>(m, "SDL").def(py::init<const char*, int, int>(),
                                py::arg("title"), py::arg("screen_width"),
                                py::arg("screen_height"));
}