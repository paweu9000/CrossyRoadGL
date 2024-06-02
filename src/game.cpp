#include "game.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Game::Game()
{}

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
    return true;
}

void Game::run_loop()
{
    while (!glfwWindowShouldClose(this->window))
    {
        process_input();
        update();
        draw();
    }
}

void Game::process_input()
{

}

void Game::update()
{

}

void Game::draw()
{
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
}