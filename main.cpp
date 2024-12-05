#include "core/Sprites.h"
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "core/Window.h"
// #include "core/Sprites.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>
#include "core/run.cpp"

namespace py = pybind11;


PYBIND11_MODULE(sdltest, m) {
  py::class_<Sprite>(m, "Sprite")
      .def(py::init<std::string, int, int, int, int, int>(),
      py::arg("img_path"), py::arg("width"), py::arg("height"),
      py::arg("start_x"), py::arg("start_y"), py::arg("angle"));
  
  m.def("run", &run, "load sprites");
}


