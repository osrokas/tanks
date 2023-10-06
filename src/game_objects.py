from tkinter import Canvas, Tk
from abc import ABC, abstractmethod
import random
from renderer import CharRenderer


class GameObject(ABC):
    """
    Abstract game object class
    """

    @abstractmethod
    def __init__(self, canvas: Canvas, x: int, y: int, game_box) -> None:
        """
        :param canvas: gameplay window
        :param x: x axis coordinate where object are created
        :param y: y axis coorndinate where object are created
        :param game_box: game window
        """
        self.canvas = canvas
        self.x = x
        self.y = y
        self.max_x = game_box.game_box_width
        self.max_y = game_box.game_box_height
        self.game_box = game_box


class Bullet(GameObject):
    """
    Class define player bullet class
    """

    def __init__(
        self,
        canvas: Canvas,
        x: int,
        y: int,
        game_box,
        direction: int,
        img_path: str,
        bullet_width: int,
        bullet_height: int,
    ) -> None:
        """
        :param canvas: gameplay window
        :param x: x axis coordinate where object are created
        :param y: y axis coorndinate where object are created
        :param game_box: game window
        :param direction: define in that direction bullet should move
        """
        super().__init__(canvas, x, y, game_box)
        self.direction = direction
        self.hit = False
        self.bullet_width = bullet_width
        self.bullet_height = bullet_height
        self.render = CharRenderer(
            canvas=self.canvas,
            img_path=img_path,
            width=bullet_width,
            height=bullet_height,
        )


class MovingBullet(object):
    """
    Class defines bullet movement across gameplay window
    """

    @staticmethod
    def create_object(bullets: list[Bullet], add_value: int):
        """
        The method create objects on gameplay window

        :param bullets: bullet objects
        :param add_value: increment value on x or y axis of object
        """
        bullets_obj = []
        for bullet_obj in bullets:
            if bullet_obj.direction == 0:
                bullet_obj.y = bullet_obj.y - add_value
            elif bullet_obj.direction == 90:
                bullet_obj.x = bullet_obj.x - add_value
            elif bullet_obj.direction == 180:
                bullet_obj.y = bullet_obj.y + add_value
            elif bullet_obj.direction == 270:
                bullet_obj.x = bullet_obj.x + add_value
            bullet = bullet_obj.canvas.create_rectangle(
                bullet_obj.x - bullet_obj.bullet_width / 2,
                bullet_obj.y - bullet_obj.bullet_height / 2,
                bullet_obj.x + bullet_obj.bullet_width / 2,
                bullet_obj.y + bullet_obj.bullet_height / 2,
            )
            bullet_obj.render.load_image(
                bullet_obj.x, bullet_obj.y, rotation=bullet_obj.direction
            )
            bullets_obj.append(bullet)

        if len(bullets_obj) == 0:
            pass
        else:
            return bullets_obj

    @staticmethod
    def delete_object(bullets: list[list], canvas: Canvas, window):
        """
        The method deletes list of objects on gameplay window

        :param bullets: list of bullets objects
        :param canvas: gameplay window
        """
        for bullet in bullets:
            if bullet == None:
                pass
            else:
                for _b in bullet:
                    canvas.delete(_b)

        window.gui.update()


