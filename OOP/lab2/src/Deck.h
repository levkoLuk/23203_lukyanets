#pragma once

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck(int numDecks = 1);
    void shuffle();
    Card drawCard();
    bool isEmpty() const;

private:
    std::vector<Card> cards;
    void createDeck(int numDecks);
};
