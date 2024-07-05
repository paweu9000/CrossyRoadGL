#pragma once
#include "element.h"
#include <vector>
#include "Entity.h"

enum class ObjectType
{
    ROAD, LINE, GRASS
};

class LevelElement : public Element
{
public:
    LevelElement(ObjectType type, int depth);
    void Draw(glm::mat4 view) override;
    void Update();
    void SetLightning(glm::vec3 viewPos) override;
    void SetSpotLightning(const std::vector<Entity*> entities);
private:
    void BindVertices();
    ObjectType type;
    bool inBounds;
};
