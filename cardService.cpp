#pragma once
#include "player.cpp"

class CardService{
    CardPack pack;
public:
    CardService(){
        pack.initFullCardPack();
    }

    void initPlayerCards(Player &player){
        player.PlayerCards(pack.initCardPack());
    }

    void defineOpenCards(Player &player){
        std::list<Card> playingCards = player.getPlayerCards();
        const std::set<int>& nums = player.getNumbers();
        for (auto num : nums) {
            auto it = std::next(playingCards.begin(), num - 1);
            it->Open();
        }
        player.PlayerCards(playingCards);
    }

    void showCards(Player &player) {
        if(player.getType() == PlayerType::HUMAN){
            std::cout << "Your cards: " << std::endl;
        }else {
            std::cout << "Pc cards: " << std::endl;
        }
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

    int scoring(Player &player){
        std::list<Card> scores = player.getPlayerCards();
        int sum = 0;
        for (auto it = scores.begin(); it != scores.end(); ++it) {
            if(it->visibility()){
                sum += static_cast<int>(it->getRank());
            }
        }
        pack.resetPack();
        return sum;
    }

    void openCards(Player &player){
        std::list<Card> openedCards = player.getPlayerCards();
        for (auto it = openedCards.begin(); it != openedCards.end(); ++it) {
            if (it->visibility()) {
                std::cout << it->getRankToString() << it->getSuitToString();
            }
        }
    }
};
