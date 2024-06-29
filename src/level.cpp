#include "level.h"
#include <algorithm>

Level::Level()
{
    for (int i = 1; i <= 10; ++i)
    {
        add_element(i);
    }
}

void Level::update(float player_depth)
{
    this->remove_oob_elements(player_depth);
    for (const auto& element: elements)
    {
        element->update();
    }
}

void Level::draw(glm::mat4 view)
{
    for (const auto& element: elements)
    {
        element->draw(view);
    }
}

void Level::add_element(int depth)
{
    this->elements.push_back(new LevelElement(ObjectType::GRASS, depth));
    this->elements.push_back(new LevelElement(ObjectType::ROAD, depth));
    this->elements.push_back(new LevelElement(ObjectType::LINE, depth));
}

void Level::remove_oob_elements(float player_depth)
{
    std::vector<LevelElement*> oob_elements;
    for (auto element : elements)
    {
        if (element->get_depth() > player_depth + 60.f)
        {
            oob_elements.emplace_back(element);
        }
    }

    for (auto element : oob_elements)
    {
        auto iter = std::find(elements.begin(), elements.end(), element);
        if (iter != elements.end())
        {
            std::iter_swap(iter, elements.end()-1);
            elements.pop_back();
        }
    }
}