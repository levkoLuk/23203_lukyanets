#include "player.h"

Player::Player(Strategy* strategy) : strategy(strategy) {}

void Player::takeCard(Card card) {
    hand.push_back(card);
}

int Player::getScore() const {
    return calculateScore();
}

bool Player::isBusted() const {
    return calculateScore() > 21;
}

bool Player::wantsHit() const {
    return strategy->decide(hand);
}

void Player::reset() {
    hand.clear();
}

int Player::calculateScore() const {
    int score = 0;
    int aces = 0;
    for (const auto& card : hand) {
        int value = card.getValue();
        if (value == 1) aces++;
        score += value;
    }
    while (aces > 0 && score + 10 <= 21) {
        score += 10;
        aces--;
    }
    return score;
}

std::string Player::getStrategyName() const {
    return strategy->getName();
}