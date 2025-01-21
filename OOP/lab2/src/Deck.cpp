#include "Deck.h"
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck(int numDecks) {
    createDeck(numDecks);
    shuffle();
}

void Deck::createDeck(int numDecks) {
    for (int i = 0; i < numDecks; ++i) {
        for (int suit = Card::CLUBS; suit <= Card::SPADES; ++suit) {
            for (int rank = Card::ACE; rank <= Card::KING; ++rank) {
                cards.push_back(Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)));
            }
        }
    }
}

void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

Card Deck::drawCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}

bool Deck::isEmpty() const {
    return cards.empty();
}