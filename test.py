import os
import sdltest

tank1 = sdltest.Sprite(r"C:\dev\tanks\asssets\tank.png", 20, 20, 150, 150, 90)
tank2 = sdltest.Sprite(r"C:\dev\tanks\asssets\tank.png", 20, 20, 300, 300, 0)

tank3 = sdltest.Sprite(r"C:\dev\tanks\asssets\enemy_tank.png", 20, 20, 50, 50, 0)
tank4 = sdltest.Sprite(r"C:\dev\tanks\asssets\enemy_tank.png", 20, 20, 200, 100, 0)

sdltest.run([tank1, tank2, tank3, tank4])

