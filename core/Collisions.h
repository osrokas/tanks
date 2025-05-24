#include "Models.h"

class Collision {
    BaseModel &ob1;
    BaseModel &ob2;
    public:
        Collision(BaseModel &object1, BaseModel &object2);
        void detect();
}
;