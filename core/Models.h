#pragma once
#include "Buffer.h"
#include "Geometry.h"
#include "Shaders.h"
#include "Sprites.h"
#include "Texture.h"
#include "Transformations.h"
#include <cstddef>

class BaseModel{
    public:
        std::string vertexShaderPath;
        std::string fragmentShaderPath;
        std::string texturePath;
        BaseModel(std::string vShaderPath, std::string fShaderPath,
                  std::string tPath);
        void create_model();
        void draw_model(float angle, float x, float y, Extent bounds);
        void addVector(Sprite &spriteVector);
        void addIndex(unsigned int index);
        // Fix create sprite 
        // Error with creating geometry 
        void createSprite();
        unsigned int getShaderProgram();
        void set_positions();

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
        Transformation* tranformormation = NULL; 
        unsigned int vShader;
        unsigned int fShader;

      protected:
        float angle = 0.0f;
        float startX = 0.0f;
        float startY = 0.0f;
        Extent bounds = {0.8f, 0.8f, -0.8f, -0.8f};
        float speed;
};