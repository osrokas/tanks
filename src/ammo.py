from tkinter import Canvas


class Bullet(object):
    def __init__(
        self, inital_x: int, inital_y: int, canvas: Canvas, direction: int
    ) -> None:
        self.inital_x = inital_x
        self.inital_y = inital_y
        self.canvas = canvas
        self.direction = direction

    def create_bullet(self, add_value: int):
        if self.direction == 0:
            self.inital_y = self.inital_y - add_value
        elif self.direction == 90:
            self.inital_x = self.inital_x - add_value
        elif self.direction == 180:
            self.inital_y = self.inital_y + add_value
        elif self.direction == 270:
            self.inital_x = self.inital_x + add_value
        bullet = self.canvas.create_rectangle(
            self.inital_x,
            self.inital_y,
            self.inital_x + 10,
            self.inital_y + 10,
            outline="red",
            fill="yellow",
        )
        self.bullet = bullet
        return bullet
