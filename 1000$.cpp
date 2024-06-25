#include <iostream>
#include "randomEngine.cpp"
#include "player.cpp"

class NumberGame{
    int randNumber;
    RandomEngine randomEngine;
    Player human;
    Player pc;
public:
    NumberGame() : human(), pc(){}
    void run(){
        int turns;
        std::cout << "Please enter amount of numbers: ";
        std::cin >> turns;
        while(human.is_playable() && pc.is_playable()) {
            std::cout << "Now u have: " << human.getScore() << std::endl
                << "and pc have: " << pc.getScore() << std::endl;
            human.addNumbers(getPlayerInput(turns));
            pc.addNumbers(calcComputerTurn(turns));
            randNumber = randomEngine.getRandomNumber();

            int absComputer = std::abs(sum(pc) - randNumber);
            int absHuman = std::abs(sum(human) - randNumber);

            std::cout << "Game begin" << std::endl
                      << "Pc chose: " ; pc.showNumbers();
            std::cout <<  "Your choice: "; human.showNumbers();
            std::cout << "Number: " << randNumber << std::endl;

            if (absComputer == absHuman) {
                std::cout << "*********Tie!*********" << std::endl;
            } else {
                defineWinnerByAbs(absComputer, absHuman);
            }
        }
        std::cout << "Gj";
    }

    std::set<int> getPlayerInput(int count){
        int number;
        std::set<int> input;
        while (input.size() < count) {
            std::cout << "Please enter number between 1 - 20 range: ";
            std::cin >> number;
            if(std::cin.fail() || number < 1 || number > 20){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 20.\n";
            } else {
                input.insert(number);
            }
        }
        return input;
    }

    std::set<int> calcComputerTurn(int &count){
        int pc_value;
        std::set<int> pc_input;
        pc_value = randomEngine.getRandomNumber();
        for(int i = 0; i < count; ++i) {
            while (!pc_input.insert(pc_value).second) {
                pc_value = randomEngine.getRandomNumber();
            }
        }
        return pc_input;
    }

    int sum(const Player &player){
        int sum = 0;
        const std::set<int>& nums = player.getNumbers();
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            sum += *it;
        }
        return sum;
    }

    void defineWinnerByAbs(int humAbs, int compAbs){
        if(humAbs > compAbs){
            std::cout << "U R win because your number were closer" << std::endl;
            human.updateBalance(pc);
        }else {
            std::cout << "PC win because his number was closer" << std::endl;
            pc.updateBalance(human);
        }
    }
};

int main() {
    NumberGame game;
    game.run();
}