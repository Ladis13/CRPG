#ifndef STATS_H
#define STATS_H

#include <cmath>
#include "ESTATS.h"
#include "SStats.h"

class Stats {
private:
    int stats[NSTATS];

public:
    Stats(int strength = 0, int sturdiness = 0, int intelligence = 0, int spirit = 0, int agility = 0, int luck = 0);
    ~Stats();

    //Functions
    SStats getSStats();

    //Accessors
    inline int getStrength() const {
        return this->stats[STAT::STRENGTH]; }
    inline int getStrudiness() const {
        return this->stats[STAT::STURDINESS]; }
    inline int getIntelligence() const {
        return this->stats[STAT::INTELLIGENCE]; }
    inline int getSpirit() const {
        return this->stats[STAT::SPIRIT]; }
    inline int getAgility() const {
        return this->stats[STAT::AGILITY]; }
    inline int getLuck() const {
        return this->stats[STAT::LUCK]; }

    //Modifiers
    inline void gainStrength(int n) {
        this->stats[STAT::STRENGTH] += n; }
    inline void gainSturdiness(int n) {
        this->stats[STAT::STURDINESS] += n; }
    inline void gainIntelligence(int n) {
        this->stats[STAT::INTELLIGENCE] += n; }
    inline void gainSpirit(int n) {
        this->stats[STAT::SPIRIT] += n; }
    inline void gainAgility(int n) {
        this->stats[STAT::AGILITY] += n; }
    inline void gainLuck(int n) {
        this->stats[STAT::LUCK] += n; }

    inline void setStrength(int n) {
        this->stats[STAT::STRENGTH] = n; }
    inline void setSturdiness(int n) {
        this->stats[STAT::STURDINESS] = n; }
    inline void setIntelligence(int n) {
        this->stats[STAT::INTELLIGENCE] = n; }
    inline void setSpirit(int n) {
        this->stats[STAT::SPIRIT] = n; }
    inline void setAgility(int n) {
        this->stats[STAT::AGILITY] = n; }
    inline void setLuck(int n) {
        this->stats[STAT::LUCK] = n; }
};

#endif
