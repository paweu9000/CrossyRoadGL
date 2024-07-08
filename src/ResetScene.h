#pragma once
#include "TextRenderer.h"

class ResetScene
{
public:
    ResetScene(TextRenderer* textRenderer);
    void RenderScene();
    void Activate();
    void Deactivate();
    bool isSceneActive();
private:
    TextRenderer* textRenderer;
    bool isActive;
};