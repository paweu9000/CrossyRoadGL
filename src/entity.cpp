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