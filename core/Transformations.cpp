#include "Transformations.h"

Transformation::Transformation(unsigned shaderID) : shaderProgramID(shaderID){};

void Transformation::move(float angle, float x, float y) {
  glm::mat4 transform = glm::mat4(1.0f);
  
  transform = glm::translate(transform, glm::vec3(x, y, 0.0f));
  transform = glm::rotate(transform, glm::radians(angle),
                          glm::normalize(glm::vec3(0.0f, 0.0f, 1.0f)));

  transformLoc = glGetUniformLocation(shaderProgramID, "transform");
  glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
};