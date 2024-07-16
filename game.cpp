#pragma once
#include <iostream>
#include <iterator>
#include "cardService.cpp"

class NumberGame{
    int randNumber;
    RandomEngine randomEngine;
    Player human;
    Player pc;
    CardService cardService;
public:
    NumberGame() : human(), pc(), randomEngine(1, 20) {}
    void run(){
        while(human.is_playable() && pc.is_playable()) {
            std::cout << "Now u have: " << human.getScore() << std::endl
                      << "and pc have: " << pc.getScore() << std::endl;
            human.addNumbers(getPlayerInput());
            pc.addNumbers(calcComputerTurn());
            randNumber = randomEngine.getRandomNumber();

            cardService.defineOpenCards(human);
            std::cout << "Your cards: " << std::endl;
            cardService.showCards(human);

            cardService.defineOpenCards(pc);
            std::cout << "Pc cards: " << std::endl;
            cardService.showCards(pc);

            int pcSum = std::abs(cardService.scoring(pc) - randNumber);
            int humanSum = std::abs(cardService.scoring(human) - randNumber);

            std::cout << "Round started" << std::endl
                      << "You have: " << cardService.scoring(human) << std::endl;
            std::cout <<  "Pc have: " << cardService.scoring(pc) << std::endl;
            std::cout << "Number: " << randNumber << std::endl;

            if (pcSum == humanSum) {
                std::cout << "*********Tie!*********" << std::endl;
            } else {
                defineWinnerByAbs(humanSum, pcSum);
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
            std::cout << "Please enter number between 1 - 10 range: ";
            std::cin >> number;
            if(std::cin.fail() || number < 1 || number > 10){
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

    void defineWinnerByAbs(int humSum, int compSum){
        if(humSum < compSum){
            std::cout << "U R win because your number were closer" << std::endl;
            human.updateBalance(pc);
        }else {
            std::cout << "PC win because his number was closer" << std::endl;
            pc.updateBalance(human);
        }
    }
};
