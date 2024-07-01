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
    virtual void Update(float deltaTime);
    void SetDirection(Direction direction);
    Direction getDirection() const;
    AABB GetAABB(glm::mat4 view);
    glm::mat4 GetModel() const;
protected:
    Direction direction;
};