#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Rotate {
    public:
        unsigned int shaderProgramID;
        Rotate(unsigned int shaderID);
        void rotate_z(float angle);
      private:
        unsigned int transformLoc;

};