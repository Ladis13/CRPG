#include "../include/Game.h"

int main()
{
    Game game;

    game.initMenu();

    while (game.isPlaying()) {
        game.mainMenu();
    }

    std::cout << "=\tAu revoir ..." << std::endl;
    std::cout << "=\n======" << std::endl;
    return 0;
}
