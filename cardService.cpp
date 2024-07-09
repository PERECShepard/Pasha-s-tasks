#pragma once
#include "player.cpp"

class CardService{
    CardPack pack;
public:

    void getRandomCard(Player &player){
        std::list<Card> playingCards = pack.initCardPack();
        const std::set<int>& nums = player.getNumbers();
        for (int i = 1; i <= playingCards.size(); ++i) {
            if (nums.find(i) != nums.end()) {
                auto it = std::next(playingCards.begin(), i - 1);
                it->Open();
            }
        }
        player.PlayerCards(playingCards);
    }

    void showCards(Player &player) {
        std::list<Card> playingCards = player.getPlayerCards();
        for (auto it = playingCards.begin(); it != playingCards.end(); ++it) {
            if (it->visibility()) {
                std::cout << it->getRankToString() << it->getSuitToString();
            } else {
                std::cout << "[#]";
            }
        }
        std::cout << std::endl;
    }
};
