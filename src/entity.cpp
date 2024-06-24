#include "entity.h"

Entity::Entity() : direction(Direction::NONE)
{
}

void Entity::update(float deltaTime)
{
}

void Entity::set_direction(Direction direction)
{
    this->direction = direction;
}

AABB Entity::get_AABB()
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