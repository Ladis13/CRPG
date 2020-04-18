#include "../include/Enemy.h"

Enemy::Enemy(std::string name, unsigned level)
{
    this->name = name;
    this->level = level;

    int stats = round(((NSTATS * 5 + this->level) / NSTATS) / 1.5);
    this->stats = Stats(stats , stats, stats, stats, stats, stats);
    this->sstats = this->stats.getSStats(this->level);

    this->hp = getVitality();
    this->stamina = getEnergy();
    this->magic = 0;
}

Enemy::~Enemy()
{
}

void Enemy::print()
{
    std::cout << "=\t" << this->name << "\tNiv : " << this->level << "\t\tVie : " << this->hp << "/" << getVitality() << std::endl;
}
