#pragma once
#include <list>
#include <vector>
#include <stack>
#include "card.cpp"
#include "randomEngine.cpp"

class CardPack {
    std::list<Card> cardPack;
    std::stack<Card> cardStack;
public:
    void initFullCardPack() {
        std::vector<Card> temp;
        for (int i = static_cast<int>(Suit::Clubs); i <= static_cast<int>(Suit::Spades); ++i) {
            for (int j = static_cast<int>(Rank::Two); j <= static_cast<int>(Rank::Ace); ++j) {
                temp.emplace_back(static_cast<Rank>(j), static_cast<Suit>(i));
            }
        }
        std::random_device dev;
        std::mt19937 gen(dev());
        std::shuffle(temp.begin(), temp.end(), gen);

        for (int i = 0; i < temp.size(); ++i) {
            cardStack.push(temp[i]);
        }
    }

    std::list<Card> initCardPack() {
        cardPack.clear();

        for (int i = 0; i < 10; ++i) {
            cardPack.push_back(cardStack.top());
            cardStack.pop();
        }
        return cardPack;
    }

    void resetPack() {
        initFullCardPack();
    }
};
