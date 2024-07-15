#pragma once
#include "glm/glm.hpp"
#include "../TextureManager.h"

struct Material
{
    unsigned int diffuse;
    unsigned int specular;
    float shininess;
};

namespace Materials
{
    const Material Player = {TextureManager::GetTexture("player"), TextureManager::GetTexture("player_specular"), 32.f};
    const Material Enemy = {TextureManager::GetTexture("enemy"), TextureManager::GetTexture("enemy_specular"), 32.f};
    const Material Road = {TextureManager::GetTexture("road"), TextureManager::GetTexture("road_specular"), 32.f};
    const Material Grass = {TextureManager::GetTexture("grass"), TextureManager::GetTexture("grass_specular"), 32.f};
    const Material Lines = {TextureManager::GetTexture("lines"), TextureManager::GetTexture("lines_specular"), 32.f};
}