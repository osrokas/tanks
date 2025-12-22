import sys

# Add the current directory to sys.path
sys.path.append(".")
import sdltest
import os
# coord1 = sdltest.Sprite(-0.1, -0.3, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0)
# coord2 = sdltest.Sprite(0.1, -0.3, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0)
# coord3 = sdltest.Sprite(0.1, 0.3, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0)
# coord4 = sdltest.Sprite(-0.1, 0.3, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0)

indecies = [0, 1, 3, 1, 2, 3]

# coord5 = sdltest.Sprite(-0.1, -0.3, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0)
# coord6 = sdltest.Sprite(0.1, -0.3, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0)
# coord7 = sdltest.Sprite(0.1, 0.3, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0)
# coord8 = sdltest.Sprite(-0.1, 0.3, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0)


# vertex_shader_path = "tanks\\shaders\\v_rotate_shader.vert"
# vertex_shader_path2 = "tanks\\shaders\\v_rotate_shader.vert"
# fragment_shader_path = "tanks\\shaders\\f_shader.vert"
# texture_path = "tanks\\asssets\\tank.JPG"

vertex_shader_path = os.path.join("shaders", "v_rotate_shader.vert")
fragment_shader_path = os.path.join("shaders", "f_shader.vert")
texture_path = os.path.join("asssets", "tank.JPG")


tank_object = sdltest.Object(
    0.1,
    0.2,
    vertex_shader_path,
    fragment_shader_path,
    texture_path,
    indecies
)

tank_object2 = sdltest.Object(
    0.1,
    0.2,
    vertex_shader_path,
    fragment_shader_path,
    texture_path,
    indecies,
)

tank_object3 = sdltest.Object(
    0.1,
    0.2,
    vertex_shader_path,
    fragment_shader_path,
    texture_path,
    indecies,
)


tanks = [
    tank_object]

enemies = [tank_object2, tank_object3]


sdltest.run(False, tanks, enemies)
