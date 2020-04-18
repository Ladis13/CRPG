#include "../include/Stats.h"

Stats::Stats(int strength, int sturdiness, int intelligence, int spirit, int agility, int luck) {
    this->stats[STAT::STRENGTH] = strength;
    this->stats[STAT::STURDINESS] = sturdiness;
    this->stats[STAT::INTELLIGENCE] = intelligence;
    this->stats[STAT::SPIRIT] = spirit;
    this->stats[STAT::AGILITY] = agility;
    this->stats[STAT::LUCK] = luck;
}

Stats::~Stats()
{
}

SStats Stats::getSStats(int level)
{
    SStats sstats;

    int vitality = 1 * getStrength() + 3 * getSturdiness() + 5 * level;
    sstats.setVitality(vitality);

    int energy = 2 * getAgility() + 2 * getSturdiness() + 2 * (level - 1);
    sstats.setEnergy(energy);

    int tenacity = (getSpirit() + getAgility()) / 2;
    sstats.setTenacity(tenacity);

    int will = (getIntelligence() + getStrength()) / 2;
    sstats.setWill(will);

    int power = (getStrength() + getAgility()) / 2;
    sstats.setPower(power);

    int resistance = (getSturdiness() + getSpirit()) / 4;
    sstats.setResistance(resistance);

    int perception = (getAgility() + getIntelligence()) / 2;
    sstats.setPerception(perception);

    int mastery = (getStrength() + getAgility() + getIntelligence()) / 6;
    sstats.setMastery(mastery);

    int dodge = (getAgility() + getIntelligence()) / 2;
    sstats.setDodge(dodge);

    int limit = floor((getIntelligence() + getSpirit()) / 20 + 1);
    sstats.setLimit(limit);

    return sstats;
}
