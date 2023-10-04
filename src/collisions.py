from tkinter import Canvas
from structures import Wall

# from ammo import Bullet
from typing import Union
from game_objects import Player, Enemy, Bullet


class Collision(object):
    def __init__(self) -> None:
        pass

    @staticmethod
    def collision(
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

    @staticmethod
    def destroy_wall(bullets: list[Bullet], walls: list[Wall]):
        for _b in bullets:
            for wall in walls:
                try:
                    if (
                        wall.left_x < _b.x < wall.right_x
                        and wall.top_y < _b.y < wall.down_y
                    ):
                        walls.remove(wall)
                        bullets.remove(_b)

                except Exception as e:
                    print(e)

    @staticmethod
    def hit_player(bullet: Bullet, player: Union[Player, Enemy]):
        if (
            player.left_x <= bullet.x <= player.right_x
            and player.down_y <= bullet.y <= player.up_y
        ):
            player.heatlh = player.heatlh - 8
            bullet.hit = True
