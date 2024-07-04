#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

class TextureManager
{
public:
    TextureManager();
    static unsigned int GetTexture(std::string texName);
private:
    void LoadTextures();
    static std::unordered_map<std::string, unsigned int> textures;
};