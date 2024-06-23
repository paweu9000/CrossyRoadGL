#pragma once
#include "entity.h"

class Enemy : public Entity
{
public:
    Enemy(Direction direction);
    void update(float deltaTime) override;
    void draw() override;
private:
    float movement_speed;
};