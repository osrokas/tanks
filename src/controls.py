from tkinter import *


class KeyBoardEvents:
    def __init__(self, gui: Tk) -> None:
        self.gui = gui

    def _key_event(self, event):
        self.key = event.__dict__["char"]

    def bind_key(self, bind):
        self.gui.bind(f"<{bind}>", self._key_event, add=False)
