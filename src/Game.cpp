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

// Item i1("Sympa", 0, RARITY::UNCOMMON, "Pas à l'envers stp :)");
// Item i2("Enculer", 0, RARITY::LEGENDARY, "Bein dans le cul ...");
// Weapon w(1, 1000, "Dieu", 1, RARITY::EPIC, "Jesus de Nazareth !");
// this->player.addItem(&i1);
// this->player.addItem(&i2);
// this->player.addItem(&w);
// this->player.printInv();

void Game::initMenu()
{
    std::cout << "======\tBIENVENUE DANS CRPG" << std::endl;
    std::cout << "=\t" << std::endl;
    std::cout << "=\t0.Quitter" << std::endl;
    std::cout << "=\t1.Nouvelle partie" << std::endl;
    std::cout << "=\t2.Charger une partie" << std::endl;
    std::cout << "=\t" << std::endl;

    std::cout << "=\tChoix : ";
    std::cin >> this->choice;

    while (std::cin.fail() || this->choice < 0 || this->choice > 2) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "=\tERREUR : Choix non reconnu." << std::endl;
        std::cout << "=\t" << std::endl;

        std::cout << "=\tChoix : ";
        std::cin >> this->choice;
    }
    std::cout << "=\t" << std::endl;

    switch (this->choice) {
        case 0: // QUITTER LE PROGRAMME
            this->playing = false;
            break;
        case 1: // CREER UN NOUVEAU JOUEUR
            createPlayer();
            break;
        case 2: // CHARGER UN JOUEUR
            loadPlayer();
            break;
    }
}

void Game::mainMenu()
{
    std::cout << "======\tMENU PRINCIPAL" << std::endl;
    std::cout << "=\t" << std::endl;

    int up;
    if ((up = this->player.levelUp()) > 0) {
        const char *x = (up > 1) ? "x" : "";
        std::cout << "=\tVous avez gagnez " << up << " niveau" << x << " !" << std::endl;
        std::cout << "=\t" << std::endl;
    }

    std::cout << "=\t0.Quitter" << std::endl;
    std::cout << "=\t1.Personnage" << std::endl;
    std::cout << "=\t2.Sauvegarder" << std::endl;
    std::cout << "=\t3.Se reposer" << std::endl;
    std::cout << "=\t4.Use stat points" << std::endl;
    std::cout << "=\t5.Combat" << std::endl;
    std::cout << "=\t6.Expérience" << std::endl;
    std::cout << "=\t" << std::endl;

    std::cout << "=\tChoix : ";
    std::cin >> this->choice;

    while (std::cin.fail() || this->choice < 0 || this->choice > 6) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "=\tERREUR : Choix non reconnu." << std::endl;
        std::cout << "=\t" << std::endl;

        std::cout << "=\tChoix : ";
        std::cin >> this->choice;
    }
    std::cout << "=\t" << std::endl;

    switch (this->choice) {
        case 0: // QUITTER LE PROGRAMME
            this->playing = false;
            break;
        case 1: // AFFICHER LE PERSONNAGE
            this->player.print();
            break;
        case 2: // SAUVEGARDER LE PERSONNAGE
            savePlayer();
            break;
        case 3: // UTILISER LE MENU DE REPOS
            if (this->player.getHp() == this->player.getVitality()) {
                std::cout << "=\tVous n'êtes pas bléssé et décidez de repartir." << std::endl;
                std::cout << "=\t" << std::endl;
            }
            else
                restMenu();
            break;
        case 4: // UTILISER LE MENU D'AMELIORATION
            if (this->player.getStatPoints() <= 0) {
                std::cout << "=\tVous n'avez pas de points à repartir." << std::endl;
                std::cout << "=\t" << std::endl;
            }
            else
                statMenu();
            break;
        case 5: // ENTRER DANS UN COMBAT
            combatMenu();
            break;
        case 6: // GAGNER DE L'EXPERIENCE
            this->player.gainExp(200);
            break;
    }

    if (this->player.isDead()) {
        gameOverMenu();
    }
}

