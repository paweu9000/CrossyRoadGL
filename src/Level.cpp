#include "Level.h"
#include <algorithm>

Level::Level()
{
    for (int i = 1; i <= 10; ++i)
    {
        AddElement(i);
    }
}

void Level::Update(float playerDepth)
{
    this->RemoveOOBElements(playerDepth);
    for (const auto &element : elements)
    {
        element->Update();
    }
}

void Level::Draw(glm::mat4 view, const std::vector<std::shared_ptr<Entity>> entities)
{
    auto viewPos = glm::vec3(view[3][0], view[3][1], view[3][2]);
    std::vector<std::shared_ptr<LevelElement>> lamps;
    for (const auto &element : elements)
    {
        if (element->GetType() == ObjectType::LAMP) lamps.push_back(element);
    }
    for (const auto &element : elements)
    {
        element->SetPointLight(lamps);
        element->SetSpotLightning(entities);
        element->Draw(view);
    }
}

void Level::AddElement(int depth)
{
    this->elements.push_back(std::make_shared<LevelElement>(ObjectType::GRASS, depth));
    this->elements.push_back(std::make_shared<LevelElement>(ObjectType::ROAD, depth));
    this->elements.push_back(std::make_shared<LevelElement>(ObjectType::LINE, depth));
    this->elements.push_back(std::make_shared<LevelElement>(ObjectType::LAMP, depth));
}

void Level::RemoveOOBElements(float playerDepth)
{
    std::vector<std::shared_ptr<LevelElement>> oobElements;
    for (auto element : elements)
    {
        if (element->GetDepth() > playerDepth + 60.f)
        {
            oobElements.emplace_back(element);
        }
    }

    for (auto element : oobElements)
    {
        auto iter = std::find(std::begin(elements), std::end(elements), element);
        if (iter != elements.end())
        {
            std::iter_swap(iter, elements.end() - 1);
            elements.pop_back();
        }
    }
}
