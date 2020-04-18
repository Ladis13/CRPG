#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Stats.h"
#include "Random.h"

class Character {
protected:
    std::string name;

    int level;
    Stats stats;
    SStats sstats;

    int hp;
    int stamina;
    int magic;

public:
    Character();
    Character(const Character& character);
    ~Character();

    //Functions
    void initialize(std::string name);

    unsigned takeDamage(unsigned damage);

    void print();
    std::string toString();

    //Accessors
    inline std::string getName() const { return this->name; }
    inline int getLevel() const { return this->level; }
    inline int getHp() const { return this->hp; }
    inline int getStamina() const { return this->stamina; }
    inline int getMagic() const { return this->magic; }

    inline bool isDead() const { return this->hp <= 0; }
    inline bool isExhausted() const { return this->stamina <= 0; }
    inline bool isCorrupted() const { return this->magic > getLimit(); }

    inline Stats getStats() const { return this->stats; }

    inline int getStrength() const { return this->stats.getStrength(); }
    inline int getSturdiness() const { return this->stats.getSturdiness(); }
    inline int getIntelligence() const { return this->stats.getIntelligence(); }
    inline int getSpirit() const { return this->stats.getSpirit(); }
    inline int getAgility() const { return this->stats.getAgility(); }
    inline int getLuck() const { return this->stats.getLuck(); }

    inline int getVitality() const { return this->sstats.getVitality(); }
    inline int getEnergy() const { return this->sstats.getEnergy(); }
    inline int getLimit() const { return this->sstats.getLimit(); }
    inline int getTenacity() const { return this->sstats.getTenacity(); }
    inline int getWill() const { return this->sstats.getWill(); }
    inline int getPower() const { return this->sstats.getPower(); }
    inline int getResistance() const { return this->sstats.getResistance(); }
    inline int getPerception() const { return this->sstats.getPerception(); }
    inline int getMastery() const { return this->sstats.getMastery(); }
    inline int getDodge() const { return this->sstats.getDodge(); }

    //Modifiers
    inline void setStrength(int n) { this->stats.setStrength(n); }
    inline void setSturdiness(int n) { this->stats.setSturdiness(n); }
    inline void setIntelligence(int n) { this->stats.setIntelligence(n); }
    inline void setSpirit(int n) { this->stats.setSpirit(n); }
    inline void setAgility(int n) { this->stats.setAgility(n); }
    inline void setLuck(int n) { this->stats.setLuck(n); }

    void gainHp(int n);
    void gainStamina(int n);
    inline void gainStrength(int n) { this->stats.gainStrength(n); }
    inline void gainSturdiness(int n) { this->stats.gainSturdiness(n); }
    inline void gainIntelligence(int n) { this->stats.gainIntelligence(n); }
    inline void gainSpirit(int n) { this->stats.gainSpirit(n); }
    inline void gainAgility(int n) { this->stats.gainAgility(n); }
    inline void gainLuck(int n) { this->stats.gainLuck(n); }

    inline void setSStats(SStats sstats) { this->sstats = sstats; }
};

#endif
