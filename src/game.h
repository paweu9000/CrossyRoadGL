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
    GLFWwindow* window;
    int width;
    int height;
};