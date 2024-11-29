import os
# os.add_dll_directory(r"C:\dev\SDL2 VC\SDL2\lib\x64\SDL2.dll")
import sdltest
import time
from datetime import datetime
import keyboard

sdl_obj = sdltest.SDL("Labas", 1000, 800)

running = sdl_obj.create_window()

sdl_obj.load_image(r"C:\dev\tanks\asssets\tank.png")
# sdl_obj.load_image(r"C:\dev\tanks\asssets\enemy_tank.png")

# renderer = sdl_obj.getRenderer()

x = 20
y = 20

fps=1/100

increment = 4
time_inc = 0
angle = 0
event = keyboard.read_event

running_start = datetime.now()
while running:
    sdl_obj.load_sprite(angle, x, y, 50, 50)
    time.sleep(fps)
    sdl_obj.clear_window()
    event = keyboard.read_event()
    if event.event_type == keyboard.KEY_DOWN and event.name == 'down':
        y += increment
        angle = 180
    if event.event_type == keyboard.KEY_DOWN and event.name == 'up':
        y -= increment
        angle = 0
    if event.event_type == keyboard.KEY_DOWN and event.name == 'left':
        x -= increment
        angle = 270
    if event.event_type == keyboard.KEY_DOWN and event.name == 'right':
        x += increment
        angle = 90

    loop_time = datetime.now()
    loop_end = loop_time - running_start 
    loop_end.seconds
    # if loop_end.seconds > 5:
    #     sdl_obj.destroy_window()
