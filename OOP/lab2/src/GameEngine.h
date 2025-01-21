#pragma once

#include "player.h"
#include "Deck.h"

class Game {
public:
    Game(Player* player1, Player* player2, Deck* deck);
    void playRound();
    void printResults() const;

private:
    Player* player1;
    Player* player2;
    Deck* deck;
};
