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
        x_detection = true; 
    }
    else {
        x_detection = false;
    }
};

void Collision::detect_y() {
    if(
       ob1.bottom <= ob2.top && ob1.top >= ob2.top || 
       ob1.bottom <= ob2.bottom && ob1.top >= ob2.bottom
    ) {
        y_detection = true; 
    }
    else {
        y_detection = false;
    };
};

void Collision::detect_xy() {
    detect_x();
    detect_y();
    if (x_detection == true && y_detection == true) {
        xy_detection = true;
    }
    else {
        xy_detection = false;
    }
}

void Collision::detect_side() {
    if(xy_detection == true){
        // TODO. FIX THIS IMPLEMENTATION. SOMETHING NOT RIGHT
        // Top bottom detection
        
        if(ob1.bottom <= ob2.top && ob1.top >= ob2.top){
            collision1.bottom == true;
            collision2.top == true;
        }
        else{
            collision1.bottom == false;
            collision2.top == false;
        };

        if( ob1.bottom <= ob2.bottom && ob1.top >= ob2.bottom) {
            collision1.top == true;
            collision2.bottom == true;
        }
        else{
            collision1.bottom == false;
            collision2.bottom == false;
        };

        if(ob1.top >= ob2.bottom) {
            collision1.top == true;
            collision2.bottom == true;
        }
        else{
            collision1.top == false;
            collision2.bottom == false;
        };

        // Left right
        if( ob1.left <= ob2.left) {
            collision1.left == true;
            collision2.left == true;
        }
        else{
            collision1.left == false;
            collision2.left == false;
        };
        if(ob1.right >= ob2.left) {
            collision1.right == true;
            collision2.left == true;
        }
        else{
            collision1.right == false;
            collision2.left == false;
        };
        if(ob1.left <= ob2.right) {
            collision1.left == true;
            collision2.right == true;
        }
        else{
            collision1.left == false;
            collision2.right == false;
        };
        if(ob1.right >= ob2.right) {
            collision1.right == true;
            collision2.right == true;
        }
        else{
            collision1.right == false;
            collision2.right == false;
        };
        
    }
}