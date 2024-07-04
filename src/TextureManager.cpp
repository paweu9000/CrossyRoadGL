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
    
    this->textures["player"] = genTexture(Constant::PlayerTexture);
    this->textures["player_normal"] = genTexture(Constant::PlayerNormalTexture);
    this->textures["player_specular"] = genTexture(Constant::PlayerSpecularTexture);
    this->textures["enemy"] = genTexture(Constant::EnemyTexture);
    this->textures["enemy_normal"] = genTexture(Constant::EnemyNormalTexture);
    this->textures["enemy_specular"] = genTexture(Constant::EnemySpecularTexture);
    this->textures["grass"] = genTexture(Constant::GrassTexture);
    this->textures["grass_normal"] = genTexture(Constant::GrassNormalTexture);
    this->textures["grass_specular"] = genTexture(Constant::GrassSpecularTexture);
    this->textures["road"] = genTexture(Constant::RoadTexture);
    this->textures["road_normal"] = genTexture(Constant::RoadNormalTexture);
    this->textures["road_specular"] = genTexture(Constant::RoadSpecularTexture);
    this->textures["lines"] = genTexture(Constant::LinesTexture);
    this->textures["lines_normal"] = genTexture(Constant::LinesNormalTexture);
    this->textures["lines_specular"] = genTexture(Constant::LinesSpecularTexture);
}

unsigned int TextureManager::GetTexture(std::string texName)
{
    return textures[texName];
}