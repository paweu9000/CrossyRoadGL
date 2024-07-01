#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Constants.h"

Camera::Camera(Player* player)
{
    this->cameraPos = glm::vec3(0.0f, 20.0f, -5.0f);
    this->cameraTarget = glm::vec3(player->GetModel()[3]);
    this->cameraUp = glm::vec3(0.0f, 20.0f, 0.0f);
    this->view = glm::lookAt(
        cameraPos, 
  		cameraTarget, 
  		cameraUp
    );
}

void Camera::Update(Player* player, float deltaTime)
{
    float movement = deltaTime * Constant::PlayerSpeed;

    switch (player->getDirection())
    {
    case Direction::NORTH:
        this->cameraPos += glm::vec3(0.f, 0.f, -movement);
        break;
    case Direction::SOUTH:
        this->cameraPos += glm::vec3(0.f, 0.f, movement);
        break;
    default:
        break;
    }
    this->cameraTarget = glm::vec3(player->GetModel()[3]);
    this->view = glm::lookAt(
        cameraPos, 
  		cameraTarget, 
  		cameraUp
    );
}

glm::mat4 Camera::GetView()
{
    return this->view;
}