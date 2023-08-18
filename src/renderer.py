from tkinter import *
from PIL import Image, ImageTk


class CharRenderer(object):
    def __init__(self, canvas: Canvas, img_path: str, width: int, height: int):
        self.canvas = canvas
        self.img_path = img_path
        self.img = Image.open(self.img_path)
        self.img = self.img.resize((width, height), resample=Image.Resampling.NEAREST)
        self.rotations = 0

    def load_image(self, x_center, y_center, rotation: int = 0) -> Image:
        self.img = self.img.rotate(-self.rotations)
        self.img = self.img.rotate(rotation)
        self._img = ImageTk.PhotoImage(self.img)
        img = self.canvas.create_image(
            x_center, y_center, anchor=CENTER, image=self._img
        )
        self.rotations = rotation

        return img
