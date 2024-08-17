#include "card.h"


std::string Card::getRankToString() const {
    auto it = rankMap.find(m_rank);
    return it!= rankMap.end()? it->second.first : "Unknown";
}

int Card::getRankToValue() const{
    auto it = rankMap.find(m_rank);
    return it!= rankMap.end()? it->second.second : 0;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    return os << "Rank: " << static_cast<int>(card.m_rank)
              << ", Suit: " << static_cast<int>(card.m_suit);
}