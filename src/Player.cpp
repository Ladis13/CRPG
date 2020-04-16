#include "../include/Player.h"

Player::Player()
{
    Character();
    this->exp = 0;
    this->exp = 0;
    this->gold = 0;
    this->statPoints = 0;
}

Player::Player(Stats stats)
{
    this->name = "-";
    this->level = 0;
    this->stats = stats;
    this->sstats = this->stats.getSStats();
    this->hp = 0;
    this->stamina = 0;

    this->exp = 0;
    this->exp = 0;
    this->gold = 0;
    this->statPoints = 0;
}

Player::Player(std::string infile)
{
    std::fstream fs;
    fs.open(infile);

    if (!fs.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier : " << infile << std::endl;
        Player();
    }

    getline(fs, this->name);
    fs >> this->level;

    int tmp;
    fs >> tmp;
    setStrength(tmp);
    fs >> tmp;
    setSturdiness(tmp);
    fs >> tmp;
    setIntelligence(tmp);
    fs >> tmp;
    setSpirit(tmp);
    fs >> tmp;
    setAgility(tmp);
    fs >> tmp;
    setLuck(tmp);

    this->sstats = stats.getSStats();

    fs >> this->hp;
    fs >> this->stamina;
    fs >> this->magic;

    fs >> this->exp;
    this->expNext = round(
        (11 * this->level * M_PI) + (3 * this->level * this->level) + 12);
    fs >> this->gold;
    fs >> this->statPoints;

    fs.close();
}

Player::~Player()
{
}

void Player::initialize(std::string name)
{
    this->name = name;
    this->level = 1;
    this->stats = Stats(10, 10, 10, 10, 10, 10);
    this->sstats = this->stats.getSStats();
    this->hp = getVitality();
    this->stamina = getEnergy();
    this->exp = 0;
    this->expNext = round(
        (11 * this->level * M_PI) + (3 * this->level * this->level) + 12);
    this->gold = 20;
    this->statPoints = 0;
}

int Player::levelUp()
{
    int up = 0;
    while (this->exp >= this->expNext) {
        this->level++;
        this->statPoints += 2;
        this->exp -= this->expNext;
        this->expNext = round(
            (11 * this->level * M_PI) + (3 * this->level * this->level) + 12);
        up++;
    }
    return up;

}

void Player::save(std::string savefile)
{
    std::fstream fs;
    fs.open(savefile);

    fs << this->name << std::endl
    << this->level << std::endl
    << getStrength() << std::endl
    << getStrudiness() << std::endl
    << getIntelligence() << std::endl
    << getSpirit() << std::endl
    << getAgility() << std::endl
    << getLuck() << std::endl
    << this->hp << std::endl
    << this->stamina << std::endl
    << this->magic << std::endl
    << this->exp << std::endl
    << this->gold << std::endl
    << this->statPoints << std::endl;

    fs.close();
}

void Player::print()
{
    std::cout << this->name << "\tNiveau :" << this->level << std::endl;
    std::cout << "Exp :\t" << this->exp << "/" << this->expNext << "\tGold :" << this->gold << std::endl;
    std::cout << "--== Statistiques Primaires ==--" << std::endl;
    std::cout << "Force :\t\t" << getStrength() << std::endl;
    std::cout << "Robustesse :\t" << getStrudiness() << std::endl;
    std::cout << "Intelligence :\t" << getIntelligence() << std::endl;
    std::cout << "Esprit :\t" << getSpirit() << std::endl;
    std::cout << "Agilité :\t" << getAgility() << std::endl;
    std::cout << "Chance :\t" << getLuck() << std::endl << std::endl;

    std::cout << "--== Statistiques Secondaires ==--" << std::endl;
    std::cout << "Vitalité :\t" << this->hp << "/" << getVitality() << std::endl;
    std::cout << "Énergie :\t" << this->stamina << "/" << getEnergy() << std::endl;
    std::cout << "Limite :\t" << this->magic << "/" << getLimit() << std::endl;
    std::cout << "Ténacité :\t" << getTenacity() << std::endl;
    std::cout << "Volonté :\t" << getWill() << std::endl;
    std::cout << "Puissance :\t" << getPower() << std::endl;
    std::cout << "Résistance :\t" << getResistance() << std::endl;
    std::cout << "Perception :\t" << getPerception() << std::endl;
    std::cout << "Maîtrise :\t" << getMastery() << std::endl;
    std::cout << "Esquive :\t" << getDodge() << std::endl << std::endl;
}

std::string Player::toString()
{
    std::string ret = toString();

    ret += this->gold + "\n";
    ret += this->statPoints + "\n";

    return ret;
}
