#include "rotate.h"

Rotate::Rotate(unsigned shaderID) :
    shaderProgramID(shaderID) {};

void Rotate::rotate_z(float angle){
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::rotate(transform, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
    transformLoc = glGetUniformLocation(shaderProgramID, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
};