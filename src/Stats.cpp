#include "../include/Stats.h"

Stats::Stats()
{
    for (int i = 0; i < NSTATS; i++) {
        this->stats[i] = 0;
    }
}

Stats::~Stats()
{
}
