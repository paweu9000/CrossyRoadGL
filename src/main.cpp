#include <iostream>
#include "game.h"

int main()
{
    auto game = new Game();
    if (game->initialize())
    {
        game->run_loop();
    }
    else
    {
        std::cout << "ERROR::INITIALIZING::GAME";
    }
    return 0;
}