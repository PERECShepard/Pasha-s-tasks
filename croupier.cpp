#include "cardPack.h"
#include "player.h"

class Croupier {
    CardPack pack;
    Player human;
    std::set<int> input;
    Player pc;
    std::pair<std::list<Card>, PlayerType> playerCards[2];
public:
    Croupier() : human(PlayerType::HUMAN), pc(PlayerType::PC) { pack.initFullCardPack(); }

    std::pair<std::list<Card>, PlayerType>* dealCards() {
        playerCards[0] = {pack.initCardPack(), PlayerType::HUMAN};
        playerCards[1] = {pack.initCardPack(), PlayerType::PC};
        return playerCards;
    }

    int getPlayerInput() {
        int number;
        while (true) {
            std::cout << "Please enter number between 1 - 10 range: ";
            std::cin >> number;
            if (std::cin.fail() || number < 1 || number > 10) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 10.\n";
            } else if (input.count(number) != 0) {
                std::cout << "You entered " << number << " choose another number." << std::endl;
            } else {
                input.insert(number);
                break;
            }
        }
        return number;
    }

    void openCards() {
        int humanNumber;
        while (human.getScores() <= 21) {
            if (input.size() >= 2) {
                char choice;
                std::cout << "Do u want to open next card? Y/N: " << std::endl;
                std::cin >> choice;
                if (toupper(choice) == 'N') {
                    break;
                } else if (toupper(choice) != 'Y') {
                    std::cout << "Incorrect choice; Repeat: " << std::endl;
                    continue;
                }
            }
            humanNumber = getPlayerInput();
            auto it = std::next(playerCards[0].first.begin(), humanNumber - 1);
            it->setOpen();
            human.setScore(it->getRankToValue());
            showCards();
        }
    }

    void showCards() {
        if (playerCards[0].second == PlayerType::HUMAN) {
            std::cout << "Your cards: " << std::endl;
        } else {
            std::cout << "Pc cards: " << std::endl;
        }
        for (auto it = playerCards[0].first.begin(); it != playerCards[0].first.end(); ++it) {
            if (it->getVisibility()) {
                std::cout << it->getRankToString() << it->getSuitToString();
            } else {
                std::cout << "[#]";
            }
        }
        std::cout << std::endl << "Now u have: ";
        for (auto it = playerCards[0].first.begin(); it != playerCards[0].first.end(); ++it) {
            if (it->getVisibility()) {
                std::cout << it->getRankToString() << it->getSuitToString();
            }
        }
        std::cout << " = " << human.getScores() << std::endl;
    }
};