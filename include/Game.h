#ifndef GAME_H
#define GAME_H

#include "Character.h"

class Game {
private :
    int choice;
    bool playing;

    Character player;

public :
    Game();
    ~Game();

    // Functions
    void mainMenu();

    //Accessors
    inline bool isPlaying() const { return this->playing; }

};

#endif
