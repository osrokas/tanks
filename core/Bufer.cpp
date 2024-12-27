#include "Buffer.h"

Buffer::Buffer(Geometry geometry) : 
    geom(geometry)
    {}

void Buffer::loadToBuffer(bool wireframe) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, geom.vertices.size() * sizeof(float), geom.vertices.data(), GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, geom.indecies.size() * sizeof(float), geom.indecies.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                          (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    if (wireframe == true){
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else{
      ;
    }
};

void Buffer::clearShader(){
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
};

void Buffer::drawShader(){
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, geom.indecies.size(), GL_UNSIGNED_INT, 0);
};
