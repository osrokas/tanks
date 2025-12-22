#include "Models.h"

// struct Detection {
//     bool top = false;
//     bool bottom = false;
//     bool left = false;
//     bool right = false;

// };

// class Collision {
//     BaseModel &ob1;
//     BaseModel &ob2;

//     public:
//         Detection collision1;
//         Detection collision2;
//         bool xy_detection;
//         bool x_detection;
//         bool y_detection;
//         Collision(BaseModel &object1, BaseModel &object2);
//         void detect_x();
//         void detect_y();
//         void detect_xy();
//         void detect_side();
// };


class Collision {
    BaseModel &ob1;
    BaseModel &ob2;

    public:
        Collision(BaseModel &object1, BaseModel &object2);
        bool nearObject(float distanceThreshold = 0.3f);
};