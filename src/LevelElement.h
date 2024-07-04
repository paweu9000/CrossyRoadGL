#pragma once
#include "element.h"

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
private:
    void BindVertices();
    ObjectType type;
    bool inBounds;
};
