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

    bool valid = false;
    while(!valid) {
        valid = true;
        std::cout << "Choix :";
        std::cin >> this->choice;

        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Choix non reconnu" << std::endl << std::endl;

            std::cout << "Choix :";
            std::cin >> this->choice;
        }

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
            std::cout << "Choix non reconnu" << std::endl << std::endl;
            valid = false;
        }
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
    std::cout << "3.Se reposer" << std::endl;
    std::cout << "4.Use stat points" << std::endl;
    std::cout << "5.Combat" << std::endl << std::endl;

    std::cout << "Choix :";
    std::cin >> this->choice;

    while (std::cin.fail() || this->choice < 0 || this->choice > 5) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Choix non reconnu" << std::endl << std::endl;

        std::cout << "Choix :";
        std::cin >> this->choice;
    }

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
            if (this->player.getHp() == this->player.getVitality())
                std::cout << "Vous n'êtes même pas blessé, un peu de courage !" << std::endl << std::endl;
            else
                restMenu();
            break;
        case 4:
            if (this->player.getStatPoints() <= 0)
                std::cout << "Vous n'avez pas de stat points" << std::endl << std::endl;
            else
                statMenu();
            break;
        case 5:
            combatMenu();
            break;
    }

    if (this->player.isDead())
        this->playing = false;
}

void Game::statMenu()
{
    int tmpVit = this->player.getVitality();
    int tmpEne = this->player.getEnergy();

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
        std::cout << "6.Chance" << std::endl << std::endl;

        std::cout << "Choix :";
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
                std::cout << "Choix non reconnu" << std::endl << std::endl;
        }
    }
    this->player.setSStats(this->player.getStats().getSStats());
    this->player.gainHp(this->player.getVitality() - tmpVit);
    this->player.gainStamina(this->player.getEnergy() - tmpEne);
}

void Game::restMenu()
{
    std::cout << "MENU DE REPOS" << std::endl;
    std::cout << "0.Retour" << std::endl;
    std::cout << "1.Dormir dans la nature" << std::endl;
    std::cout << "2.Dormir à l'auberge (10 po)" << std::endl << std::endl;

    std::cout << "Choix :";
    std::cin >> this->choice;

    if (this->choice == 2 && this->player.getGold() < 10) {
        std::cout << "Vous n'avez pas assez de pièces d'or pour cela !" << std::endl << std::endl;
        this->choice = 0;
    }

    while (std::cin.fail() || this->choice < 0 || this->choice > 2) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Choix non reconnu" << std::endl << std::endl;

        std::cout << "Choix :";
        std::cin >> this->choice;
    }

    switch (this->choice) {
        case 0:
            break;
        case 1:
            std::cout << "Vous dormez à la belle étoile, vous régénérez " << this->player.getVitality() / 2 << " points de vie !" << std::endl;
            this->player.gainHp(this->player.getVitality() / 2);
            if (this->rand.gen(1, 3) == 1) {
                std::cout << "Vous êtes aggressé pendant votre sommeil !" << std::endl << std::endl;
                combatMenu(false);
            }
            break;
        case 2:
            std::cout << "Vous dormez à l'auberge, vous récupérez tous vos points de vie !" << std::endl << std::endl;
            this->player.gainHp(this->player.getVitality());
            this->player.gainGold(-10);
            break;

    }
}

