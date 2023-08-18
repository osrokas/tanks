from tkinter import *
from player import Player
from enemy import Enemy
import time
from walls import Wall
from collisions import Collision
from PIL import Image, ImageTk
from renderer import CharRenderer
from ammo import Bullet


class Screen(object):
    # Init Tk class

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

    def running_game(self):
        colision_detector = Collision()
        wall1 = Wall(self.canvas, x1=40, y1=60, x2=450, y2=200)
        enemy1 = Enemy(
            self.canvas,
            x=200,
            y=300,
            max_x=self.game_box_width,
            max_y=self.game_box_height,
        )

        enemy2 = Enemy(
            self.canvas,
            x=200,
            y=300,
            max_x=self.game_box_width,
            max_y=self.game_box_height,
        )

        player = Player(
            x_center=60,
            y_center=60,
            x_max=int(self.game_box_width),
            y_max=int(self.game_box_height),
            player_height=40,
            player_width=40,
            canvas=self.canvas,
            img_path=r"C:\dev\python_game\asssets\images.jpg",
        )

        collision = None
        # Running game loop
        while True:
            player.shotting = False
            wall = wall1.create_wall()
            player.return_value(gui=self.gui)
            e1 = enemy1.create_player()
            e2 = enemy2.create_player()
            player1 = player.create_player()

            self.gui.update()

            try:
                self.canvas.delete(shot)
            except UnboundLocalError:
                pass

            if player.shotting == True:
                bullet = Bullet(
                    inital_x=player.x_coord,
                    inital_y=player.y_coord,
                    canvas=self.canvas,
                    direction=player.angle,
                )
            try:
                if collision == "Collision":
                    del bullet
                    collision = None
                elif collision == None:
                    shot = bullet.create_bullet(add_value=6)
                    colision_return = colision_detector.collision(
                        self.canvas, shot, wall
                    )
                    collision = colision_return
            except UnboundLocalError:
                pass

            self.canvas.delete(e1)
            self.canvas.delete(e2)
            self.canvas.delete(player1)
            self.canvas.delete(wall)
            fps_value = 1 / 60
            time.sleep(fps_value)
