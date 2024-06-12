#pragma once
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum class Direction
{
    NORTH, EAST, WEST, SOUTH, NONE
};

class Entity
{
public:
    Entity();
    void update(float deltaTime);
    void draw();
    void set_direction(Direction direction);
    void reset_direction();
    bool is_moving();
private:
    float vertices[324];
    unsigned int VAO, VBO;
    Shader* shader;
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 view;
    Direction direction;
    bool isMoving;
    float movementAngle;
};