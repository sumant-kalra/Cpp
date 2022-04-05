#ifndef RANDOM_H
#define RANDOM_H

namespace random_space
{
    // Generate a 4 digit PIN using rand() of <cstdlib>
    unsigned short int generatePIN_4_C();

    // C++11
    // Distribution bounds the output of the generator intialized with a seed

    // 1. distribution(2. generator)
    // 1.5 Initialize/Seed the generator with an unsigned value from any clock

    // Generate a 4 digit PIN using <random> library of C++
    unsigned short int generatePIN_4_cpp();

    // Generate a real number randomly in the provided range
    double generateRand_cpp(double min, double max);

    // Generate a real number randomly in the range [0,1)
    double generateRandCanonical();
}

#endif