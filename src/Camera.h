#pragma once
#include <glm/glm.hpp>
#include "Player.h"

enum class CMove
{
   Front, Back 
};

class Camera
{
public:
    Camera(std::shared_ptr<Player> player);
    glm::mat4 GetView();
    void Update(std::shared_ptr<Player> player, float deltaTime);
private:
    glm::vec3 cameraPos;
    glm::vec3 cameraTarget;
    glm::vec3 cameraUp;
    glm::mat4 view;
};
