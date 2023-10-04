from tkinter import *


class Bullet(object):
    def __init__(
        self, inital_x: int, inital_y: int, canvas: Canvas, direction: int
    ) -> None:
        self.inital_x = inital_x
        self.inital_y = inital_y
        self.canvas = canvas
        self.direction = direction

        self.canvas.create_rectangle(
            self.inital_x,
            self.inital_y,
            self.inital_x + 10,
            self.inital_y + 10,
            outline="red",
            fill="yellow",
        )


class Bullets(object):
    def __init__(self, bullets: list[Bullet]) -> None:
        self.bullets = bullets

    def move_bullets(self):
        for bullet in self.bullets:
            bullet.create_object(add_value=6)
