#pragma once
#include "shader.h"
#include "element.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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
};