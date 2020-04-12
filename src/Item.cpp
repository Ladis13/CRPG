#include "../include/Item.h"

static unsigned long nid = 0;

Item::Item(std::string name, std::string desc, int price, RARITY rarity)
{
    this->id = nid++;
    this->name = name;
    this->desc = desc;
    this->price = price;
    this->rarity = rarity;
}

Item::~Item()
{

}

std::string Item::toString()
{
    std::string ret = "";

    ret += std::to_string(this->id) + "";
    ret += this->name + "\n";
    ret += this->desc;
    ret += std::to_string(this->price) + " " + std::to_string(this->rarity);

    return ret;
}
