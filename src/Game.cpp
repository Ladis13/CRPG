#include "../include/Game.h"

Game::Game()
{
    this->choice = 0;
    this->playing = true;

    this->savefile = "data/save.data";
}

Game::~Game()
{
}

void Game::initMenu()
{
    std::cout << "--== CRPG ==--" << std::endl << std::endl;
    std::cout << "0.Quitter" << std::endl;
    std::cout << "1.Nouvelle partie" << std::endl;
    std::cout << "2.Charger une partie" << std::endl << std::endl;

    std::cout << "Choix :";
    std::cin >> choice;

    switch (this->choice) {
        case 0:
            this->playing = false;
            break;
        case 1:
            createPlayer();
            break;
        case 2:
            loadPlayer();
            break;
        default:
            break;

    }
}

void Game::mainMenu()
{
    int up = this->player.levelUp();
    if (up > 0) {
        const char *x = (up > 1) ? "x" : "";
        std::cout << "Vous avez gagnez " << up << " niveau" << x << std::endl << std::endl;
    }

    std::cout << "MENU PRINCIPAL" << std::endl;
    std::cout << "0.Quitter" << std::endl;
    std::cout << "1.Personnage" << std::endl;
    std::cout << "2.Sauvegarder" << std::endl;
    std::cout << "3.Gain exp" << std::endl;
    std::cout << "4.Use stat points" << std::endl;

    std::cout << std::endl << "Choix :";
    std::cin >> this->choice;

    switch (this->choice) {
        case 0:
            this->playing = false;
            break;
        case 1:
            this->player.print();
            break;
        case 2:
            savePlayer();
            break;
        case 3:
            this->player.gainExp(200);
            break;
        case 4:
            if (this->player.getStatPoints() <= 0)
                std::cout << "Vous n'avez pas de stat points" << std::endl << std::endl;
            else
                statMenu();
            break;
        default:
            break;
    }
}

void Game::statMenu()
{
    int tmpVit = this->player.getVitality(), tmpEne = this->player.getEnergy();
    bool choose = true;
    while (choose && this->player.getStatPoints() > 0) {
        const char* s = (this->player.getStatPoints() > 1) ? "s" : "";
        std::cout << "Vous avez " << this->player.getStatPoints() << " point" << s << " de statistiques" << std::endl << std::endl;

        std::cout << "MENU DE STATISTIQUES" << std::endl;
        std::cout << "0.Retour" << std::endl;
        std::cout << "1.Force" << std::endl;
        std::cout << "2.Robustesse" << std::endl;
        std::cout << "3.Intelligence" << std::endl;
        std::cout << "4.Esprit" << std::endl;
        std::cout << "5.Agilité" << std::endl;
        std::cout << "6.Chance" << std::endl;

        std::cout << std::endl << "Choix :";
        std::cin >> this->choice;

        switch (this->choice) {
            case 0:
                choose = false;
                break;
            case 1:
                this->player.gainStrength(1);
                this->player.gainStatPoints(-1);
                break;
            case 2:
                this->player.gainSturdiness(1);
                this->player.gainStatPoints(-1);
                break;
            case 3:
                this->player.gainIntelligence(1);
                this->player.gainStatPoints(-1);
                break;
            case 4:
                this->player.gainSpirit(1);
                this->player.gainStatPoints(-1);
                break;
            case 5:
                this->player.gainAgility(1);
                this->player.gainStatPoints(-1);
                break;
            case 6:
                this->player.gainLuck(1);
                this->player.gainStatPoints(-1);
                break;
            default:
                break;
        }
    }
    this->player.setSStats(this->player.getStats().getSStats());
    this->player.gainHp(this->player.getVitality() - tmpVit);
    this->player.gainStamina(this->player.getEnergy() - tmpEne);
}

void Game::combatMenu()
{

}

void Game::shopMenu()
{

}

void Game::createPlayer()
{
    std::string name;

    std::cout << "Quel est le nom de votre héros" << std::endl << ":";
    std::cin >> name;

    this->player.initialize(name);
}

void Game::savePlayer()
{
    this->player.save(this->savefile);
}

void Game::loadPlayer()
{
    Player player(savefile);
    this->player = player;
}
