#include "../include/Game.h"

int main()
{
    Game game;

    game.initMenu();

    while (game.isPlaying()) {
        game.mainMenu();
    }

    std::cout << std::endl << "Au revoir ..." << std::endl;
    return 0;
}