class Enemy(GameObject):
    """
    Define class of enemy objects
    """

    def __init__(
        self,
        canvas: Canvas,
        x: int,
        y: int,
        game_box,
        img_path: str,
        player_width: int,
        player_height: int,
        heatlh: int,
    ) -> None:
        super().__init__(canvas, x, y, game_box)
        self.render = CharRenderer(
            canvas=self.canvas,
            img_path=img_path,
            width=player_width,
            height=player_height,
        )
        self.player_width = player_width
        self.player_height = player_height
        self.angle = 0
        self.list = []
        self.shoting = False
        self.heatlh = heatlh

    def create_object(self):
        """
        The method creates object on gameplay window
        """
        enemy = self.canvas.create_rectangle(
            self.x, self.y, self.x + 10, self.y + 10, outline="white", fill="red"
        )
        self._movement()
        self.renderer = self.render.load_image(
            x_center=self.x, y_center=self.y, rotation=self.angle
        )
        return enemy

    def _movement(self):
        """
        The method define enemy object movement on gameplay window
        """
        if len(self.list) == 0:
            self.state = self.__movement_state()
            self.list.append(self.state)
        elif len(self.list) > 0 and len(self.list) < 100:
            self.state = self.list[0]
            self.list.append(self.state)
        else:
            self.list = []
            self.state = self.__movement_state()

        if self.state == "UP":
            if self.y > 0:
                self.y = self.y - 2
            else:
                self.y = self.y

        elif self.state == "DOWN":
            if self.y < self.max_y:
                self.y = self.y + 2
            else:
                self.y = self.y

        elif self.state == "LEFT":
            if self.x > 0:
                self.x = self.x - 2
            else:
                self.x = self.x

        elif self.state == "RIGHT":
            if self.x < self.max_x:
                self.x = self.x + 2
            else:
                self.x = self.x

    def __movement_state(self):
        """
        The method define object movement direction on current state
        """
        random_state = random.randint(0, 3)
        if random_state == 0:
            state = "UP"
            self.angle = 0

        elif random_state == 1:
            state = "DOWN"
            self.angle = 180
        elif random_state == 2:
            state = "LEFT"
            self.angle = 90

        elif random_state == 3:
            state = "RIGHT"
            self.angle = 270

        return state

    def fire(self, fire_state: bool):
        if fire_state == True:
            self.shoting = True
        elif fire_state == False:
            self.shoting = False

    @staticmethod
    def fire_state():
        if random.random() < 0.01:
            return True
        else:
            return False

    @property
    def left_x(self):
        x = self.x - self.player_width / 2
        return x

    @property
    def right_x(self):
        x = self.x + self.player_width / 2
        return x

    @property
    def up_y(self):
        y = self.y + self.player_height / 2
        return y

    @property
    def down_y(self):
        y = self.y - self.player_height / 2
        return y


class Player(GameObject):
    def __init__(
        self,
        canvas: Canvas,
        x: int,
        y: int,
        game_box: int,
        player_width: int,
        player_height: int,
        img_path: str,
        heatlh: int,
        speed: int = 4,
    ) -> None:
        super().__init__(canvas, x, y, game_box)
        self.angle = 0
        self.last_rotation = []
        self.bullets = []
        self.shotting = False
        self.player_width = player_width
        self.player_height = player_height
        self.game_box = game_box
        self.heatlh = heatlh
        self.render = CharRenderer(
            canvas=self.canvas,
            img_path=img_path,
            width=player_width,
            height=player_height,
        )
        self.speed = speed
        self.speed_w = speed
        self.speed_s = speed
        self.speed_d = speed
        self.speed_a = speed

    def create_object(self):
        player = self.canvas.create_rectangle(
            self.x - self.player_width / 2,
            self.y - self.player_height / 2,
            self.x + self.player_width / 2,
            self.y + self.player_height / 2,
        )
        self.shotting = False
        self.renderer = self.render.load_image(
            x_center=self.x, y_center=self.y, rotation=self.angle
        )
        return player

    def _keyboard_input_events(self, event):
        self.key = event.__dict__["char"]
        if self.key == "w":
            if self.y > 0:
                self.y = self.y - self.speed_w
            else:
                self.y = self.y

            self.angle = 0

        if self.key == "s":
            if self.y < self.max_y:
                self.y = self.y + self.speed_s
            else:
                self.y = self.max_y

            self.angle = 180

        if self.key == "a":
            if self.x > 0:
                self.x = self.x - self.speed_a
            else:
                self.x = self.x

            self.angle = 90

        if self.key == "d":
            if self.x < self.max_x:
                self.x = self.x + self.speed_d
            else:
                self.x = self.max_x

            self.angle = 270

        if self.key == "e":
            self.shotting = True

    def return_value(self, gui: Tk):
        gui.bind(f"<Key>", self._keyboard_input_events, add=False)

    @property
    def left_x(self):
        x = self.x - self.player_width / 2
        return x

    @property
    def right_x(self):
        x = self.x + self.player_width / 2
        return x

    @property
    def up_y(self):
        y = self.y - self.player_height / 2
        return y

    @property
    def down_y(self):
        y = self.y + self.player_height / 2
        return y
