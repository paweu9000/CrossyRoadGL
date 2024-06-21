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
    void draw() override;
    void update();
private:
    ObjectType type;
};