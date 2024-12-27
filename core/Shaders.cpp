#include "Shaders.h"


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
}

void Buffer::drawShader(){
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, geom.indecies.size(), GL_UNSIGNED_INT, 0);
};


Shader::Shader(const char *pathShader)
    : shaderPath(pathShader)
{}

unsigned int Shader::compileShader(GLenum type) {
  int success;
  char infoLog[512];
  std::string code;
  code = Shader::readFile();
  const char* shaderCode = code.c_str();
  unsigned int shader;
  shader = glCreateShader(type);
  glShaderSource(shader, 1, &shaderCode, NULL);
  glCompileShader(shader);
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  return shader;
}


ShaderProgram::ShaderProgram(unsigned int vShader, unsigned int fShader)
    : vertexShader(vShader), fragmentShader(fShader),
      shaderProgram() {}

void ShaderProgram::create(){
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
}

void ShaderProgram::useShader() { 
  glUseProgram(shaderProgram); 
}


Texture::Texture(const char *textPath) :
  texturePath(textPath) {}

void Texture::load_texture() { 
  glGenTextures(1, &texture); 
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  int width, height, nrChannels;
  unsigned char *data =
      stbi_load(texturePath, &width, &height, &nrChannels, 0);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
               GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);
  stbi_image_free(data);
  }

  void Texture::draw_texture() { 
    glBindTexture(GL_TEXTURE_2D, texture);
   }