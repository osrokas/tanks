from game_window import GameWindow
from game_objects import GameObject


class DeleteOutOfBound(object):
    @staticmethod
    def delete_object(game_window: GameWindow, game_objects: list[GameObject]):
        for game_object in game_objects:
            if (
                game_object.x > game_window.game_box_width
                or game_object.y > game_window.game_box_height
                or game_object.x < 0
                or game_object.y < 0
            ):
                game_objects.remove(game_object)
                del game_object
