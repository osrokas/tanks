#pragma once
#include "Buffer.h"
#include "Shaders.h"
#include "Texture.h"
#include "Sprites.h"
#include "Geometry.h"
#include <cstddef>

class BaseModel{
    public:
        std::string vertexShaderPath;
        std::string fragmentShaderPath;
        std::string texturePath;

        BaseModel(std::string vShaderPath, std::string fShaderPath,
                  std::string tPath);
        void create_model();
        void draw_model();
        void addVector(Sprite &spriteVector);
        void addIndex(unsigned int index);
        // Fix create sprite 
        // Error with creating geometry 
        void createSprite();

      private:
        Shader vertexShader;
        Shader fragmentShader;
        ShaderProgram* shaderProgram = NULL;
        Texture texture;
        std::vector<Sprite> geometry;
        std::vector<float> vertices;
        std::vector<unsigned int> indecies;
        Buffer *buffering = NULL;
        Geometry geomObject;
        unsigned int vShader;
        unsigned int fShader;
};