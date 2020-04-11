#include "../include/Character.h"

Character::Character()
{
    this->name = "-";
    this->level = 0;
}

Character::~Character()
{

}

void Character::print()
{
    std::cout << this->name << "\t" << this->level << std::endl;
    std::cout << "Force :" << getStrength() << std::endl;
    std::cout << "Robustesse :" << getStrudiness() << std::endl;
    std::cout << "Intelligence :" << getIntelligence() << std::endl;
    std::cout << "Esprit :" << getSpirit() << std::endl;
    std::cout << "Agilité :" << getAgility() << std::endl;
    std::cout << "Chance :" << getLuck() << std::endl << std::endl;

}
