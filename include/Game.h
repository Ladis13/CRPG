#ifndef GAME_H
#define GAME_H

#include "Player.h"


class Game {
private :
    int choice;
    bool playing;

    std::string savefile;
    Player player;

public :
    Game();
    ~Game();

    // Functions
    void initMenu();
    void mainMenu();
    void statMenu();
    void combatMenu();
    void shopMenu();

    void createPlayer();
    void savePlayer();
    void loadPlayer();

    //Accessors
    inline bool isPlaying() const { return this->playing; }

};

#endif
