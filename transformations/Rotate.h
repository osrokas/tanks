#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Rotate {
    public:
        unsigned int shaderProgramID;
        Rotate(unsigned int shaderID);
        void rotate_z();
    private:
        unsigned int transformLoc;

};