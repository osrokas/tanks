#include "Transformations.h"

Transformation::Transformation(unsigned shaderID) : shaderProgramID(shaderID){};

void Transformation::move(float angle, float x, float y, Extent extent) {
  glm::mat4 transform = glm::mat4(1.0f);

  if (x>extent.maxX) {
    x = extent.maxX;
  }
  if (x<extent.minX) {
    x = extent.minX;
  }

  if (y>extent.maxY) {
    y = extent.maxY;
  }

  if (y< extent.minY) {
    y = extent.minY;
  }
  
  transform = glm::translate(transform, glm::vec3(x, y, 0.0f));
  transform = glm::rotate(transform, glm::radians(angle),
                          glm::normalize(glm::vec3(0.0f, 0.0f, 1.0f)));

  transformLoc = glGetUniformLocation(shaderProgramID, "transform");
  glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
};