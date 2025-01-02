from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

# Define the extension module
ext_modules = [
    Pybind11Extension(
        "sdltest",  # Name of the Python module
        [
            "main.cpp",
            "core/Buffer.cpp",
            "core/Window.cpp",
            "core/Models.cpp",
            "core/Shaders.cpp",
            "core/Texture.cpp",
            "core/KeyboardEvents.cpp",
            "core/stb_image.cpp",
            r"C:/CLibs/glad/src/glad.c",
        ],  # source file
        include_dirs=[
            r"C:/dev/SDL2 VC/SDL2/include",
            r"C:/CLibs/SDL2_image-2.8.2/include",
            r"C:/CLibs/glad/include",
        ],
        library_dirs=[
            r"C:/dev/SDL2 VC/SDL2/lib/x64",
            r"C:/CLibs/SDL2_image-2.8.2/lib/x64",
        ],
        libraries=["SDL2", "SDL2_image", "opengl32"],
        cxx_std=17,  # Source file
    ),
]


# Set up the package
setup(
    name="sdltest",
    headers=[
        "core/Window.h",
        "core/KeyboardEvents.h",
        "core/Geometry.h",
        "core/Shaders.h",
        "core/Sprites.h",
        "core/stb_image.h",
        "core/Buffer.h",
        "core/Models.h",
        "core/Texture.h",
        "core/Object.h"
    ],
    version="0.2",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
)
