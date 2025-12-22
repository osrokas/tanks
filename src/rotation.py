import keyboard
import math
import sys

import pygame
from pygame.locals import *


class BoundingBox:
    def __init__(self, width, height):
        self.init_x = 0
        self.init_y = 0
        self.width = width
        self.height = height

    @property
    def bottom(self):
        return self.init_y - (self.height / 2)

    @property
    def top(self):
        return self.init_y + (self.height / 2)

    @property
    def right(self):
        return self.init_x + (self.width / 2)

    @property
    def left(self):
        return self.init_x - (self.width / 2)


class Rotation:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def rotate(self, angle):

        x_ = self.x * math.cos(angle) - self.y * math.sin(angle)
        y_ = self.x * math.sin(angle) + self.y * math.cos(angle)

        return x_, y_


class BBoxRotations:

    def __init__(self, sprite: BoundingBox) -> None:
        self.sprite = sprite
        self.rotations = [
            Rotation(self.sprite.right, self.sprite.bottom),
            Rotation(self.sprite.left, self.sprite.bottom),
            Rotation(self.sprite.left, self.sprite.top),
            Rotation(self.sprite.right, self.sprite.top),
        ]

    def apply_rotation(self, angle):
        rotations_vector = []
        for each in self.rotations:
            x, y = each.rotate(angle=angle)
            rotations_vector.append((x, y))

        return rotations_vector


class Sprite:
    def __init__(self, x, y, width, height):
        self.x = x
        self.y = y
        self.bbox = BoundingBox(width=width, height=height)
        self.rotations = BBoxRotations(self.bbox)
        self.angle = 0

    def _rotate(self):
        radians = math.radians(self.angle)
        vec = self.rotations.apply_rotation(angle=radians)
        return vec

    def transform_coords(self):

        (x1, y1), (x2, y2), (x3, y3), (x4, y4) = self._rotate()

        return (
            (x1 + self.x, y1 + self.y),
            (x2 + self.x, y2 + self.y),
            (x3 + self.x, y3 + self.y),
            (x4 + self.x, y4 + self.y),
        )


class Player(Sprite):

    def __init__(self, x, y, width, height):
        super().__init__(x, y, width, height)

    def move(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_w]:
            self.y -= 0.1
            self.angle = 270
        elif keys[pygame.K_s]:
            self.y += 0.1
            self.angle = 90
        elif keys[pygame.K_a]:
            self.x -= 0.1
            self.angle = 180
        elif keys[pygame.K_d]:
            self.x += 0.1
            self.angle = 0
        else:
            pass

    def draw(self):
        self.move()
        (x1, y1), (x2, y2), (x3, y3), (x4, y4) = self.transform_coords()
        pygame.draw.circle(screen, "red", [int(x1), int(y1)], 2)
        pygame.draw.circle(screen, "green", [int(x2), int(y2)], 2)
        pygame.draw.circle(screen, "blue", [int(x3), int(y3)], 2)
        pygame.draw.circle(screen, "yellow", [int(x4), int(y4)], 2)


if __name__ == "__main__":

    pygame.init()
    screen = pygame.display.set_mode((800, 600))  # width=800, height=600
    pygame.display.set_caption("My Game")

    rect = Player(x=0, y=0, width=0.1, height=0.2)

    FPS = pygame.time.Clock()

    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
        screen.fill((0, 0, 0))

        rect.draw()
        print(rect.x, rect.y, rect.angle)
        pygame.display.update()
        FPS.tick(60)
