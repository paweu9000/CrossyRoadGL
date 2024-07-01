#include "Game.h"
#include <iostream>
#include "Enemy.h"
#include "Constants.h"
#include <algorithm>

void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Game::Game() 
{
    deltaTime = 0;
    lastFrame = 0;
}

Game::~Game()
{
    glfwTerminate();
}

bool Game::Initialize()
{
    if (!glfwInit()) return false;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    this->width = 1280;
    this->height = 720;

    this->window = glfwCreateWindow(width, height, "Crossy Road GL", nullptr, nullptr);
    if (!window) 
    {
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(this->window);

    glfwSetFramebufferSizeCallback(this->window, FramebufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
    }

    glEnable(GL_DEPTH_TEST);

    shaderProgram = new Shader("src/shaders/vertex.vs", "src/shaders/fragment.fs");

    this->depth = 1;

    level = new Level();
    player = new Player();
    entities.push_back(player);
    for (depth; depth <= 10; ++depth)
    {
        entities.push_back(new Enemy(Direction::EAST, depth));
        entities.push_back(new Enemy(Direction::WEST, depth));
    }
    
    camera = new Camera(player);

    return true;
}

void Game::RunLoop()
{
    while (!glfwWindowShouldClose(this->window))
    {
        CalculateDelta();
        ProcessInput(this->window);
        Update();
        Draw();
    }
}

void Game::ProcessInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && !player->IsMoving())
    {
        player->SetDirection(Direction::NORTH);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && !player->IsMoving())
    {
        player->SetDirection(Direction::EAST);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && !player->IsMoving())
    {
        player->SetDirection(Direction::WEST);
    }
    // if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && !player->IsMoving())
    // {
    //     player->SetDirection(Direction::SOUTH);
    // }
}

void Game::Update()
{
    this->GenerateLevel();
    level->Update(player->GetDepth());
    for (const auto& entity: entities)
    {
        entity->Update(deltaTime);
    }
    if (this->CheckCollision())
    {
    // TODO:
        player->ShowCollision(true);
    // Implement end of the game
    }
    else
    {
        player->ShowCollision(false);
    }
    camera->Update(player, deltaTime);
    this->RemoveOOBElements();
}

void Game::Draw()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    level->Draw(camera->GetView());
    for (const auto& entity: entities)
    {
        entity->Draw(camera->GetView());
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Game::CalculateDelta()
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

bool Game::CheckCollision()
{
    AABB a = player->GetAABB(camera->GetView());

    int meetingAxies = 0;

    for (int i = 1; i < entities.size(); i++)
    {
        AABB b = entities[i]->GetAABB(camera->GetView());
        if ((a.min.x <= b.max.x && a.max.x >= b.min.x) &&
           (a.min.y <= b.max.y && a.max.y >= b.min.y) &&
           (a.min.z <= b.max.z && a.max.z >= b.min.z))
        {
            return true;
        }
    }
    return false;
}

void Game::GenerateLevel()
{
    if (player->GetDepth() + (Constant::DepthOffset * 3.f) < depth * Constant::DepthOffset)
    {
        this->level->AddElement(depth);
        entities.push_back(new Enemy(Direction::EAST, depth));
        entities.push_back(new Enemy(Direction::WEST, depth));
        ++depth;
    }
}

void Game::RemoveOOBElements()
{
    auto player_depth = player->GetDepth();
    std::vector<Entity*> oob_entities;
    for (int i = 1; i < entities.size(); ++i)
    {
        if (entities[i]->GetDepth() > player_depth + 60.f)
        {
            oob_entities.emplace_back(entities[i]);
        }
    }

    for (auto entity : oob_entities)
    {
        auto iter = std::find(entities.begin(), entities.end(), entity);
        if (iter != entities.end())
        {
            std::iter_swap(iter, entities.end()-1);
            entities.pop_back();
        }
    }
}