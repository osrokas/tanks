import sys

# Add the current directory to sys.path
sys.path.append(".")
import sdltest

# background = sdltest.Sprite(r"C:\dev\tanks\asssets\background.png", 600, 600, 0, 0, 0)

# tank1 = sdltest.Sprite(r"C:\dev\tanks\asssets\tank.png", 20, 20, 150, 150, 90)
# tank2 = sdltest.Sprite(r"C:\dev\tanks\asssets\enemy_tank.png", 20, 20, 300, 300, 0)

# tank3 = sdltest.Sprite(r"C:\dev\tanks\asssets\enemy_tank.png", 20, 20, 50, 50, 0)
# tank4 = sdltest.Sprite(r"C:\dev\tanks\asssets\enemy_tank.png", 20, 20, 200, 100, 0)

coord1 = sdltest.Sprite(-0.1, -0.3, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0)
coord2 = sdltest.Sprite(0.1, -0.3, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0)
coord3 = sdltest.Sprite(0.1, 0.3, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0)
coord4 = sdltest.Sprite(-0.1, 0.3, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0)

indecies = [0, 1, 3, 1, 2, 3]

coord5 = sdltest.Sprite(-0.5, -0.5, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0)
coord6 = sdltest.Sprite(-0.4, -0.5, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0)
coord7 = sdltest.Sprite(-0.4, -0.4, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0)
coord8 = sdltest.Sprite(-0.5, -0.4, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0)

indecies2 = [0, 1, 3, 1, 2, 3]

vertex_shader_path = "C:\\dev\\tanks\\shaders\\v_rotate_shader.vert"
vertex_shader_path2 = "C:\\dev\\tanks\\shaders\\v_shader.vert"
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


tanks = [tank_object, tank_object2]


sdltest.run(False, tanks)
