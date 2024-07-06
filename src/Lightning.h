#pragma once
#include <glm/glm.hpp>

namespace Lightning
{
    const glm::vec3 SpotAmbient = glm::vec3(1.0f, 1.0f, 1.0f);
    const glm::vec3 SpotDiffuse = glm::vec3(1.0f, 1.0f, 1.0f);
    const glm::vec3 SpotSpecular = glm::vec3(1.0f, 1.0f, 1.0f);
    const glm::vec3 PointAmbient = glm::vec3(0.25f, 0.25f, 0.25f);
    const glm::vec3 PointDiffuse = glm::vec3(0.8f, 0.8f, 0.8f);
    const glm::vec3 PointSpecular = glm::vec3(1.0f, 1.0f, 1.0f);
    const float Constant = 1.0f;
    const float Linear = 0.09f;
    const float Quadratic = 0.032f;
    const float SpotCutOff = glm::cos(glm::radians(7.5f));
    const float SpotOuterCutOff = glm::cos(glm::radians(10.0f));
    const glm::vec3 East = glm::vec3(1.0f, -0.2f, 0.0f);
    const glm::vec3 West = glm::vec3(-1.0f, -0.2f, 0.0f);
}