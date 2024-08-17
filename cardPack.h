#pragma once
#include <list>
#include <vector>
#include <stack>
#include "card.h"
#include "randomEngine.h"

class CardPack {
    std::list<Card> cardPack;
    std::stack<Card> cardStack;
public:
    void initFullCardPack();
    std::list<Card> initCardPack();

    void resetPack() {
        initFullCardPack();
    }
};