#include "Shaders.h"

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