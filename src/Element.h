#pragma once
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <memory>
#include "Shared/Material.h"

class Element
{
public:
    Element();
    virtual void Draw(glm::mat4 view);
    float GetDepth();
protected:
    virtual glm::vec3 ConfigureDepth(glm::vec3 vec, int depth);
    void SetMaterial(Material material);
    void SetDirectionLight();
    virtual void SetLightning(glm::vec3 viewPos) {}
    std::vector<float> vertices;
    std::unique_ptr<Shader> shader;
    unsigned int VBO, VAO;
    glm::mat4 projection;
    glm::mat4 model;
    unsigned int textureID;
};