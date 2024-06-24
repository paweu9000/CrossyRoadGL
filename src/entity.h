#pragma once
#include "shader.h"
#include "element.h"

enum class Direction
{
    NORTH, EAST, WEST, SOUTH, NONE
};

struct AABB
{
    glm::vec3 min;
    glm::vec3 max;
};

class Entity : public Element
{
public:
    Entity();
    virtual void update(float deltaTime);
    void set_direction(Direction direction);
    AABB get_AABB();
protected:
    Direction direction;
};