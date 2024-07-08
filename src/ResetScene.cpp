#include "ResetScene.h"

ResetScene::ResetScene(TextRenderer* renderer)
{
    this->isActive = false;
    this->textRenderer = renderer;
}

void ResetScene::Activate()
{
    this->isActive = true;
}

void ResetScene::Deactivate()
{
    this->isActive = false;
}

bool ResetScene::isSceneActive()
{
    return this->isActive;
}

void ResetScene::RenderScene()
{
    textRenderer->RenderText("You got hit! Press R to restart", 300.f, 360.f);
}
