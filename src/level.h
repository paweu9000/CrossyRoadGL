#pragma once
#include "element.h"
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Level : protected Element
{
public:
    Level();
    const std::vector<float> get_vertices() const;
    void update();
    void draw();
};