#include "Card.h"
#include <string>

Card::Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}

int Card::getValue() const {
    if (rank >= JACK) return 10;
    return rank;
}

std::string Card::toString() const {
    std::string ranks[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
    std::string suits[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
    return ranks[rank - 1] + " of " + suits[suit];
}