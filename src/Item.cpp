#include "../include/Item.h"

Item::Item(std::string name, int price, RARITY rarity, std::string desc)
{
    this->name = name;
    this->desc = desc;
    this->price = price;
    this->rarity = rarity;
}

Item::Item(const Item& item)
{
    this->name = item.getName();
    this->desc = item.getDesc();
    this->price = item.getPrice();
    this->rarity = item.getRarity();
}

Item::~Item()
{

}

std::string Item::toString()
{
    std::string ret = "";

    ret += "Nom : " + this->name +
    "\nDesc :" + this->desc +
    "\nPrix :" + std::to_string(this->price) +
    "\tRareté :" + std::to_string(this->rarity);

    return ret;
}
