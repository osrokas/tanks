#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "core/Window.h"
// #include "core/Sprites.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>

namespace py = pybind11;

// Expose the function to Python
PYBIND11_MODULE(sdltest, m) {
  py::class_<SDL>(m, "SDL")
      .def(py::init<const char *, int, int>(), py::arg("title"),
           py::arg("width"), py::arg("height"))
      .def("create_window", &SDL::initalize)
      .def("load_image", &SDL::load_image, py::arg("image_path"))
      .def("load_sprite", &SDL::render_texture, py::arg("angle"), py::arg("x"), py::arg("y"), py::arg("sprite_width"), py::arg("sprite_height"))
      .def("clear_window", &SDL::clearWindow)
      .def("destroy_window", &SDL::destroyWindow);

  //   py::class_<Sprite>(m, "Sprite")
  //       .def(py::init<std::shared_ptr<Allocator>, std::string, int, int>(),
  //            py::arg("renderer"), py::arg("img_path"), py::arg("w"),
  //            py::arg("h"))
  //       .def("load_image", &Sprite::loadImage)
  //       .def("load_sprite", &Sprite::loadSprite);

  //   py::class_<Sprite>(m, "Sprite")
  //       .def(py::init<std::string, int, int>(), py::arg("img_path"),
  //           py::arg("w"), py::arg("h"))
  //       .def("load_image", &Sprite::loadImage)
  //       .def("load_sprite", &Sprite::loadSprite);
  // }
}
