from tkinter import Canvas
from structures import Wall

# from ammo import Bullet
from typing import Union
from game_objects import Player, Enemy, Bullet, GameObject


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

    @staticmethod
    def player_collisions_down(player: Player, collision_obj: GameObject):
        if collision_obj.left_x < player.x < collision_obj.right_x and (
            collision_obj.down_y == player.up_y
            or collision_obj.down_y == player.up_y + 1
            or collision_obj.down_y == player.up_y + 2
            or collision_obj.down_y == player.up_y + 3
            or collision_obj.down_y == player.up_y + 4
        ):
            colision = "up"
            return colision

    @staticmethod
    def player_collisions_up(player: Player, collision_obj: GameObject):
        if collision_obj.left_x < player.x < collision_obj.right_x and (
            collision_obj.top_y == player.down_y
            or collision_obj.top_y == player.down_y - 1
            or collision_obj.top_y == player.down_y - 2
            or collision_obj.top_y == player.down_y - 3
            or collision_obj.top_y == player.down_y - 4
        ):
            colision = "down"
            return colision

    @staticmethod
    def player_collisions_left(player: Player, collision_obj: GameObject):
        if collision_obj.top_y < player.y < collision_obj.down_y and (
            collision_obj.right_x == player.left_x
            or collision_obj.right_x == player.left_x - 1
            or collision_obj.right_x == player.left_x - 2
            or collision_obj.right_x == player.left_x - 3
            or collision_obj.right_x == player.left_x - 4
        ):
            colision = "left"
            return colision

    @staticmethod
    def player_collisions_right(player: Player, collision_obj: GameObject):
        if collision_obj.top_y < player.y < collision_obj.down_y and (
            collision_obj.left_x == player.right_x
            or collision_obj.left_x == player.right_x + 1
            or collision_obj.left_x == player.right_x + 2
            or collision_obj.left_x == player.right_x + 3
            or collision_obj.left_x == player.right_x + 4
        ):
            colision = "right"
            return colision

    @staticmethod
    def check_collsion(collsions, player: Player):
        if "down" in collsions:
            player.speed_s = 0
        else:
            player.speed_s = 4
        if "up" in collsions:
            player.speed_w = 0
        else:
            player.speed_w = 4
        if "left" in collsions:
            player.speed_a = 0
        else:
            player.speed_a = 4

        if "right" in collsions:
            player.speed_d = 0
        else:
            player.speed_d = 4
