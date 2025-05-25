#include "Models.h"

class Collision {
    BaseModel &ob1;
    BaseModel &ob2;

    public:
        bool x_dectection;
        bool y_dectection;
        Collision(BaseModel &object1, BaseModel &object2);
        void detect_x();
        void detect_y();
        void detect_xy();
};