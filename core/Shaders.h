#pragma once
#include "Geometry.h"
#include "stb_image.h"
#include <fstream>
#include <glad/glad.h>
#include <iostream>
#include <sstream>

class Buffer{
    
    public:
      Geometry geom;
      Buffer(Geometry geomtry);
      void loadToBuffer(bool wireframe);
      void drawShader();
      void clearShader();

    private:
      GLuint VBO;
      GLuint VAO;
      GLuint EBO;
};


class Shader{

  public:
    const char *shaderPath;
    Shader(const char *pathShader);
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
    ShaderProgram(unsigned int vShader, unsigned int fShader);
    void create();
    void useShader();

  private:
    unsigned int shaderProgram;
};


class Texture{
  public:
    const char *texturePath;
    Texture(const char *textPath);
    void load_texture();
    void draw_texture();
  private:
    unsigned int texture;
};