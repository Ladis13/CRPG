#include "../include/Game.h"

Game::Game()
{
    this->choice = 0;
    this->playing = true;
}

Game::~Game()
{
}

void Game::mainMenu()
{
    std::cout << "MENU PRINCIPAL" << std::endl;
    std::cout << "0.Quitter" << std::endl;
    std::cout << "1.Personnage" << std::endl;

    std::cout << std::endl << "Choix :";
    std::cin >> this->choice;
    std::cout << std::endl;

    switch (this->choice) {
        case 0:
            this->playing = false;
            break;
        case 1:
            player.print();
            break;
        default:
            break;
    }
}
