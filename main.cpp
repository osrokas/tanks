#define SDL_MAIN_HANDLED
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <SDL2/SDL.h>

#include "core/run.cpp"

namespace py = pybind11;


PYBIND11_MODULE(sdltest, m) {
  py::class_<Sprite>(m, "Sprite")
      .def(py::init<float, float, float, float, float, float, float, float>(),
           py::arg("x_pos"), py::arg("y_pos"), py::arg("z_pos"),
           py::arg("r"), py::arg("g"), py::arg("b"), py::arg("tx1"), py::arg("tx2"));

  m.def("run", &run, "load sprites");
}


