from tkinter import Canvas


class Wall(object):
    def __init__(self, canvas: Canvas, x1: int, y1: int, x2: int, y2: int) -> None:
        self.canvas = canvas
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2

    def create_wall(self):
        wall = self.canvas.create_rectangle(
            self.x1, self.y1, self.x2, self.y2, outline="white", fill=""
        )

        return wall