void Game::combatMenu(bool pstart)
{
    DArr<Enemy> enemies;
    int nbEnemy = rand.gen(1, 3);

    std::string eName = "";
    unsigned eLevel;
    for (int i = 0; i < nbEnemy; i++) {
        eName += "Enemy ";
        eName += std::to_string(i + 1);
        eLevel = this->rand.gen(this->player.getLevel() - 1, this->player.getLevel() + 1);

        enemies.push(Enemy(eName, eLevel));

        eName = "";
    }

    bool escaped = false;
    bool pDefeated = false;
    bool eDefeated = false;

    bool playerTurn = pstart;
    bool protect = false;

    while (!escaped && !pDefeated && !eDefeated) {

        if (playerTurn){
            std::cout << "MENU DE COMBAT" << std::endl;
            std::cout << "0.Fuir" << std::endl;
            std::cout << "1.Attaquer" << std::endl;
            std::cout << "2.Se protéger" << std::endl;
            std::cout << "3.Personnage" << std::endl << std::endl;

            std::cout << "Choix :";
            std::cin >> this->choice;

            while (std::cin.fail() || this->choice < 0 || this->choice > 3) {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Choix non reconnu" << std::endl << std::endl;

                std::cout << "Choix :";
                std::cin >> this->choice;
            }

            switch (this->choice) {
            case 0:
                escaped = true;
                break;
            case 1:
                std::cout << "CHOIX DE L'ENNEMI" << std::endl;
                std::cout << "0.Retour" << std::endl;

                for (unsigned i = 0; i < enemies.size(); i++) {
                    if (!enemies[i].isDead())
                        std::cout << i+1 << "." << enemies[i].getName() << "\t" << enemies[i].getHp() << "/" << enemies[i].getVitality() << std::endl;
                    else
                        std::cout << enemies[i].getName() << "\tMort" << std::endl;
                }

                std::cout << std::endl;

                std::cout << "Choix :";
                std::cin >> this->choice;

                if (this->choice != 0) {
                    while (std::cin.fail() || this->choice < 0 || this->choice > (int) enemies.size() || enemies[this->choice - 1].isDead()) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Choix non reconnu" << std::endl << std::endl;

                        std::cout << "Choix :";
                        std::cin >> this->choice;
                    }
                }

                if (this->choice != 0) {
                    this->choice--;
                    playerTurn = false;

                    int playerDamage = this->player.getPower();
                    int enemyDefence = enemies[this->choice].getResistance();
                    int playerPerception = this->player.getPerception();
                    int enemyDodge = enemies[this->choice].getDodge();

                    int playerLuck = this->player.getLuck();

                    int damage = 0;

                    if (this->rand.gen(1, 100) <= enemyDodge) {
                        std::cout << "Esquivé !\t";
                    }
                    else if (this->rand.gen(1, 475) <= (100 - playerPerception)) {
                        std::cout << "Raté !\t";
                    }
                    else {
                        damage += playerDamage;
                        damage -= enemyDefence;

                        if (this->rand.gen(1, 100) < playerLuck) {
                            std::cout << "Critique !";
                            damage *= 2;
                        }

                        if (damage < 0) {
                            damage = 0;
                        }
                    }

                    std::cout << "Vous avez infligé " << enemies[this->choice].takeDamage(damage) <<  " dommages à " << enemies[this->choice].getName() << std::endl << std::endl;
                }
                break;
            case 2:
                std::cout << "Vous vous protéger !" << std::endl << std::endl;
                protect = true;
                playerTurn = false;
                break;
            case 3:
                this->player.print();
            }
        } else {
            std::cout << "Enemy turn" << std::endl;

            int enemyDamage;
            int playerResistance = this->player.getResistance();
            int enemyPercption;
            int playerDodge = this->player.getDodge();
            int enemyLuck;

            if (protect)
                playerResistance *= 2;

            int damage = 0;

            for (unsigned i = 0; i < enemies.size(); i++) {
                if (!enemies[i].isDead()) {
                    enemyDamage = enemies[i].getPower();
                    enemyPercption = enemies[i].getPerception();
                    enemyLuck = enemies[i].getLuck();

                    // std::cout << "DEBUG : " << enemyDamage << " - " << playerResistance << std::endl;

                    if (this->rand.gen(1, 100) <= playerDodge) {
                        std::cout << "Esquivé !\t";
                    }
                    else if (this->rand.gen(1, 475) <= (100 - enemyPercption)) {
                        std::cout << "Raté !\t";
                    }
                    else {
                        damage += enemyDamage;
                        damage -= playerResistance;

                        if (this->rand.gen(1, 100) < enemyLuck) {
                            std::cout << "Critique !";
                            damage *= 2;
                        }

                        if (damage < 0) {
                            damage = 0;
                        }
                    }
                    std::cout << enemies[i].getName() << " vous a infligez " << this->player.takeDamage(damage) << " dommages !" << std::endl << std::endl;
                damage = 0;
                }
            }

            playerTurn = true;
        }

        if (this->player.isDead()) {
            pDefeated = true;
        }

        eDefeated = enemies[0].isDead();
        for (unsigned i = 1; i < enemies.size(); i++) {
            eDefeated = eDefeated && enemies[i].isDead();
        }
    }

    if (pDefeated)
        std::cout << "Vous êtes mort !" << std::endl << std::endl;

    if (eDefeated) {
        std::cout << "Vous avez triomphé de vos ennemis, " << std::endl << std::endl;

        int exp = 0;
        int gold = 0;
        for (size_t i = 0; i < enemies.size(); i++) {
            int eLevel = enemies[i].getLevel();
            exp += this->rand.gen(4 * (eLevel + 1), 6 * (eLevel + 1));
            gold += this->rand.gen(eLevel + 3, 2*eLevel + 3);
        }
        std::cout << "vous avez gagné " << exp << " points d'expériences et " << gold << " pièces d'or !" << std::endl << std::endl;
        this->player.gainExp(exp);
        this->player.gainGold(gold);
    }

    if (escaped)
        std::cout << "Vous vous êtes enfuit !" << std::endl << std::endl;
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
