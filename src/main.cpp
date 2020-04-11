#include "../include/Game.h"

int main()
{
    Game game;

    while (game.isPlaying()) {
        game.mainMenu();
    }

    std::cout << "Au revoir ..." << std::endl;
    return 0;
}
