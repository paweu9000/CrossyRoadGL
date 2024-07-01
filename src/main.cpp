#include <iostream>
#include "Game.h"

int main()
{
    auto game = new Game();
    if (game->Initialize())
    {
        game->RunLoop();
    }
    else
    {
        std::cout << "ERROR::INITIALIZING::GAME";
    }
    return 0;
}