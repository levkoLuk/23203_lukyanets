#pragma once

#include <string>

class Card {
public:
    enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(Rank rank, Suit suit);
    int getValue() const;
    std::string toString() const;

private:
    Rank rank;
    Suit suit;
};