void Game::statMenu()
{
    int tmpVit = this->player.getVitality();
    int tmpEne = this->player.getEnergy();

    bool choose = true;
    while (choose && this->player.getStatPoints() > 0) {

        std::cout << "======\tMENU DE STATISTIQUES" << std::endl;
        std::cout << "=\t" << std::endl;

        const char* s = (this->player.getStatPoints() > 1) ? "s" : "";
        std::cout << "=\tVous avez " << this->player.getStatPoints() << " point" << s << " de statistiques !" << std::endl;
        std::cout << "=\t" << std::endl;

        std::cout << "=\t0.Retour" << std::endl;
        std::cout << "=\t1.Force" << std::endl;
        std::cout << "=\t2.Robustesse" << std::endl;
        std::cout << "=\t3.Intelligence" << std::endl;
        std::cout << "=\t4.Esprit" << std::endl;
        std::cout << "=\t5.Agilité" << std::endl;
        std::cout << "=\t6.Chance" << std::endl;
        std::cout << "=\t" << std::endl;

        std::cout << "=\tChoix :";
        std::cin >> this->choice;

        while (std::cin.fail() || this->choice < 0 || this->choice > 6) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "=\tERREUR : Choix non reconnu." << std::endl;
            std::cout << "=\t" << std::endl;

            std::cout << "=\tChoix : ";
            std::cin >> this->choice;
        }
        std::cout << "=\t" << std::endl;

        switch (this->choice) {
            case 0: // QUITTER LE MENU
                choose = false;
                break;
            case 1: // AMELIORE LA FORCE
                std::cout << "=\tVotre force a augmenté !" << std::endl;
                std::cout << "=\t" << std::endl;
                this->player.gainStrength(1);
                this->player.gainStatPoints(-1);
                break;
            case 2: // AMELIORE LA ROBUSTESSE
                std::cout << "=\tVous vous sentez plus robuste !" << std::endl;
                std::cout << "=\t" << std::endl;
                this->player.gainSturdiness(1);
                this->player.gainStatPoints(-1);
                break;
            case 3: // AMELIORE L'INTELLIGENCE
                std::cout << "=\tVous êtes plus intelligent !" << std::endl;
                std::cout << "=\t" << std::endl;
                this->player.gainIntelligence(1);
                this->player.gainStatPoints(-1);
                break;
            case 4: // AMELIORE L'ESPRIT
                std::cout << "=\tVotre esprit est plus puissant !" << std::endl;
                std::cout << "=\t" << std::endl;
                this->player.gainSpirit(1);
                this->player.gainStatPoints(-1);
                break;
            case 5: // AMELIORE L'AGILITE
                std::cout << "=\tVous êtes plus agile !" << std::endl;
                std::cout << "=\t" << std::endl;
                this->player.gainAgility(1);
                this->player.gainStatPoints(-1);
                break;
            case 6: // AMELIORE LA CHANCE
                std::cout << "=\tVotre chance s'améliore !" << std::endl;
                std::cout << "=\t" << std::endl;
                this->player.gainLuck(1);
                this->player.gainStatPoints(-1);
                break;
        }
    }

    this->player.setSStats(this->player.getStats().getSStats(this->player.getLevel()));
    this->player.gainHp(this->player.getVitality() - tmpVit);
    this->player.gainStamina(this->player.getEnergy() - tmpEne);
}

