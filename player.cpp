#include <iostream>
#include <set>

class Player{
    std::set<int> numbers;
    int score;
public:
    explicit Player() : score(1000){}

    void addNumbers(const std::set<int> &s){
        numbers = s;
    }

    void showNumbers(){
        for(auto it = numbers.begin(); it != numbers.end(); ++it){
            std::cout << *it << " _ ";
        }
    }

    const std::set<int>& getNumbers() const {
        return numbers;
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
};
