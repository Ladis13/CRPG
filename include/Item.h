#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
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

    // Accessors
    inline unsigned long getId() const { return this->id; }
    inline std::string getName() const { return this->name; }
    inline std::string getDesc() const { return this->desc; }
    inline int getPrice() const { return this->price; }
    inline RARITY getRarity() const { return this->rarity; }

};

#endif
