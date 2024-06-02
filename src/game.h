#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game
{
public:
    Game();
    ~Game();
    bool initialize();
    void run_loop();

private:
    void process_input();
    void update();
    void draw();
    bool check_shader_compile_status(int shaderId);
    GLFWwindow* window;
    int width;
    int height;
    float vertices[9];
    unsigned int VAO, VBO;
    unsigned int vertexShader, fragmentShader;
    unsigned int shaderProgram;
};