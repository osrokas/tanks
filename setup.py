from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

import os
import subprocess



def get_pkg_config_flags(config_name="sdl2-config"):
    """Get compiler and linker flags from pkg-config on Linux."""
    try:
        cflags = subprocess.check_output(['pkg-config', '--cflags', config_name]).decode('utf-8').strip().split()
        ldflags = subprocess.check_output(['pkg-config', '--libs', config_name]).decode('utf-8').strip().split()
        return cflags, ldflags
    except (subprocess.CalledProcessError, FileNotFoundError):
        return [], []
    
include_dirs = []
library_dirs = []
libraries = []
extra_compile_args = []
extra_link_args = []


sdl2_cflags, sdl2_libs = get_pkg_config_flags()

# SDL2_Image might have a different pkg-config name
sdl2_image_cflags, sdl2_image_libs = get_pkg_config_flags("SDL2_image")

if sdl2_cflags:
    extra_compile_args.extend(sdl2_cflags)
if sdl2_image_cflags:
    extra_compile_args.extend(sdl2_image_cflags)

if sdl2_libs:
    extra_link_args.extend(sdl2_libs)
if sdl2_image_libs:
    extra_link_args.extend(sdl2_image_libs)
# Define the extension module
ext_modules = [
    Pybind11Extension(
        "sdltest",  # Name of the Python module
        [
            "main.cpp",
            os.path.join("core", "Buffer.cpp"),
            os.path.join("core", "Window.cpp"),
            os.path.join("core", "Models.cpp"),
            os.path.join("core", "Shaders.cpp"),
            os.path.join("core", "Texture.cpp"),
            os.path.join("core", "KeyboardEvents.cpp"),
            os.path.join("core", "stb_image.cpp"),
            os.path.join("core", "Geometry.cpp"),
            os.path.join("glad", "src", "glad.c"),
            os.path.join("core", "Transformations.cpp"),
        ],  # source file
        include_dirs=[
            os.path.join("glad", "include"),
        ],
        # library_dirs=[
        #     r"C:/dev/SDL2 VC/SDL2/lib/x64",
        #     r"C:/CLibs/SDL2_image-2.8.2/lib/x64",
        # ],
        extra_compile_args=extra_compile_args,
        extra_link_args=extra_link_args,
        libraries=["SDL2", "SDL2_image", "GL"],
        cxx_std=17,  # Source file
    ),
]




# Set up the package
setup(
    name="sdltest",
    # headers=[
    #     "core/Window.h",
    #     "core/KeyboardEvents.h",
    #     "core/Geometry.h",
    #     "core/Shaders.h",
    #     "core/Sprites.h",
    #     "core/stb_image.h",
    #     "core/Buffer.h",
    #     "core/Models.h",
    #     "core/Texture.h",
    #     "core/Object.h",
    #     "core/Transformations.h",
    # ],
    version="0.2",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
)
