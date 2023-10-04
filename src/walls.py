from structures import Wall
from tkinter import *


class WallReneder:
    """ """

    def __init__(self, canvas: Canvas) -> None:
        self.canas = canvas

    def load_walls(walls: list[Wall]):
        for wall in walls:
            wall.create_wall()
