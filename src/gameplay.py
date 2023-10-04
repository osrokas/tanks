from structures import Wall
from game_objects import Enemy


def wall_generator(canvas):
    walls_g = [
        Wall(
            canvas,
            x=100,
            y=200,
            width=160,
            height=20,
            img_path=r"C:\dev\python_game\asssets\walls.png",
        ),
        Wall(
            canvas,
            x=20,
            y=10,
            width=160,
            height=20,
            img_path=r"C:\dev\python_game\asssets\walls.png",
        ),
        Wall(
            canvas,
            x=30,
            y=40,
            width=160,
            height=20,
            img_path=r"C:\dev\python_game\asssets\walls.png",
        ),
        Wall(
            canvas,
            x=100,
            y=200,
            width=160,
            height=20,
            img_path=r"C:\dev\python_game\asssets\walls.png",
        ),
        Wall(
            canvas,
            x=899,
            y=100,
            width=20,
            height=160,
            img_path=r"C:\dev\python_game\asssets\walls.png",
        ),
        Wall(
            canvas,
            x=-9999,
            y=-9999,
            width=20,
            height=160,
            img_path=r"C:\dev\python_game\asssets\walls.png",
        ),
    ]

    return walls_g


def create_enemies(canvas, window):
    # Create enemies
    enemy1 = Enemy(
        canvas,
        x=200,
        y=300,
        game_box=window,
        player_height=40,
        player_width=40,
        img_path=r"C:\dev\python_game\asssets\enemy_tank.png",
        heatlh=100,
    )
    enemy2 = Enemy(
        canvas=canvas,
        x=200,
        y=300,
        game_box=window,
        player_height=40,
        player_width=40,
        img_path=r"C:\dev\python_game\asssets\enemy_tank.png",
        heatlh=100,
    )
    enemy2 = Enemy(
        canvas=canvas,
        x=200,
        y=300,
        game_box=window,
        player_height=40,
        player_width=40,
        img_path=r"C:\dev\python_game\asssets\enemy_tank.png",
        heatlh=100,
    )
    enemy2 = Enemy(
        canvas=canvas,
        x=200,
        y=300,
        game_box=window,
        player_height=40,
        player_width=40,
        img_path=r"C:\dev\python_game\asssets\enemy_tank.png",
        heatlh=100,
    )
    enemy3 = Enemy(
        canvas=canvas,
        x=-2000000000,
        y=-2000000000,
        game_box=window,
        player_height=40,
        player_width=40,
        img_path=r"C:\dev\python_game\asssets\enemy_tank.png",
        heatlh=100,
    )

    enemies = [enemy1, enemy2, enemy3]

    return enemies
