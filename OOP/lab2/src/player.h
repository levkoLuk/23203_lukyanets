#pragma once

#include <vector>
#include "Card.h"
#include "strategy.h"

class Player {
public:
    Player(Strategy* strategy);
    void takeCard(Card card);
    int getScore() const;
    bool isBusted() const;
    bool wantsHit() const;
    void reset();
    std::string getStrategyName() const;

private:
    std::vector<Card> hand;
    Strategy* strategy;
    int calculateScore() const;
};
