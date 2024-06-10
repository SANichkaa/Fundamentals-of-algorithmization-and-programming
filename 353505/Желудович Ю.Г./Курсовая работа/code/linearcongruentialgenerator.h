#ifndef LINEARCONGRUENTIALGENERATOR_H
#define LINEARCONGRUENTIALGENERATOR_H

#include <cstdint>
#include <ctime>

class LinearCongruentialGenerator
{
public:
    typedef unsigned long long uint64;
    typedef uint64 RandomValue;

    LinearCongruentialGenerator();

    LinearCongruentialGenerator& operator=(uint64 seed);

    uint64 operator()(uint64 seed);


    uint64 operator()(uint64 min, uint64 max);

private:
    uint64 X;
};

#endif // LINEARCONGRUENTIALGENERATOR_H
