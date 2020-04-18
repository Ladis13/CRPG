#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "DArr.h"

class Game {
private :
    int choice;
    bool playing;

    Player player;
    std::string savefile;

    Random rand;

public :
    Game();
    ~Game();

    // Functions
    void initMenu();
    void mainMenu();
    void statMenu();
    void restMenu();
    void combatMenu(bool pstart = true);
    void shopMenu();
    void gameOverMenu();

    void createPlayer();
    void savePlayer();
    void loadPlayer();

    //Accessors
    inline bool isPlaying() const { return this->playing; }

};

#endif
