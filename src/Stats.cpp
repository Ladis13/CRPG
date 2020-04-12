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

SStats Stats::getSStats()
{
    SStats sstats;

    int vitality = floor(0.25*getStrength() + getStrudiness() + 3);
    sstats.setVitality(vitality);

    int energy = floor(0.25*getStrength() + 0.50*getStrudiness() + 0.75*getAgility() + 0.25*getIntelligence() - 2);
    sstats.setEnergy(energy);

    int tenacity = floor(0.15*getSpirit() + 0.1*getAgility());
    sstats.setTenacity(tenacity);

    int will = floor(0.15*getIntelligence() + 0.1*getStrength());
    sstats.setWill(will);

    int power = floor(0.2*getStrength() + 0.2*getIntelligence());
    sstats.setPower(power);

    int resistance = floor(0.2*getStrudiness() + 0.15*getSpirit());
    sstats.setResistance(resistance);

    int perception = floor(0.2*getAgility() + 0.15*getIntelligence());
    sstats.setPerception(perception);

    int mastery = floor(0.05*getStrength() + 0.05*getAgility() + 0.05*getIntelligence() + 0.05*getSpirit());
    sstats.setMastery(mastery);

    int dodge = floor(0.2*getAgility() + 0.1*getIntelligence());
    sstats.setDodge(dodge);

    int limit = floor((getIntelligence() + getSpirit()) / 20 + 1);
    sstats.setLimit(limit);

    return sstats;
}
