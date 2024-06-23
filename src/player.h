#pragma once
#include "entity.h"

class Player : public Entity
{
public:
    Player();
    void update(float deltaTime) override;
    void draw() override;
    bool is_moving();
private:
    bool isMoving;
    float movementAngle;
};