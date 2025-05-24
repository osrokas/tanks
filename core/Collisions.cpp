#include "Collisions.h"
#include "Models.h"
#include <iomanip>

Collision::Collision(BaseModel &object1, BaseModel &object2):
    ob1(object1), ob2(object2) {};

void Collision::detect() {
    

    if(
        (ob1.init_x - ob1.width) == (ob2.init_x - ob2.width) || 
        (ob1.init_x - ob1.width) == (ob2.init_x + ob2.width) || 
        (ob1.init_x + ob1.width) == (ob2.init_x - ob2.width) ||
        (ob1.init_x + ob1.width) == (ob2.init_x + ob2.width)
    ) {
        std::cout << "COLLISION DETECTED" << std::endl;
    };
};