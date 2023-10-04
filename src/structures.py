from tkinter import Canvas
from renderer import CharRenderer


class Wall(object):
    def __init__(
        self, canvas: Canvas, x: int, y: int, width: int, height: int, img_path: str
    ) -> None:
        self.canvas = canvas
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.img_path = img_path
        self.angle = 0
        self.render = CharRenderer(
            canvas=self.canvas,
            img_path=img_path,
            width=width,
            height=height,
        )

    def create_wall(self):
        wall = self.canvas.create_rectangle(
            self.x - self.width / 2,
            self.y - self.height / 2,
            self.x + self.width / 2,
            self.y + self.height / 2,
            tags="wall",
        )

        self.renderer = self.render.load_image(
            x_center=self.x, y_center=self.y, rotation=self.angle
        )

        return wall

    @property
    def left_x(self):
        coord = self.x - self.width / 2
        return coord

    @property
    def right_x(self):
        coord = self.x + self.width / 2
        return coord

    @property
    def top_y(self):
        coord = self.y - self.height / 2
        return coord

    @property
    def down_y(self):
        coord = self.y + self.height / 2
        return coord
