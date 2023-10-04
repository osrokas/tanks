from ammo import Bullet


class BulletsBar(object):
    def __init__(self, bullets: list[Bullet], max_bullets: int) -> None:
        self.bullets = bullets
        self.max_bullets = max_bullets

    @property
    def get_count(self):
        count = len(self.bullets)
        return count

    @property
    def available_bullets(self):
        count = self.max_bullets - self.get_count
        return count
