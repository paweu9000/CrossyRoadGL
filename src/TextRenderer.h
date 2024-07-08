#pragma once
#include <ft2build.h>
#include FT_FREETYPE_H
#include "glm/glm.hpp"
#include <unordered_map>
#include "Shader.h"
#include <string>

struct Character 
{
    unsigned int TextureID;
    glm::ivec2 Size;
    glm::ivec2 Bearing;
    unsigned int Advance;
};

class TextRenderer
{
public:
    TextRenderer();
    void RenderText(std::string text, float x, float y);
protected:
    std::unordered_map<char, Character> characters;
    glm::mat4 projection;
    Shader* shader;
    unsigned int VAO, VBO;
};