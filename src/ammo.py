from tkinter import *
from renderer import CharRenderer


class Bullet(object):
    def __init__(
        self,
        inital_x: int,
        inital_y: int,
        canvas: Canvas,
        direction: int,
        img_path: str,
        bullet_width: int,
        bullet_height: int,
    ) -> None:
        self.inital_x = inital_x
        self.inital_y = inital_y
        self.canvas = canvas
        self.direction = direction
        self.bullet_width = bullet_width
        self.bullet_height = bullet_height
        self.canvas.create_rectangle(
            self.inital_x - self.bullet_width / 2,
            self.inital_y - self.bullet_height / 2,
            self.inital_x + self.bullet_width / 2,
            self.inital_y + self.bullet_height / 2,
            outline="red",
            fill="yellow",
        )

        self.render = CharRenderer(
            canvas=self.canvas,
            img_path=img_path,
            width=bullet_width,
            height=bullet_height,
        )
        self.renderer = self.render.load_image(x_center=self.x, y_center=self.y)


class Bullets(object):
    def __init__(self, bullets: list[Bullet]) -> None:
        self.bullets = bullets

    def move_bullets(self):
        for bullet in self.bullets:
            bullet.create_object(add_value=6)
