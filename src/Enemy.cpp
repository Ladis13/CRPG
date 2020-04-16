#include "../include/Enemy.h"

Enemy::Enemy(std::string name, unsigned level)
{
    this->name = name;
    this->level = level;

    int stats = round(((NSTATS * 10 + this->level) / NSTATS) / 2);
    this->stats = Stats(stats , stats, stats, stats, stats, stats);
    this->sstats = this->stats.getSStats();

    this->hp = getVitality();
    this->stamina = getEnergy();
    this->magic = 0;
}

Enemy::~Enemy()
{
}

void Enemy::print()
{
    std::cout << this->name << "\tNiveau :" << this->level << std::endl;
    std::cout << "Vitalité : " << this->hp << "/" << getVitality() << std::endl;
    std::cout << "Énergie : " << this->stamina << "/" << getEnergy() << std::endl << std::endl;
}
