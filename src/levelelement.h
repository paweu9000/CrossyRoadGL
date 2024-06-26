#pragma once
#include "element.h"

enum class ObjectType
{
    ROAD, LINE, GRASS
};

class LevelElement : protected Element
{
public:
    LevelElement(ObjectType type);
    void draw(glm::mat4 view) override;
    void update();
private:
    void bind_vertices();
    ObjectType type;
};