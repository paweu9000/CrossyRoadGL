#pragma once
#include "LevelElement.h"

class Level
{
public:
    Level();
    void Update(float playerDepth);
    void Draw(glm::mat4 view, const std::vector<std::shared_ptr<Entity>> entities);
    void AddElement(int depth);
private:
    void RemoveOOBElements(float playerDepth);
    std::vector<std::shared_ptr<LevelElement>> elements;
};
