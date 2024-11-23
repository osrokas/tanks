import os
# os.add_dll_directory(r"C:\dev\SDL2 VC\SDL2\lib\x64\SDL2.dll")
import sdltest


result = sdltest.SDL("Labas", 1000, 800)
print(f"Result of addition: {result}")
