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
    this->sstats = this->stats.getSStats(this->level);
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

    this->sstats = stats.getSStats(this->level);

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

void Player::operator= (Player& player)
{
    this->name = player.getName();

    this->level = player.getLevel();
    this->stats = player.getStats();
    this->sstats = stats.getSStats(this->level);

    this->hp = player.getHp();
    this->stamina = player.getStamina();
    this->magic = player.getMagic();

    this->exp = player.getExp();
    this->expNext = calculExpNext();
    this->gold = player.getGold();
    this->statPoints = player.getStatPoints();

    this->inventory = Inventory(player.getInventory());
}

void Player::initialize(std::string name)
{
    this->name = name;
    this->level = 1;
    this->stats = Stats(5, 5, 5, 5, 5, 5);
    this->sstats = this->stats.getSStats(this->level);
    this->hp = getVitality();
    this->stamina = getEnergy();
    this->exp = 0;
    this->expNext = round(
        (11 * this->level * M_PI) + (3 * this->level * this->level) + 12);
    this->gold = 5;
    this->statPoints = 0;
}

void Player::save(std::string savefile)
{
    std::fstream fs;
    fs.open(savefile);

    fs << this->name << std::endl
    << this->level << std::endl
    << getStrength() << std::endl
    << getSturdiness() << std::endl
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

int Player::levelUp()
{
    int up = 0;
    while (this->exp >= this->expNext) {
        this->level++;
        this->statPoints += 2;
        this->exp -= this->expNext;
        this->expNext = calculExpNext();
        up++;
    }
    return up;

}

int Player::calculExpNext()
{
    return round(
        (11 * this->level * M_PI) +
        (3 * this->level * this->level) + 12);
}

void Player::print()
{
    std::cout << "======\tFICHE DE PERSONNAGE\n";
    std::cout << "=\n";
    std::cout << "=\tNiv : " << this->level << std::endl;
    std::cout << "=\tNom : " << this->name <<
    "\t\t\t\tExpérience : " << this->exp << "/" << this->expNext << "\n";
    std::cout << "=\tVie : " << this->hp << "/" << this->getVitality() <<
    "\t\tÉnergie : " << this->stamina << "/" << getEnergy() <<
    "\t\tMagie : " << this->magic << "/" << getLimit() << "\n";
    std::cout << "=\n";
    std::cout << "=-----\tSTATISTIQUES\n";
    std::cout << "=\n";
    std::cout << "=\tForce : " << getStrength() <<
    "\t\tRobustesse : " << getSturdiness() << "\n";
    std::cout << "=\tIntelligence : " << getIntelligence() <<
    "\tEsprit : " << getSpirit() << "\n";
    std::cout << "=\tAgilité : " << getAgility() <<
    "\t\tChance : " << getLuck() << "\n";
    std::cout << "=\n";
    std::cout << "=\tPuissance : " << getPower() <<
    "\t\tResistance : " << getResistance() << "\n";
    std::cout << "=\tPerception : " << getPerception() <<
    "\t\tEsquive : " << getDodge() << "\n";
    std::cout << "=\n";
}

std::string Player::toString()
{
    std::string ret = toString();

    ret += this->gold + "\n";
    ret += this->statPoints + "\n";

    return ret;
}
