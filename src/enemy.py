from tkinter import Canvas
import random


class Enemy(object):
    def __init__(self, canvas: Canvas, x: int, y: int, max_x, max_y) -> None:
        self.canvas = canvas
        self.x = x
        self.y = y
        self.max_x = max_x
        self.max_y = max_y
        self.list = []

    def create_player(self):
        enemy = self.canvas.create_rectangle(
            self.x, self.y, self.x + 10, self.y + 10, outline="white", fill="red"
        )
        self._movement()

        return enemy

    def _movement(self):
        if len(self.list) == 0:
            self.state = self.__movement_state()
            self.list.append(self.state)
        elif len(self.list) > 0 and len(self.list) < 20:
            self.state = self.list[0]
            self.list.append(self.state)
        else:
            self.list = []
            self.state = self.__movement_state()

        if self.state == "UP":
            if self.y > 0:
                self.y = self.y - 4
            else:
                self.y = self.y

        elif self.state == "DOWN":
            if self.y < self.max_y:
                self.y = self.y + 4
            else:
                self.y = self.y

        elif self.state == "LEFT":
            if self.x > 0:
                self.x = self.x - 4
            else:
                self.x = self.x

        elif self.state == "RIGHT":
            if self.x < self.max_x:
                self.x = self.x + 4
            else:
                self.x = self.x

    def __movement_state(self):
        random_state = random.randint(0, 3)
        if random_state == 0:
            state = "UP"

        elif random_state == 1:
            state = "DOWN"

        elif random_state == 2:
            state = "LEFT"

        elif random_state == 3:
            state = "RIGHT"

        return state
