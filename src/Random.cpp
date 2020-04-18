#include "../include/Random.h"

Random::Random(unsigned seed)
{
    if (seed == 0) {
        srand(time(NULL));
    } else {
        srand(seed);
    }
}

Random::~Random()
{
}

int Random::gen(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int Random::lootExp(int level)
{
    return gen(2*level + 6, 4*level + 9);
}

int Random::lootGold(int level)
{
    return gen(level + 2, 2 * level + 3);
}
