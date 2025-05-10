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

  py::class_<Object>(m, "Object")
      .def(
          py::init<std::string &, std::string &, std::string &, std::vector<struct Sprite> &, std::vector<unsigned int> &>(),
          py::arg("vertex_shader"), py::arg("fragment_shader"),
          py::arg("texture_path"), py::arg("sprites"), py::arg("indecies"));

  m.def("run", &run, "load sprites");
}