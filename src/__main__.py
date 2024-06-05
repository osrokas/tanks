from game_window import GameWindow
from game_objects import Player, Bullet, MovingBullet
import time
from collisions import Collision
from handlers import DeleteOutOfBound
from bullets_bar import BulletsBar
from gameplay import wall_generator, create_enemies
from PIL import ImageTk, Image as ii
from tkinter import *

# import multiprocessing

CPU_COUNT = 4

import os

current_path = os.getcwd()
background_img = os.path.join(current_path, "asssets", "background.png")
player_img = os.path.join(current_path, "asssets", "tank.png")
enemy_img = os.path.join(current_path, "asssets", "enemy.png")
bullets_img = os.path.join(current_path, "asssets", "bullet.png")
# pool = multiprocessing.Pool(CPU_COUNT)

# Create game window
window = GameWindow(
    game_name="Tanks",
    screen_size=(1200, 700),
    background_color="grey",
    game_box_width=1000,
    game_box_height=600,
)
python_image = ii.open(background_img)
python_image = python_image.resize((2400, 1200), resample=ii.Resampling.NEAREST)
ph = ImageTk.PhotoImage(python_image)
# Create gameplay window
canvas = window.create_game_window()
bullet_canvas = window.bullets_window()

walls = wall_generator(canvas)
enemies = create_enemies(canvas=canvas, window=window)

health_canvas_list = []
for ene in enemies:
    health_canvas = window.health_bar()
    health_canvas_list.append(health_canvas)
# Create player

player = Player(
    x=60,
    y=60,
    player_height=40,
    player_width=40,
    canvas=canvas,
    game_box=window,
    img_path=player_img,
    heatlh=100,
)
# Initialize collisions
colision_detector = Collision()

# Create list for iteration processing
# Player bullets
bullets = []
bullets_canvas = []
max_bullets_len = 5
# Enemies bullets
enemy_bullets = []
enemy_bullets_canvas = []
max_enemy_bullets_len = 10
# Set collision value to false
collision = None


initial_time = []
while True:
    canvas.create_image((0, 0), image=ph)
    canvas.pack(fill=BOTH)
    initial_time.append(time.time())
    try:
        _time = initial_time[-1] - initial_time[0]
        if _time >= 3:
            initial_time = []
        else:
            pass
    except:
        pass
    # Create game objects
    _walls = []
    for _w in walls:
        _append_w = _w.create_wall()
        _walls.append(_append_w)
    # wall = wall1.create_wall()
    player_object = player.create_object()
    # Set shooting to False
    player.shotting = False
    # Return keyboard input values
    player.return_value(window.gui)
    # Update game window after iteration
    canvas_en = []
    window.gui.update()
    for en in enemies:
        if en.heatlh < 0:
            enemies.remove(en)
    for en in enemies:
        canvas_en.append(en.create_object())
        _en_fire_state = en.fire_state()
        en.fire(_en_fire_state)
        try:
            for _bul in bullets:
                colision_detector.hit_player(bullet=_bul, player=en)
                if _bul.hit == True:
                    bullets.remove(_bul)
        except IndexError:
            pass
        if en.shoting == True and len(enemy_bullets) < max_enemy_bullets_len:
            en_bullet = Bullet(
                x=en.x,
                y=en.y,
                canvas=canvas,
                direction=en.angle,
                game_box=window,
                bullet_width=20,
                bullet_height=30,
                img_path=bullets_img,
            )
            enemy_bullets.append(en_bullet)

        try:
            # pass
            # if collision == "Collision":
            #     del bullet
            #     collision = None
            # elif collision == None:
            # Iterate through bullets list and create bullet rectangle
            # in game window with incremnt value of coordinates with add_value parameter
            _en_bullets = MovingBullet.create_object(enemy_bullets, 6)
            # Append bullets rectangles to list
            enemy_bullets_canvas.append(_en_bullets)

            Collision.destroy_wall(bullets=enemy_bullets, walls=walls)
            # print(col)
            try:
                # Iterate through list and delete last iteration rectangles
                MovingBullet.delete_object(
                    enemy_bullets_canvas[0:-1], canvas=canvas, window=window
                )
            except Exception as e:
                pass
        except Exception as e:
            print(e)
    collisions = []
    for _ww in walls:
        coll_down = colision_detector.player_collisions_down(player, _ww)
        coll_left = colision_detector.player_collisions_left(player, _ww)
        coll_right = colision_detector.player_collisions_right(player, _ww)
        coll_up = colision_detector.player_collisions_up(player, _ww)
        collisions.append(coll_down)
        collisions.append(coll_up)
        collisions.append(coll_left)
        collisions.append(coll_right)
    colision_detector.check_collsion(collsions=collisions, player=player)
    # When keyboard pressed 'e' set shoting to True
    # and bullet object created
    if player.shotting == True and len(bullets) < max_bullets_len:
        bullet = Bullet(
            x=player.x,
            y=player.y,
            canvas=canvas,
            direction=player.angle,
            game_box=window,
            bullet_width=20,
            bullet_height=30,
            img_path=bullets_img,
        )
        # Append bullet object to bullets list
        bullets.append(bullet)
    try:
        _bullets = MovingBullet.create_object(bullets, 6)
        # Append bullets rectangles to list
        bullets_canvas.append(_bullets)

        Collision.destroy_wall(bullets=bullets, walls=walls)
        window.gui.update()
        # print(col)
        try:
            # Iterate through list and delete last iteration rectangles
            MovingBullet.delete_object(
                bullets_canvas[0:-1], canvas=canvas, window=window
            )
        except Exception as e:
            pass
        # colision_return = colision_detector.collision(canvas, shot, wall)
        # collision = colision_return
    except Exception as e:
        print(e)
    bullets_count = BulletsBar(bullets=bullets, max_bullets=max_bullets_len)
    bullets_text = f"Shots : {bullets_count.available_bullets}"
    window.bullet_text_update(txt=str(bullets_text))
    # i = 0
    # for _h in health_canvas_list:
    #     window.health_bar_text_update(txt=str(i))
    # # for __en in enemies:
    # GameWindow.health_bar_text_update(canvas=_h, gui=window.gui, enemies=enemies)

    if len(_walls) > 0:
        canvas.delete(_walls.pop())
    window.gui.update()
    canvas.delete(player_object)
    window.gui.update()

    # pool.map(canvas.delete, canvas_en)
    # pool.close()
    # pool.join()
    for _en in canvas_en:
        canvas.delete(_en)
    DeleteOutOfBound.delete_object(game_window=window, game_objects=bullets)
    DeleteOutOfBound.delete_object(game_window=window, game_objects=enemy_bullets)

    # Set fps
    fps_value = 1 / 120
    time.sleep(fps_value)
