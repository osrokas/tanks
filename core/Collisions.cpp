#include "Collisions.h"
#include "Models.h"
#include <iomanip>

Collision::Collision(BaseModel &object1, BaseModel &object2):
    ob1(object1), ob2(object2) {};

void Collision::detect_x() {
    if(
       ob1.left <= ob2.left && ob1.right >= ob2.left ||
       ob1.left <= ob2.right && ob1.right >= ob2.right
    ) {
        x_dectection = true; 
    }
    else {
        x_dectection = false;
    }
};

void Collision::detect_y() {
    if(
       ob1.bottom <= ob2.top && ob1.top >= ob2.top || 
       ob1.bottom <= ob2.bottom && ob1.top >= ob2.bottom
    ) {
        y_dectection = true; 
    }
    else {
        y_dectection = false;
    }
};

void Collision::detect_xy() {
    detect_x();
    detect_y();
    if (x_dectection == true && y_dectection == true) {
        std::cout << "COLLISION DETECTED" << std::endl;
    }
    
}