#pragma once
#include "TextRenderer.h"

class ResetScene
{
public:
    ResetScene(std::shared_ptr<TextRenderer> textRenderer);
    void RenderScene();
    void Activate();
    void Deactivate();
    bool isSceneActive();
private:
    std::shared_ptr<TextRenderer> textRenderer;
    bool isActive;
};