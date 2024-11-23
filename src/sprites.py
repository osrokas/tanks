class Sprites:

    def __init__(self, width: int, height: int, init_pos_x: int, init_pos_y: int, init_angle: float, sprite_name=''):
        self.width = width
        self.height = height
        self.x = init_pos_x
        self.y = init_pos_y
        self.angle = init_angle,
        self.sprite_name = sprite_name