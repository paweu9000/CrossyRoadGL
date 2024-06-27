#pragma once
#include "entity.h"

class Player : public Entity
{
public:
    Player();
    void update(float deltaTime) override;
    void draw(glm::mat4 view) override;
    void show_collision(bool collides);
    bool is_moving();
private:
    bool move_out_of_bounds();
    bool isMoving;
    float movementAngle;
};