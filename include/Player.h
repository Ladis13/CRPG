#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character {
private:
    int exp;
    int expNext;
    int gold;
    int statPoints;

public:
    Player();
    Player(Stats stats);
    Player(std::string infile);
    ~Player();

    //Functions
    void initialize(std::string name);
    int levelUp();
    void save(std::string savefile);
    void print();
    std::string toString();

    //Accessors
    inline int getExp() const { return this->exp; }
    inline int getExpNext() const { return this->expNext; }
    inline int getGold() const { return this->gold; }
    inline int getStatPoints() const { return this->statPoints; }

    //Modifiers
    inline void gainStrength(int n) {
        this->stats.gainStrength(n); }
    inline void gainSturdiness(int n) {
        this->stats.gainSturdiness(n); }
    inline void gainIntelligence(int n) {
        this->stats.gainIntelligence(n); }
    inline void gainSpirit(int n) {
        this->stats.gainSpirit(n); }
    inline void gainAgility(int n) {
        this->stats.gainAgility(n); }
    inline void gainLuck(int n) {
        this->stats.gainLuck(n); }

    inline void gainExp(int n) { this->exp += n; }
    inline void gainGold(int n) { this->gold += n; }
    inline void gainStatPoints(int n) { this->statPoints += n; }

    inline void setExp(int n) { this->exp = n; }
    inline void setExpNext(int n) { this->expNext = n; }
    inline void setGold(int n) {this->gold = n; }
    inline void setStatPoints(int n) {this->statPoints = n; }

};

#endif
