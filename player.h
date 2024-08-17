#pragma once
#include <iostream>
#include <set>

enum class PlayerType{
    HUMAN,
    PC
};

class Player {
    int valueOfCards;
    int balance;
    PlayerType type;
public:
    Player(PlayerType t = PlayerType::HUMAN) : valueOfCards(0), balance(0), type(t) {};

    inline int getScores() const{
        return valueOfCards;
    }

    inline Player getPlayerType(){
        return type;
    }

    void setScore(int score);
};