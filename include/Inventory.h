#ifndef INVENTORY_H
#define INVENTORY_H

#include "Weapon.h"
#include "DArr.h"
#include <iostream>

class Inventory {
private:
    DArr<Item*> inventory;

public:
    Inventory();
    Inventory( Inventory& inventory);
    ~Inventory();

    //Functions
    void print();

    // Accessors
    inline DArr<Item*> getInventory() const { return this->inventory; }
    inline Item *getItem(int index) { return this->inventory[index]; }
    inline unsigned getInventorySize() { return this->inventory.size(); }

    // Modifiers
    inline void addItem(Item *item) { this->inventory.push(item); }

};

#endif
