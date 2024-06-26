#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include "constants.h"

Camera::Camera(Player* player)
{
    this->cameraPos = glm::vec3(0.0f, 20.0f, -5.0f);
    this->cameraTarget = glm::vec3(player->get_model()[3]);
    this->cameraUp = glm::vec3(0.0f, 20.0f, 0.0f);
    this->view = glm::lookAt(
        cameraPos, 
  		cameraTarget, 
  		cameraUp
    );
}

void Camera::update(Player* player, float deltaTime)
{
    float movement = deltaTime * Constant::player_speed;

    switch (player->get_direction())
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
    this->cameraTarget = glm::vec3(player->get_model()[3]);
    this->view = glm::lookAt(
        cameraPos, 
  		cameraTarget, 
  		cameraUp
    );
}

glm::mat4 Camera::get_view()
{
    return this->view;
}