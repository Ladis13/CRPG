#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "RARITY.h"

class Item {
protected:
    unsigned long id;

    std::string name;
    std::string desc;
    int price;
    RARITY rarity;


public:
    Item(std::string name = "-", std::string desc = "-", int price = 0, RARITY rarity = RARITY::COMMON);
    ~Item();

    //Functions
    std::string toString();

};


#endif
