#pragma once
#include <glm/glm.hpp>
#include "player.h"

enum class CMove
{
   Front, Back 
};

class Camera
{
public:
    Camera(Player* player);
    glm::mat4 get_view();
    void update(Player* player, float deltaTime);
private:
    glm::vec3 cameraPos;
    glm::vec3 cameraTarget;
    glm::vec3 cameraUp;
    glm::mat4 view;
};