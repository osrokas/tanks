cmake_minimum_required(VERSION 3.14)
project(tanks)

# # Find Python and Pybind11
# find_package(Python3 3.10 EXACT)
find_package(pybind11 REQUIRED)

# Add SDL2
find_package(SDL2 REQUIRED)

# Add your C++ source files
add_library(tanks MODULE core/Sprites.cpp core/KeyboardEvents.cpp core/main.cpp)

# # Set the output file name for the Python module
# set_target_properties(tanks PROPERTIES
#     PREFIX ""
#     SUFFIX "${PYTHON3_MODULE_EXTENSION}"
# )

# Link against Pybind11
target_include_directories(tanks PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(tanks PRIVATE ${SDL2_LIBRARIES})