import sys

# Add the current directory to sys.path
sys.path.append(".")
import sdltest

coord1 = sdltest.Sprite(-0.1, -0.3, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0)
coord2 = sdltest.Sprite(0.1, -0.3, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0)
coord3 = sdltest.Sprite(0.1, 0.3, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0)
coord4 = sdltest.Sprite(-0.1, 0.3, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0)

indecies = [0, 1, 3, 1, 2, 3]

coord5 = sdltest.Sprite(-0.1, -0.3, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0)
coord6 = sdltest.Sprite(0.1, -0.3, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0)
coord7 = sdltest.Sprite(0.1, 0.3, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0)
coord8 = sdltest.Sprite(-0.1, 0.3, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0)


indecies2 = [0, 1, 3, 1, 2, 3]

vertex_shader_path = "C:\\dev\\tanks\\shaders\\v_rotate_shader.vert"
vertex_shader_path2 = "C:\\dev\\tanks\\shaders\\v_rotate_shader.vert"
fragment_shader_path = "C:\\dev\\tanks\\shaders\\f_shader.vert"
texture_path = "C:\\dev\\tanks\\asssets\\tank.JPG"

tank_object = sdltest.Object(
    vertex_shader_path,
    fragment_shader_path,
    texture_path,
    [coord1, coord2, coord3, coord4],
    indecies,
)

tank_object2 = sdltest.Object(
    vertex_shader_path2,
    fragment_shader_path,
    texture_path,
    [coord5, coord6, coord7, coord8],
    indecies2,
)

tank_object3 = sdltest.Object(
    vertex_shader_path2,
    fragment_shader_path,
    texture_path,
    [coord5, coord6, coord7, coord8],
    indecies2,
)


tanks = [
    tank_object]

enemies = [tank_object2, tank_object3]


sdltest.run(False, tanks, enemies)
