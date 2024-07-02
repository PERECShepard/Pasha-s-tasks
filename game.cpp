#include <iostream>
#include <iterator>
#include "cards.cpp"

class NumberGame{
    int randNumber;
    RandomEngine randomEngine;
    Player human;
    Player pc;
    Cards cards;
public:
    NumberGame() : human(), pc(), randomEngine(1, 20), cards(static_cast<Rank>(10)){}
    void run(){
        while(human.is_playable() && pc.is_playable()) {
            std::cout << "Now u have: " << human.getScore() << std::endl
                      << "and pc have: " << pc.getScore() << std::endl;
            human.addNumbers(getPlayerInput());
            pc.addNumbers(calcComputerTurn());
            randNumber = randomEngine.getRandomNumber();

            int absComputer = std::abs(sum(pc) - randNumber);
            int absHuman = std::abs(sum(human) - randNumber);

            std::cout << "Round started" << std::endl
                      << "Pc chose: " ; pc.showNumbers();
            std::cout <<  "Your choice: "; human.showNumbers();
            std::cout << "Number: " << randNumber << std::endl;

            cards.displayDesk(human);
            cards.displayDesk(pc);

            if (absComputer == absHuman) {
                std::cout << "*********Tie!*********" << std::endl;
            } else {
                defineWinnerByAbs(absComputer, absHuman);
            }
        }
        if(!human.is_playable()){
            std::cout << "You do not have enough money to play. PC win this game.\n"
                      << "Game finished!" << std::endl;
        }else {
            std::cout << "The PC does not have enough money to play. You win this game.\n"
                      << "Game finished!" << std::endl;
        }
    }

    std::set<int> getPlayerInput(){
        int number;
        std::set<int> input;
        while (input.size() < 2) {
            std::cout << "Please enter number between 1 - 20 range: ";
            std::cin >> number;
            if(std::cin.fail() || number < 1 || number > 20){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 20.\n";
            } else if(!input.insert(number).second) {
                std::cout << "You entered_ " << number << " choose another number."<< std::endl;
            }else{
                input.insert(number);
            }
        }
        return input;
    }

    std::set<int> calcComputerTurn(){
        RandomEngine re(1, 10);
        int pc_value;
        std::set<int> pc_input;
        pc_value = re.getRandomNumber();
        while(pc_input.size() < 2) {
            while (!pc_input.insert(pc_value).second) {
                pc_value = re.getRandomNumber();
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
