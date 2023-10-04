from tkinter import *
from game_objects import Enemy


class GameWindow(object):
    def __init__(
        self,
        game_name: str,
        screen_size: tuple,
        background_color: str,
        game_box_width: int,
        game_box_height: int,
    ) -> None:
        self.game_name = game_name
        self.screen_size = screen_size
        self.background_color = background_color

        self.game_box_width = game_box_width
        self.game_box_height = game_box_height

        self.gui = Tk()
        self.gui.configure(background=background_color)
        self.gui.title(game_name)
        self.gui.geometry(f"{screen_size[0]}x{screen_size[1]}")

    def create_game_window(self):
        self.padx = 20
        self.pady = 20
        self.canvas = Canvas(
            self.gui, bg="black", width=self.game_box_width, height=self.game_box_height
        )
        self.canvas.pack(padx=self.padx, pady=self.pady)
        canvas = self.canvas

        return canvas

    def bullets_window(self):
        self.canvas_txt = Canvas(self.gui, bg="black", width=200, height=200)
        self.canvas_txt.pack(padx=0, pady=0)
        self.bullet_text = self.canvas_txt.create_text(
            50,
            20,
            fill="white",
            font=("Helvetica 15 bold"),
        )
        canvas = self.canvas_txt

        return canvas

    def bullet_text_update(self, txt: str):
        self.canvas_txt.itemconfigure(self.bullet_text, text=txt)
        self.gui.update()

    def health_bar(self):
        self.canvas_txt = Canvas(self.gui, bg="green", width=200, height=50)
        self.canvas_txt.pack(side="left")
        self.health_text = self.canvas_txt.create_text(
            50,
            20,
            fill="red",
            font=("Helvetica 15 bold"),
        )
        canvas = self.canvas_txt

        return canvas

    def health_bar_text_update(self, txt: str):
        self.canvas.itemconfigure(self.health_text, text=txt)
