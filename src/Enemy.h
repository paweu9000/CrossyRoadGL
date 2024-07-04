#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
    Enemy(Direction direction, int depth);
    void Update(float deltaTime) override;
    void Draw(glm::mat4 view) override;
    void SetLightning(glm::vec3 viewPos) override;
private:
    glm::vec3 ConfigureDepth(glm::vec3 vec, int depth) override;
    void ResetPosition();
    float movementSpeed;
    int depth;
    float speedMultiplier;
};
