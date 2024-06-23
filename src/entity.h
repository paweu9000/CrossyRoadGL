#pragma once
#include "shader.h"
#include "element.h"

enum class Direction
{
    NORTH, EAST, WEST, SOUTH, NONE
};

class Entity : public Element
{
public:
    Entity();
    virtual void update(float deltaTime);
    void set_direction(Direction direction);
protected:
    Direction direction;
};