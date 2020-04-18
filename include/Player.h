#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Inventory.h"

class Player : public Character {
private:
    int exp;
    int expNext;
    int gold;
    int statPoints;

    Inventory inventory;

public:
    // Constructors
    Player();
    Player(Stats stats);
    Player(std::string infile);

    // Desctructor
    ~Player();

    // Operators
    void operator= (Player& player);

    // Functions
    void initialize(std::string name);
    void save(std::string savefile);

    int levelUp();
    int calculExpNext();

    void print();
    std::string toString();

    inline void printInv() { this->inventory.print(); }

    //Accessors
    inline int getExp() const { return this->exp; }
    inline int getExpNext() const { return this->expNext; }
    inline int getGold() const { return this->gold; }
    inline int getStatPoints() const { return this->statPoints; }

    inline Inventory& getInventory(){ return this->inventory; }
    inline Item getItem(int index) { return *this->inventory.getItem(index);}
    inline unsigned getInventorySize() { return this->inventory.getInventorySize(); }

    //Modifiers
    inline void gainExp(int n) { this->exp += n; }
    inline void gainGold(int n) { this->gold += n; }
    inline void gainStatPoints(int n) { this->statPoints += n; }

    inline void addItem(Item *item) { this->inventory.addItem(item); }

};

#endif
