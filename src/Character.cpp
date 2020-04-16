#include "../include/Character.h"

Character::Character()
{
    this->name = "-";
    this->level = 0;
    this->hp = 0;
    this->stamina = 0;
    this->magic = 0;
}

Character::Character(const Character& character)
{
    this->name = character.getName();
    this->level = character.getLevel();
    this->stats = character.getStats();
    this->sstats = this->stats.getSStats();
    this->hp = character.getHp();
    this->stamina = character.getStamina();
    this->magic = character.getMagic();
}

Character::~Character()
{

}

void Character::initialize(std::string name)
{
    this->name = name;
    this->level = 1;
    this->stats = Stats(10, 10, 10, 10, 10, 10);
    this->sstats = this->stats.getSStats();
    this->hp = getVitality();
    this->stamina = getEnergy();
    this->magic = 0;
}

unsigned Character::takeDamage(unsigned damage)
{
    unsigned realDmg = damage;
    this->hp -= damage;

    if(this->hp < 0) {
        realDmg -= this->hp;
        this->hp = 0;
    }

    return realDmg;
}

void Character::print()
{
    std::cout << this->name << "\t" << this->level << std::endl;
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
    std::cout << "Ténacité :\t" << getTenacity() << std::endl;
    std::cout << "Volonté :\t" << getWill() << std::endl;
    std::cout << "Puissance :\t" << getPower() << std::endl;
    std::cout << "Résistance :\t" << getResistance() << std::endl;
    std::cout << "Perception :\t" << getPerception() << std::endl;
    std::cout << "Maîtrise :\t" << getMastery() << std::endl;
    std::cout << "Esquive :\t" << getDodge() << std::endl << std::endl;

}

std::string Character::toString()
{
    std::string ret = "";

    ret += this->name + "\n";
    ret += this->level + "\n";
    ret += getStrength() + "\n";
    ret += getStrudiness() + "\n";
    ret += getIntelligence() + "\n";
    ret += getSpirit() + "\n";
    ret += getAgility() + "\n";
    ret += getLuck() + "\n";
    ret += this->hp + "\n";
    ret += this->stamina + "\n";
    ret += this->magic + "\n";

    return ret;
}
