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
    Direction get_direction() const;
    AABB get_AABB(glm::mat4 view);
    glm::mat4 get_model() const;
protected:
    Direction direction;
};