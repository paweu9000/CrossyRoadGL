#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
    Player();
    void Update(float deltaTime) override;
    void Draw(glm::mat4 view) override;
    void ShowCollision(bool collides);
    bool IsMoving();
private:
    bool MoveOutOfBounds();
    bool isMoving;
    float movementAngle;
};