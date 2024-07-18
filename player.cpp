#pragma once
#include <set>
#include "cardPack.cpp"

class Player{
    std::set<int> numbers;
    int score;
    std::list<Card> pack;
public:
    explicit Player() : score(1000){}

    void addNumbers(const std::set<int> &s){
        numbers = s;
    }

    const std::set<int>& getNumbers() const {
        return numbers;
    }
    void resetNumbers(){
        numbers.clear();
    }

    bool is_playable() const{
        return score >= 100;
    }

    void updateBalance(Player &p1){
        this->score += 100;
        p1.score -= 100;
        numbers.clear();
    }

    int getScore() const{
        return score;
    }

    void PlayerCards(std::list<Card> list){
        pack = list;
    }

    std::list<Card> getPlayerCards(){
        return pack;
    }
};
