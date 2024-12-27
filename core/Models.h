#pragma once
#include "Buffer.h"
#include "Shaders.h"
#include "Texture.h"


class BaseModel{
    public:
        Shader vertexShader;
        Shader fragmentShader;
        ShaderProgram shaderProgram;
        Texture texture;
        Geometry 
};