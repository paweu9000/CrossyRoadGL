#include "game.h"
#include <iostream>
#include "enemy.h"
#include "constants.h"

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

void Game::run_loop()
{
    while (!glfwWindowShouldClose(this->window))
    {
        calculate_delta();
        process_input(this->window);
        update();
        draw();
    }
}

void Game::process_input(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && !player->is_moving())
    {
        player->set_direction(Direction::NORTH);
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
    this->generate_level();
    this->level->update();
    for (const auto& entity: entities)
    {
        entity->update(deltaTime);
    }
    if (this->check_collision())
    {
    // TODO:
        player->show_collision(true);
    // Implement end of the game
    }
    else
    {
        player->show_collision(false);
    }
    camera->update(player, deltaTime);
}

void Game::draw()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->level->draw(camera->get_view());
    for (const auto& entity: entities)
    {
        entity->draw(camera->get_view());
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Game::calculate_delta()
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

bool Game::check_collision()
{
    AABB a = player->get_AABB(camera->get_view());

    int meetingAxies = 0;

    for (int i = 1; i < entities.size(); i++)
    {
        AABB b = entities[i]->get_AABB(camera->get_view());
        if ((a.min.x <= b.max.x && a.max.x >= b.min.x) &&
           (a.min.y <= b.max.y && a.max.y >= b.min.y) &&
           (a.min.z <= b.max.z && a.max.z >= b.min.z))
        {
            return true;
        }
    }
    return false;
}

void Game::generate_level()
{
    if (player->get_depth() + (Constant::depth_offset * 3.f) < depth * Constant::depth_offset)
    {
        this->level->add_element(depth);
        entities.push_back(new Enemy(Direction::EAST, depth));
        entities.push_back(new Enemy(Direction::WEST, depth));
        ++depth;
    }
}