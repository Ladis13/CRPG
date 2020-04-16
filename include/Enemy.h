#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
private:

public :
    Enemy(std::string name, unsigned level);
    ~Enemy();

    //Functions
    void print();

    //Accessors

    //Modifiers


};

#endif
