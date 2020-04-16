#ifndef UTIL_H
#define UTIL_H

#include <cstdlib>
#include <ctime>

class Random {
private :
    unsigned seed;

public :
    Random(unsigned seed = 0);
    ~Random();

    //Functions
    int gen(int min = 0, int max = 100);
};

#endif
