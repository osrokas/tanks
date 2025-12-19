#define SDL_MAIN_HANDLED
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <SDL2/SDL.h>

#include "core/run.cpp"

namespace py = pybind11;


PYBIND11_MODULE(sdltest, m) {

  py::class_<Object>(m, "Object")
      .def(
          py::init<float, float, std::string &, std::string &, std::string &, std::vector<unsigned int> &>(),
          py::arg("width"), py::arg("length"), py::arg("vertex_shader"), py::arg("fragment_shader"),
          py::arg("texture_path"), py::arg("indecies"));

  m.def("run", &run, "load sprites");
}