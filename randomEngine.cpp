#include <iostream>
#include <random>

class RandomEngine{
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;
public:
    RandomEngine(int min, int max): gen{std::random_device{}()}, distrib{min, max}{}
    int getRandomNumber(){
        return distrib(gen);
    }
};