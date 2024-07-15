#pragma once
#include "element.h"
#include <vector>
#include "Entity.h"

enum class ObjectType
{
    ROAD, LINE, GRASS, LAMP
};

class LevelElement : public Element
{
public:
    LevelElement(ObjectType type, int depth);
    void Draw(glm::mat4 view) override;
    void Update();
    void SetLightning(glm::vec3 viewPos) override;
    void SetSpotLightning(const std::vector<std::shared_ptr<Entity>> entities);
    void SetPointLight(const std::vector<std::shared_ptr<LevelElement>> lamps);
    ObjectType GetType() const;
private:
    void BindVertices();
    ObjectType type;
    bool inBounds;
};
