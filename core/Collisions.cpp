#include "Collisions.h"
#include "Models.h"
#include <iomanip>

Collision::Collision(BaseModel &object1, BaseModel &object2):
    ob1(object1), ob2(object2) {};

bool Collision::nearObject(float distanceThreshold) {
    float distanceX = ob1.init_x - ob2.init_x;
    float distanceY = ob1.init_y - ob2.init_y;

    float distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));

    if (distance <= distanceThreshold) {
        return true;
    }
    else {
        return false;
    }
}