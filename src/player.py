from tkinter import *
from renderer import CharRenderer


class Player(object):
    def __init__(
        self,
        x_center: int,
        y_center: int,
        x_max: int,
        y_max: int,
        player_width: int,
        player_height: int,
        canvas: Canvas,
        img_path: str,
    ):
        self.x_coord = x_center
        self.y_coord = y_center
        self.x_max = x_max
        self.y_max = y_max
        self.canvas = canvas
        self.player_width = player_width
        self.player_height = player_height
        self.angle = 0
        self.last_rotation = []
        self.bullets = []
        self.shotting = False
        self.render = CharRenderer(
            canvas=self.canvas,
            img_path=img_path,
            width=player_width,
            height=player_height,
        )

    def create_player(self):
        player = self.canvas.create_rectangle(
            self.x_coord - self.player_width / 2,
            self.y_coord - self.player_height / 2,
            self.x_coord + self.player_width / 2,
            self.y_coord + self.player_height / 2,
            outline="white",
            fill="purple",
        )
        self.shotting = False
        self.renderer = self.render.load_image(
            x_center=self.x_coord, y_center=self.y_coord, rotation=self.angle
        )

        return player

    def _keyboard_input_events(self, event):
        self.key = event.__dict__["char"]
        if self.key == "w":
            if self.y_coord > 0:
                self.y_coord = self.y_coord - 4
            else:
                self.y_coord = self.y_coord

            self.angle = 0

        if self.key == "s":
            if self.y_coord < self.y_max:
                self.y_coord = self.y_coord + 4
            else:
                self.y_coord = self.y_max

            self.angle = 180

        if self.key == "a":
            if self.x_coord > 0:
                self.x_coord = self.x_coord - 4
            else:
                self.x_coord = self.x_coord

            self.angle = 90

        if self.key == "d":
            if self.x_coord < self.x_max:
                self.x_coord = self.x_coord + 4
            else:
                self.x_coord = self.x_max

            self.angle = 270

        if self.key == "e":
            self.shotting = True

    def return_value(self, gui: Tk):
        gui.bind(f"<Key>", self._keyboard_input_events, add=False)
