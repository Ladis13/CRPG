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
    inline std::string getName() const {
        return this->name; }
    inline int getLevel() const {
        return this->level; }
    inline int getHp() const {
        return this->hp; }
    inline int getStamina() const {
        return this->stamina; }
    inline int getMagic() const {
        return this->magic; }

    inline bool isDead() const {
        return this->hp <= 0; }
    inline bool isExhausted() const {
        return this->stamina <= 0; }
    inline bool isCorrupted() const {
        return this->magic > getLimit(); }

    inline Stats getStats() const {
        return this->stats; }

    inline int getStrength() const {
        return this->stats.getStrength(); }
    inline int getStrudiness() const {
        return this->stats.getStrudiness(); }
    inline int getIntelligence() const {
        return this->stats.getIntelligence(); }
    inline int getSpirit() const {
        return this->stats.getSpirit(); }
    inline int getAgility() const {
        return this->stats.getAgility(); }
    inline int getLuck() const {
        return this->stats.getLuck(); }

    inline int getVitality() const {
        return this->sstats.getVitality(); }
    inline int getEnergy() const {
        return this->sstats.getEnergy(); }
    inline int getTenacity() const {
        return this->sstats.getTenacity(); }
    inline int getWill() const {
        return this->sstats.getWill(); }
    inline int getPower() const {
        return this->sstats.getPower(); }
    inline int getResistance() const {
        return this->sstats.getResistance(); }
    inline int getPerception() const {
        return this->sstats.getPerception(); }
    inline int getMastery() const {
        return this->sstats.getMastery(); }
    inline int getDodge() const {
        return this->sstats.getDodge(); }
    inline int getLimit() const {
        return this->sstats.getLimit(); }

    //Modifiers
    inline void gainHp(int n) {
        this->hp += n;
        if (this->hp > getVitality())
        this->hp = getVitality(); }
    inline void gainStamina(int n) {
        this->stamina += n; if (this->stamina > getEnergy())
        this->stamina = getEnergy(); }
    inline void gainMagic(int n) { this->magic += n; }

    inline void setName(std::string name) {
        this->name = name; }
    inline void setLevel(int n) {
        this->level = n; }
    inline void setHp(int n) {
        this->hp = n; }
    inline void setStamina(int n) {
        this->stamina = n; }

    inline void setStrength(int n) {
        this->stats.setStrength(n); }
    inline void setSturdiness(int n) {
        this->stats.setSturdiness(n); }
    inline void setIntelligence(int n) {
        this->stats.setIntelligence(n); }
    inline void setSpirit(int n) {
        this->stats.setSpirit(n); }
    inline void setAgility(int n) {
        this->stats.setAgility(n); }
    inline void setLuck(int n) {
        this->stats.setLuck(n); }

    inline void setSStats(SStats sstats) {
        this->sstats = sstats; }

    inline void setVitality(int n) {
        this->sstats.setVitality(n); }
    inline void setEnergy(int n) {
        this->sstats.setEnergy(n); }
    inline void setTenacity(int n) {
        this->sstats.setTenacity(n); }
    inline void setWill(int n) {
        this->sstats.setWill(n); }
    inline void setPower(int n) {
        this->sstats.setPower(n); }
    inline void setResistance(int n) {
        this->sstats.setResistance(n); }
    inline void setPerception(int n) {
        this->sstats.setPerception(n); }
    inline void setMastery(int n) {
        this->sstats.setMastery(n); }
    inline void setDodge(int n) {
        this->sstats.setDodge(n); }
    inline void setLimit(int n) {
        this->sstats.setLimit(n); }
};

#endif
