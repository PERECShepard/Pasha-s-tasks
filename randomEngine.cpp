#include <iostream>
#include <random>

class RandomEngine{
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;
public:
<<<<<<< HEAD
    RandomEngine(int min, int max): gen{std::random_device{}()}, distrib{min, max}{}
    int getRandomNumber(){
        return distrib(gen);
    }
};
=======
    RandomEngine(): gen{std::random_device{}()}, distrib{1, 20}{}
    int getRandomNumber(){
        return distrib(gen);
    }
};
>>>>>>> c5f9e4e (test)
