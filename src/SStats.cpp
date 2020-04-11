#include "../include/SStats.h"

SStats::SStats()
{
    for (int i = 0; i < NSSTATS; i++) {
        this->sstats[i] = 0;
    }
}

SStats::~SStats()
{
}
