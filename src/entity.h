#pragma once
#include "shader.h"
#include "element.h"

enum class Direction
{
    NORTH, EAST, WEST, SOUTH, NONE
};

class Entity : protected Element
{
public:
    Entity();
    void update(float deltaTime);
    void draw() override;
    void set_direction(Direction direction);
    void reset_direction();
    bool is_moving();
private:
    Direction direction;
    bool isMoving;
    float movementAngle;
    glm::vec3 cubePosition;
    glm::quat cubeRotation;
};