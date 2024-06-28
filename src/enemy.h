#pragma once
#include "entity.h"

class Enemy : public Entity
{
public:
    Enemy(Direction direction, int depth);
    void update(float deltaTime) override;
    void draw(glm::mat4 view) override;
private:
    glm::vec3 configure_depth(glm::vec3 vec, int depth) override;
    float movement_speed;
    void reset_position();
    int depth;
    float speed_multiplier;
};