#pragma once
#include <iostream>

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

enum class Suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

class Card{
    Rank m_rank;
    Suit m_suit;
    bool is_visible;
public:
    Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit), is_visible(false) {}
    Card(){}

    bool visibility() const{
        return is_visible;
    }

    void Open(){
        is_visible = true;
    }

    Rank getRank(){
        return m_rank;
    }

    std::string getRankToString() const {
        switch (m_rank) {
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

    std::string getSuitToString() const {
        switch (m_suit) {
            case Suit::Clubs:    return "♣";
            case Suit::Diamonds: return "♦";
            case Suit::Hearts:   return "♥";
            case Suit::Spades:   return "♠";
            default:             return "Unknown Suit";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Card& card) {
        return os << "Rank: " << static_cast<int>(card.m_rank)
                  << ", Suit: " << static_cast<int>(card.m_suit);
    }
};

