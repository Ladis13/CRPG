#include "../include/Weapon.h"

Weapon::Weapon(int damageMin, int damageMax, std::string name, int price, RARITY rarity, std::string desc)
{
    this->damageMin = damageMin;
    this->damageMax = damageMax;
    this->name = name;
    this->desc = desc;
    this->price = price;
    this->rarity = rarity;
}

Weapon::~Weapon()
{
}

std::string Weapon::toString()
{
    std::string ret = "";

    ret += "Nom : " + this->name +
    "\nDesc :" + this->desc +
    "\nDommages : " + std::to_string(this->damageMin) +
    "-" + std::to_string(this->damageMax) + 
    "\nPrix :" + std::to_string(this->price) +
    "\tRareté :" + std::to_string(this->rarity);

    return ret;
}
