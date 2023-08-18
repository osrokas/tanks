from tkinter import Canvas


class Collision(object):
    def __init__(self) -> None:
        pass

    @classmethod
    def collision(
        cls,
        game_window: Canvas,
        firs_object: Canvas,
        second_object: Canvas,
    ):
        coords_first = game_window.coords(firs_object)
        coords_second = game_window.coords(second_object)
        try:
            if coords_second[0] < coords_first[0] < coords_second[2]:
                if coords_second[1] < coords_first[1] < coords_second[3]:
                    collision = "Collision"
            else:
                collision = None
            return collision

        except UnboundLocalError or IndexError:
            collision = None
            return collision
