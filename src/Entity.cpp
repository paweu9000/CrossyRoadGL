#include "Entity.h"

Entity::Entity() : direction(Direction::NONE)
{
}

void Entity::Update(float deltaTime)
{
}

void Entity::SetDirection(Direction direction)
{
    this->direction = direction;
}

AABB Entity::GetAABB(glm::mat4 view)
{
    std::vector<glm::vec3> positions;
    for (int i = 0; i < vertices.size(); i += 6)
    {
        positions.emplace_back(vertices[i], vertices[i+1], vertices[i+2]);
    }

    std::vector<glm::vec3> transformedPositions;
    transformedPositions.reserve(positions.size());

    for (const auto& pos: positions)
    {
        glm::vec4 transformedPos = projection * view * model * glm::vec4(pos, 1.f);
        transformedPositions.push_back(transformedPos);
    }

    glm::vec3 min = transformedPositions[0];
    glm::vec3 max = transformedPositions[0];

    for (const auto& pos: transformedPositions)
    {
        min = glm::min(min, pos);
        max = glm::max(max, pos);
    }

    return {min, max};
}

glm::mat4 Entity::GetModel() const
{
    return this->model;
}

Direction Entity::getDirection() const
{
    return this->direction;
}
