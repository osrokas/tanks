import sys

# Add the current directory to sys.path
sys.path.append(".")
import sdltest

# background = sdltest.Sprite(r"C:\dev\tanks\asssets\background.png", 600, 600, 0, 0, 0)

# tank1 = sdltest.Sprite(r"C:\dev\tanks\asssets\tank.png", 20, 20, 150, 150, 90)
# tank2 = sdltest.Sprite(r"C:\dev\tanks\asssets\enemy_tank.png", 20, 20, 300, 300, 0)

# tank3 = sdltest.Sprite(r"C:\dev\tanks\asssets\enemy_tank.png", 20, 20, 50, 50, 0)
# tank4 = sdltest.Sprite(r"C:\dev\tanks\asssets\enemy_tank.png", 20, 20, 200, 100, 0)

coord1 = sdltest.Sprite(0.5, 0.2, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0)
coord2 = sdltest.Sprite(0.5, 0.3, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0)
coord3 = sdltest.Sprite(0.3, 0.3, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0)
coord4 = sdltest.Sprite(0.3, 0.2, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0)


indecies = [0,1,3,1,2,3]

texture_path = r"C:\dev\tanks\asssets\tank.JPG"
vertex_shader_path = r"C:\dev\tanks\shaders\v_shader.vert"
fragment_shader_path = r"C:\dev\tanks\shaders\f_shader.vert"


sdltest.run(
    False,
    [coord1, coord2, coord3, coord4],
    indecies,
    texture_path,
    vertex_shader_path,
    fragment_shader_path,
)
