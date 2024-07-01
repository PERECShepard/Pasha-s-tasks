#include <iostream>
#include <string>
#include <vector>
#include "randomEngine.cpp"

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
    std::vector<Rank> desk;
public:
    Cards(Rank rank) : m_rank(rank) { createAndShuffleDesk(desk); }

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

    void createAndShuffleDesk(std::vector<Rank>& vec) {
        for (int beginRank = static_cast<int>(Rank::Two); beginRank <= static_cast<int>(Rank::Ace); ++beginRank) {
            vec.push_back(static_cast<Rank>(beginRank));
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(vec.begin(), vec.end(), g);
    }

    void displayDesk() {
        for (auto it = desk.begin(); it != desk.end(); ++it) {
            std::cout << "[" << getRankToString(*it) << "]";
        }
        std::cout << "\n";
    }

    Cards chooseCard(int cardIndex) {
        auto it = desk.begin() + cardIndex;
        Cards chosenCard = *it;
        desk.erase(it);
        return chosenCard;
    }
};
