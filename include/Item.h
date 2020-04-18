#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include "RARITY.h"

class Item {
protected:
    std::string name;
    std::string desc;
    int price;
    RARITY rarity;


public:
    Item(std::string name = "-", int price = 0, RARITY rarity = RARITY::COMMON, std::string desc = "-");
    Item(const Item& item);
    ~Item();

    //Functions
    std::string toString();

    // Accessors
    inline std::string getName() const { return this->name; }
    inline std::string getDesc() const { return this->desc; }
    inline int getPrice() const { return this->price; }
    inline RARITY getRarity() const { return this->rarity; }

};

#endif