void Game::restMenu()
{
    std::cout << "======\tMENU DE REPOS" << std::endl;
    std::cout << "=\t" << std::endl;
    std::cout << "=\t0.Retour" << std::endl;
    std::cout << "=\t1.Dormir dans la nature" << std::endl;
    std::cout << "=\t2.Dormir à l'auberge (10 po)" << std::endl;
    std::cout << "=\t" << std::endl;

    std::cout << "=\tChoix : ";
    std::cin >> this->choice;

    if (this->choice == 2 && this->player.getGold() < 10) {
        std::cout << "=\t" << std::endl;
        std::cout << "=\tVous n'avez pas assez de pièces d'or, revenez quand vous pourrez payer !" << std::endl;
        std::cout << "=\t" << std::endl;
        this->choice = 0;
    }

    while (std::cin.fail() || this->choice < 0 || this->choice > 2) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "=\tERREUR : Choix non reconnu." << std::endl;
        std::cout << "=\t" << std::endl;

        std::cout << "=\tChoix : ";
        std::cin >> this->choice;
    }
    std::cout << "=\t" << std::endl;

    switch (this->choice) {
        case 0: // QUITTER LE MENU
            break;
        case 1: // SE REPOSER DANS LA NATURE
            std::cout << "=\tVous dormez à la belle étoile, vous régénérez " << this->player.getVitality() / 2 << " points de vie !" << std::endl;
            std::cout << "=\t" << std::endl;
            this->player.gainHp(this->player.getVitality() / 2);

            if (this->rand.gen(1, 3) == 1) {
                std::cout << "=\tVous êtes aggressé pendant votre sommeil !" << std::endl;
                std::cout << "=\t" << std::endl;
                combatMenu(false);
            }
            break;
        case 2: // SE REPOSER A L'AUBERGE
            std::cout << "=\tVous payez une chambre à l'auberge.\n=\tVous vous sentez complétement reposé !" << std::endl;
            std::cout << "=\t" << std::endl;

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
        eName += "Bandit ";
        eName += std::to_string(i + 1);
        eLevel = this->rand.gen(
            (this->player.getLevel() - 1) > 0 ? this->player.getLevel() - 1 : 1
            , this->player.getLevel() + 1);

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
            std::cout << "======\tMENU DE COMBAT" << std::endl;
            std::cout << "=\t" << std::endl;
            std::cout << "=\t0.Fuir" << std::endl;
            std::cout << "=\t1.Attaquer" << std::endl;
            std::cout << "=\t2.Se protéger" << std::endl;
            std::cout << "=\t3.Personnage" << std::endl;
            std::cout << "=\t" << std::endl;

            std::cout << "=\tChoix : ";
            std::cin >> this->choice;

            while (std::cin.fail() || this->choice < 0 || this->choice > 3) {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "=\tERREUR : Choix non reconnu." << std::endl;
                std::cout << "=\t" << std::endl;

                std::cout << "=\tChoix : ";
                std::cin >> this->choice;
            }
            std::cout << "=\t" << std::endl;

            switch (this->choice) {
            case 0:
                escaped = true;
                break;
            case 1:
                std::cout << "=-----\tCHOIX DE L'ENNEMI" << std::endl;
                std::cout << "=\t" << std::endl;
                std::cout << "=\t0.Retour" << std::endl;

                for (unsigned i = 0; i < enemies.size(); i++) {
                    if (!enemies[i].isDead())
                        enemies[i].print();
                    else
                        std::cout << "=\t" << enemies[i].getName() << "\tMort" << std::endl;
                }
                std::cout << "=\t" << std::endl;

                std::cout << "=\tChoix : ";
                std::cin >> this->choice;

                if (this->choice != 0) {
                    while (std::cin.fail() || this->choice < 0 || this->choice > (int) enemies.size() || enemies[this->choice - 1].isDead()) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "=\tERREUR : Choix non reconnu." << std::endl;
                        std::cout << "=\t" << std::endl;

                        std::cout << "=\tChoix : ";
                        std::cin >> this->choice;
                    }
                    std::cout << "=\t" << std::endl;

                    this->choice--;
                    playerTurn = false;

                    int playerDamage = this->player.getPower();
                    int enemyDefence = enemies[this->choice].getResistance();
                    int playerPerception = this->player.getPerception();
                    int enemyDodge = enemies[this->choice].getDodge();

                    int playerLuck = this->player.getLuck();

                    int damage = 0;

                    std::cout << "=\t";

                    if (this->rand.gen(1, 100) <= enemyDodge) {
                        std::cout << "Coup esquivé ! ";
                    }
                    else if (this->rand.gen(1, 975) <= (100 - playerPerception)) {
                        std::cout << "Coup raté ! ";
                    }
                    else {
                        damage += playerDamage;
                        damage -= enemyDefence;

                        if (this->rand.gen(1, 100) < playerLuck) {
                            std::cout << "Coup critique ! ";
                            damage *= 2;
                        }

                        if (damage < 0) {
                            damage = 0;
                        }
                    }

                    std::cout << "Vous avez infligé " << enemies[this->choice].takeDamage(damage) <<  " dommages à " << enemies[this->choice].getName() << std::endl;
                    std::cout << "=\t" << std::endl;
                }

                break;
            case 2:
                std::cout << "=\tVous vous protéger !" << std::endl;
                std::cout << "=\t" << std::endl;
                protect = true;
                playerTurn = false;
                break;
            case 3:
                this->player.print();
            }
        } else {
            std::cout << "=-----\tTour des ennemis" << std::endl;
            std::cout << "=\t" << std::endl;

            int enemyDamage;
            int playerResistance = this->player.getResistance();
            int enemyPercption;
            int playerDodge = this->player.getDodge();
            int enemyLuck;

            if (protect)
                playerResistance *= 2;

            int damage = 0;
            int total = 0;

            for (unsigned i = 0; i < enemies.size(); i++) {
                if (!enemies[i].isDead()) {
                    enemyDamage = enemies[i].getPower();
                    enemyPercption = enemies[i].getPerception();
                    enemyLuck = enemies[i].getLuck();

                    std::cout << "=\t";

                    if (this->rand.gen(1, 100) <= playerDodge) {
                        std::cout << "Coup esquivé ! ";
                    }
                    else if (this->rand.gen(1, 975) <= (100 - enemyPercption)) {
                        std::cout << "Coup raté ! ";
                    }
                    else {
                        damage += enemyDamage;
                        damage -= playerResistance;

                        if (this->rand.gen(1, 100) < enemyLuck) {
                            std::cout << "Coup critique ! ";
                            damage *= 2;
                        }

                        if (damage < 0) {
                            damage = 0;
                        }
                    }
                    std::cout << enemies[i].getName() << " vous a infligez " << this->player.takeDamage(damage) << " dommages !" << std::endl;
                    total += damage;
                    damage = 0;
                }
            }

            if (enemies.size() > 1) {
                std::cout << "=\t" << std::endl;
                std::cout << "=\tTotal de dommages : " << total << " points de  vie !" << std::endl;
            }
            
            std::cout << "=\t" << std::endl;

            playerTurn = true;
            protect = false;
        }

        if (this->player.isDead()) {
            pDefeated = true;
        }

        eDefeated = enemies[0].isDead();
        for (unsigned i = 1; i < enemies.size(); i++) {
            eDefeated = eDefeated && enemies[i].isDead();
        }
    }

    if (eDefeated) {
        std::cout << "=\tVous avez triomphé de vos ennemis." << std::endl;
        std::cout << "=\t" << std::endl;

        int exp = 0;
        int gold = 0;
        for (size_t i = 0; i < enemies.size(); i++) {
            int eLevel = enemies[i].getLevel();
            exp += this->rand.lootExp(eLevel);
            gold += this->rand.lootGold(eLevel);
        }
        std::cout << "=\tVous avez gagné " << exp << " points d'expériences." << std::endl;
        std::cout << "=\tVous avez gagné " << gold << " pièces d'or ." << std::endl;
        std::cout << "=\t" << std::endl;
        this->player.gainExp(exp);
        this->player.gainGold(gold);
    }

    if (escaped) {
        std::cout << "=\tVous vous êtes enfuit !" << std::endl;
        std::cout << "=\t" << std::endl;
    }
}

