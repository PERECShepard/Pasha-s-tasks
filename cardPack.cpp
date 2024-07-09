#pragma once
#include <list>
#include "card.cpp"
#include "randomEngine.cpp"

class CardPack{
    std::list<Card> cardPack;
    std::list<Card> fullCardPack;
public:

    void initFullCardPack() {
        for (int i = static_cast<int>(Suit::Clubs); static_cast<Suit>(i) <= Suit::Spades; ++i) {
            for (int j = static_cast<int>(Rank::Two); static_cast<Rank>(j) <= Rank::Ace; ++j) {
                fullCardPack.emplace_back(static_cast<Rank>(j), static_cast<Suit>(i));
            }
        }
    }

    std::list<Card> initCardPack() {
        cardPack.clear();
        std::vector<Card> temp;
        std::random_device dev;
        std::mt19937 gen(dev());

        for (int i = static_cast<int>(Suit::Clubs); static_cast<Suit>(i) <= Suit::Spades; ++i) {
            for (int j = static_cast<int>(Rank::Two); static_cast<Rank>(j) <= Rank::Ace; ++j) {
                temp.emplace_back(static_cast<Rank>(j), static_cast<Suit>(i));
            }
        }

        std::shuffle(temp.begin(), temp.end(), gen);

        auto it = temp.begin();
        for (int i = 0; i < 10; ++i, ++it) {
            cardPack.push_back(*it);
        }
        return cardPack;
    }


};
