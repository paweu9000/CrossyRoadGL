#include "game.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
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

bool Game::initialize()
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

    glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
    }

    glEnable(GL_DEPTH_TEST);

    shaderProgram = new Shader("src/shaders/vertex.vs", "src/shaders/fragment.fs");

    level = new Level();
    player = new Entity();

    return true;
}

void Game::run_loop()
{
    while (!glfwWindowShouldClose(this->window))
    {
        calculate_delta();
        process_input(this->window);
        update();
        draw();
        player->reset_direction();
    }
}

void Game::process_input(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && !player->is_moving())
    {
        player->set_direction(Direction::NORTH);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && !player->is_moving())
    {
        player->set_direction(Direction::SOUTH);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && !player->is_moving())
    {
        player->set_direction(Direction::EAST);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && !player->is_moving())
    {
        player->set_direction(Direction::WEST);
    }
}

void Game::update()
{
    this->level->update();
    this->player->update(deltaTime);
}

void Game::draw()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->level->draw();
    this->player->draw();

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Game::calculate_delta()
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}