void Game::shopMenu()
{

}

void Game::gameOverMenu()
{
    std::cout << "======\tGAME OVER" << std::endl;
    std::cout << "=\t" << std::endl;
    std::cout << "=\t0.Quitter" << std::endl;
    std::cout << "=\t1.Utiliser la sauvegarde" << std::endl;
    std::cout << "=\t2.Créer un nouveau personnage" << std::endl;
    std::cout << "=\t" << std::endl;

    std::cout << "=\tChoix : ";
    std::cin >> this->choice;

    while (std::cin.fail() || this->choice < 0 || this->choice > 2) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "=\tERREUR : Choix non reconnu." << std::endl;
        std::cout << "=\t" << std::endl;

        std::cout << "=\tChoix : ";
        std::cin >> this->choice;
    }
    std::cout << "=\t" << std::endl;

    switch (this->choice) {
        case 0:
            this->playing = false;
            break;
        case 1:
            loadPlayer();
            break;
        case 2:
            createPlayer();
            break;
    }
}

void Game::createPlayer()
{
    std::string name;

    std::cout << "=\tQuel est le nom de votre héros" << std::endl << "=\tNom : ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "=\t" << std::endl;

    this->player.initialize(name);
}

void Game::savePlayer()
{
    this->player.save(this->savefile);
    std::cout << "=\tSauvegarde de " << this->player.getName() << " réussie !" << std::endl;
    std::cout << "=\t" << std::endl;
}

void Game::loadPlayer()
{
    Player player(this->savefile);
    this->player.~Player();
    this->player = player;
    std::cout << "=\tVous avez charger " << this->player.getName() << "\tNiv :" << this->player.getLevel() << std::endl;
    std::cout << "=\t" << std::endl;
}
