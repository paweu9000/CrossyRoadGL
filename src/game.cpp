#include "game.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Game::Game() : 
vertices{
    // Triangles         // Colors
    -0.5f, -0.5f, -0.5f, 1.f, 0.f, 0.f,
     0.5f, -0.5f, -0.5f, 1.f, 0.f, 0.f,
     0.5f,  0.5f, -0.5f, 1.f, 0.f, 0.f,
     0.5f,  0.5f, -0.5f, 1.f, 0.f, 0.f,
    -0.5f,  0.5f, -0.5f, 1.f, 0.f, 0.f,
    -0.5f, -0.5f, -0.5f, 1.f, 0.f, 0.f,

    -0.5f, -0.5f,  0.5f, 1.f, 0.1f, 0.f,
     0.5f, -0.5f,  0.5f, 1.f, 0.1f, 0.f,
     0.5f,  0.5f,  0.5f, 1.f, 0.1f, 0.f,
     0.5f,  0.5f,  0.5f, 1.f, 0.1f, 0.f,
    -0.5f,  0.5f,  0.5f, 1.f, 0.1f, 0.f,
    -0.5f, -0.5f,  0.5f, 1.f, 0.1f, 0.f,

    -0.5f,  0.5f,  0.5f, 1.f, 0.1f, 0.1f,
    -0.5f,  0.5f, -0.5f, 1.f, 0.1f, 0.1f,
    -0.5f, -0.5f, -0.5f, 1.f, 0.1f, 0.1f,
    -0.5f, -0.5f, -0.5f, 1.f, 0.1f, 0.1f,
    -0.5f, -0.5f,  0.5f, 1.f, 0.1f, 0.1f,
    -0.5f,  0.5f,  0.5f, 1.f, 0.1f, 0.1f,

     0.5f,  0.5f,  0.5f, 1.f, 0.2f, 0.2f,
     0.5f,  0.5f, -0.5f, 1.f, 0.2f, 0.2f,
     0.5f, -0.5f, -0.5f, 1.f, 0.2f, 0.2f,
     0.5f, -0.5f, -0.5f, 1.f, 0.2f, 0.2f,
     0.5f, -0.5f,  0.5f, 1.f, 0.2f, 0.2f,
     0.5f,  0.5f,  0.5f, 1.f, 0.2f, 0.2f,

    -0.5f, -0.5f, -0.5f, 1.f, 0.3f, 0.1f,
     0.5f, -0.5f, -0.5f, 1.f, 0.3f, 0.1f,
     0.5f, -0.5f,  0.5f, 1.f, 0.3f, 0.1f,
     0.5f, -0.5f,  0.5f, 1.f, 0.3f, 0.1f,
    -0.5f, -0.5f,  0.5f, 1.f, 0.3f, 0.1f,
    -0.5f, -0.5f, -0.5f, 1.f, 0.3f, 0.1f,

    -0.5f,  0.5f, -0.5f, 1.f, 0.3f, 0.3f,
     0.5f,  0.5f, -0.5f, 1.f, 0.3f, 0.3f,
     0.5f,  0.5f,  0.5f, 1.f, 0.3f, 0.3f,
     0.5f,  0.5f,  0.5f, 1.f, 0.3f, 0.3f,
    -0.5f,  0.5f,  0.5f, 1.f, 0.3f, 0.3f,
    -0.5f,  0.5f, -0.5f, 1.f, 0.3f, 0.3f
},
levelVertices{
    -20.f, -20.f, -1.f, 1.f, 0.f, 0.0f,
    20.f, -20.f, -1.f, 0.0f, 1.f, 1.f,
    20.f,  20.f, -1.f, 1.f, 1.f, 0.0f,
    20.f,  20.f, -1.f, 1.f, 1.f, 0.0f,
    -20.f,  20.f, -1.f, 0.f, 0.f, 1.f,
    -20.f, -20.f, -1.f, 1.f, 0.f, 0.0f,
}{
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

    shaderPrograms.push_back(new Shader("src/shaders/vertex.vs", "src/shaders/fragment.fs"));
    shaderPrograms.push_back(new Shader("src/shaders/level_vertex.vs", "src/shaders/level_fragment.fs"));

    this->projection = glm::mat4(1.f);
    this->model = glm::mat4(1.f);
    this->view = glm::mat4(1.f);
    this->projection = glm::perspective(glm::radians(45.f), (float)width/(float)height, 0.1f, 100.f);
    this->model = glm::rotate(model, glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f));
    this->view = glm::translate(view, glm::vec3(0.f, 0.f, -10.f));

    this->levelProjection = glm::mat4(1.f);
    this->levelModel = glm::mat4(1.f);
    this->levelView = glm::mat4(1.f);
    this->levelProjection = glm::perspective(glm::radians(45.f), (float)width/(float)height, 0.1f, 100.f);
    this->levelModel = glm::translate(levelModel, glm::vec3(0.f, -5.f, 0.f));
    this->levelView = glm::translate(levelView, glm::vec3(0.f, 0.f, -10.f));

    glGenVertexArrays(1, &this->VAO[0]);
    glGenBuffers(1, &this->VBO[0]);
    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenVertexArrays(1, &this->VAO[1]);
    glGenBuffers(1, &this->VBO[1]);
    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(levelVertices), levelVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(10, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(10);
    glVertexAttribPointer(11, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(11);
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
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        model = glm::rotate(model, deltaTime*3, glm::vec3(-1.0f, 0.0f, 0.0f));
        view = glm::translate(view, glm::vec3(0.f, deltaTime*3, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        model = glm::rotate(model, deltaTime*3, glm::vec3(1.0f, 0.0f, 0.0f));
        view = glm::translate(view, glm::vec3(0.f, -deltaTime*3, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        model = glm::rotate(model, deltaTime*3, glm::vec3(0.0f, 0.f, 1.0f));
        view = glm::translate(view, glm::vec3(deltaTime*3, 0.f, 0.f));
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        model = glm::rotate(model, deltaTime*3, glm::vec3(0.0f, 0.0f, -1.0f));
        view = glm::translate(view, glm::vec3(-deltaTime*3, 0.f, 0.f));
    }
}

void Game::update()
{

}

void Game::draw()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderPrograms[1]->use();
    shaderPrograms[1]->set_mat4("model", this->levelModel);
    shaderPrograms[1]->set_mat4("view", this->levelView);
    shaderPrograms[1]->set_mat4("projection", this->levelProjection);
    auto color = cos(glfwGetTime());
    shaderPrograms[1]->set_float("colorChange", color < 0.8f ? 0.8f : color);

    glBindVertexArray(VAO[1]);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    shaderPrograms[0]->use();
    shaderPrograms[0]->set_mat4("model", this->model);
    shaderPrograms[0]->set_mat4("view", this->view);
    shaderPrograms[0]->set_mat4("projection", this->projection);
    
    glBindVertexArray(VAO[0]);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Game::calculate_delta()
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}