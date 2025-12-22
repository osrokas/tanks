#pragma once
#include "Geometry.h"
#include "stb_image.h"
#include <fstream>
#include "glad/glad.h"
#include <iostream>
#include <sstream>
#include <vector>

class Shader{

  public:
    std::string shaderPath;
    Shader(std::string pathShader);
    unsigned int compileShader(GLenum type);

  private:
    std::string readFile() { 
      // Define variables
      std::string shaderCode;
      std::ifstream shaderFile;
      // Open shader file
      shaderFile.open(shaderPath);
      // Read content into stream
      std::stringstream shaderStream;
      shaderStream << shaderFile.rdbuf();
      // Close file
      shaderFile.close();
      // Convert stream into string
      shaderCode = shaderStream.str();
      
      return shaderCode;
      }
};


class ShaderProgram{
  public:
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;
    ShaderProgram(unsigned int vShader, unsigned int fShader);
    void create();
    void useShader();
    unsigned int getShaderProgram();
};

