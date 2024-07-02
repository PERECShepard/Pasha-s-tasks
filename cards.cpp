#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "randomEngine.cpp"
#include "player.cpp"

enum class Rank {
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Cards{
    Rank m_rank;
    std::vector<std::pair<Rank, bool>> desk;
public:
    Cards(Rank rank) : m_rank(rank) {
        createAndShuffleDesk(desk);
    }

    std::string getRankToString(const Rank rank) const {
        switch (rank) {
            case Rank::Two:   return "2";
            case Rank::Three: return "3";
            case Rank::Four:  return "4";
            case Rank::Five:  return "5";
            case Rank::Six:   return "6";
            case Rank::Seven: return "7";
            case Rank::Eight: return "8";
            case Rank::Nine:  return "9";
            case Rank::Ten:   return "10";
            case Rank::Jack:  return "J";
            case Rank::Queen: return "Q";
            case Rank::King:  return "K";
            case Rank::Ace:   return "A";
            default:          return "Unknown";
        }
    }

    void createAndShuffleDesk(std::vector<std::pair<Rank, bool>>& vec) {
        for (int beginRank = static_cast<int>(Rank::Two); beginRank <= static_cast<int>(Rank::Ace); ++beginRank) {
            vec.emplace_back(static_cast<Rank>(beginRank), false);
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(vec.begin(), vec.end(), g);
    }

    void displayDesk(const Player &player) {
        const std::set<int>& nums = player.getNumbers();
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            int num = *it;
            desk[num - 1].second = true;
        }

        for (int i = 0; i < desk.size(); ++i) {
            if (desk[i].second) {
                std::string rankStr = getRankToString(desk[i].first);
                std::cout << "[" << rankStr << "]";
            } else {
                std::cout << "[" << "#" << "]";
            }
        }
        std::cout << "\n";
    }

    int getValue(){
        int value = static_cast<int>(m_rank);
        return value;
    }
};
