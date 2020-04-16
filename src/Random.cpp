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
