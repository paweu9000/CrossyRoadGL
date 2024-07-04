#include "TextureManager.h"
#include "Constants.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"

std::unordered_map<std::string, unsigned int> TextureManager::textures;

TextureManager::TextureManager()
{
    LoadTextures();
}

void TextureManager::LoadTextures()
{
    auto genTexture = [](std::string fileName){
        unsigned int textureID;
        glGenTextures(1, &textureID);
        int width, height, nrComponents;
        std::string path = "src/textures/" + fileName;
        unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrComponents, 0);

        if (data)
        {
            GLenum format;
            if (nrComponents == 1) format = GL_RED;
            else if (nrComponents == 3) format = GL_RGB;
            else if (nrComponents == 4) format = GL_RGBA;

            glBindTexture(GL_TEXTURE_2D, textureID);
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "TEXTURE::LOAD FAILURE::" << path << std::endl;
            stbi_image_free(data);
        }
        return textureID;
    };
    this->textures["player"] = genTexture(Constant::Textures[0]);
    this->textures["enemy"] = genTexture(Constant::Textures[1]);
    this->textures["grass"] = genTexture(Constant::Textures[2]);
    this->textures["road"] = genTexture(Constant::Textures[3]);
    this->textures["lines"] = genTexture(Constant::Textures[4]);
}

unsigned int TextureManager::GetTexture(std::string texName)
{
    return textures[texName];
}