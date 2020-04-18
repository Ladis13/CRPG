#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item {
private :
    int damageMin;
    int damageMax;

public :
    Weapon(int damageMin = 0, int damageMax = 0, std::string name = "-", int price = 0, RARITY rarity = RARITY::COMMON, std::string desc = "-");
    ~Weapon();

    //Functions
    std::string toString();
};

#endif
