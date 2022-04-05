#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>

#include "Random.h"

//------------------------------------------------------------//
unsigned short int random_space::generatePIN_4_C()
{
    srand(time(NULL));
    return (unsigned short int)((rand() % 9000) + 1000);
}

//------------------------------------------------------------//
// distribution(generator)
// Initialize/Seed the generator before using it
unsigned short int random_space::generatePIN_4_cpp()
{
    std::uniform_int_distribution<int> distribution(1000, 9999);

    unsigned int seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    std::default_random_engine generator(seed);

    return (unsigned short int)distribution(generator);
}

//------------------------------------------------------------//
double random_space::generateRand_cpp(double min, double max)
{
    std::uniform_real_distribution<double> distribution(min, max);

    unsigned int seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    std::default_random_engine generator(seed);

    return distribution(generator);
}

//------------------------------------------------------------//
double random_space::generateRandCanonical()
{
    unsigned int seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // Generates a random floating point number in range [0,1)
    return std::generate_canonical<double, 10>(generator);
}