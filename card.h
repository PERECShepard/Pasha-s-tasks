#pragma once
#include <iostream>
#include <unordered_map>

enum class Rank {
    Two,
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

const std::unordered_map<Rank, std::pair<std::string, int>> rankMap = {
        {Rank::Two, {"2", 2}},
        {Rank::Three, {"3", 3}},
        {Rank::Four, {"4", 4}},
        {Rank::Five, {"5", 5}},
        {Rank::Six, {"6", 6}},
        {Rank::Seven, {"7", 7}},
        {Rank::Eight, {"8", 8}},
        {Rank::Nine, {"9", 9}},
        {Rank::Ten, {"10", 10}},
        {Rank::Jack, {"J", 2}},
        {Rank::Queen, {"Q", 3}},
        {Rank::King, {"K", 4}},
        {Rank::Ace, {"A", 11}}
};

class Card{
    Rank m_rank;
    Suit m_suit;
    bool is_visible;
public:
    Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit), is_visible(false) {}
    Card(){}

    inline bool getVisibility(){
        return is_visible;
    }

    void setOpen(){
        is_visible = true;
    }

    std::string getRankToString() const;
    int getRankToValue() const;

    std::string getSuitToString() const {
        switch (m_suit) {
            case Suit::Clubs:    return "♣";
            case Suit::Diamonds: return "♦";
            case Suit::Hearts:   return "♥";
            case Suit::Spades:   return "♠";
            default:             return "Unknown Suit";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};