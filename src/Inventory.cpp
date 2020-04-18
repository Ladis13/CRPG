#include "../include/Inventory.h"

Inventory::Inventory()
{
}

Inventory::Inventory(Inventory& inv)
{
    this->inventory = DArr<Item*>();
    for (unsigned i = 0; i < inv.getInventorySize(); i++) {
        this->inventory[i] = inv.getItem(i);
    }
}

Inventory::~Inventory()
{
}

void Inventory::print()
{
    for (unsigned i = 0; i < this->inventory.size(); i++)
        std::cout << "Item " << i << ":\n" << this->inventory[i]->toString() << std::endl;
}
