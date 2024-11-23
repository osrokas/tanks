from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

# Define the extension module
ext_modules = [
    Pybind11Extension(
        "sdltest",  # Name of the Python module
        ["main.cpp", "core/Window.cpp"],
        include_dirs=[
            "C:/dev/SDL2 VC/SDL2/include",
            "C:/CLibs/SDL2_image-2.8.2/SDL2/include",
        ],
        library_dirs=[
            "C:/dev/SDL2 VC/SDL2/lib/x64",
            "C:/CLibs/SDL2_image-2.8.2/lib/x64",
        ],
        libraries=["SDL2", "SDL2_image"],  # Source file
    ),
]

# Set up the package
setup(
    name="sdltest",
    version="0.1",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
)
