#include "GameEngine.h"
#include <iostream>

Game::Game(Player* player1, Player* player2, Deck* deck) : player1(player1), player2(player2), deck(deck) {}

void Game::playRound() {
    player1->reset();
    player2->reset();

    player1->takeCard(deck->drawCard());
    player2->takeCard(deck->drawCard());

    while (player1->wantsHit() && !player1->isBusted()) {
        player1->takeCard(deck->drawCard());
    }

    while (player2->wantsHit() && !player2->isBusted()) {
        player2->takeCard(deck->drawCard());
    }
}

void Game::printResults() const {
    std::cout << "Player 1 score: " << player1->getScore() << std::endl;
    std::cout << "Player 2 score: " << player2->getScore() << std::endl;

    if (player1->isBusted() && player2->isBusted()) {
        std::cout << "Both players busted!" << std::endl;
    } else if (player1->isBusted()) {
        std::cout << "Player 2 wins!" << std::endl;
    } else if (player2->isBusted()) {
        std::cout << "Player 1 wins!" << std::endl;
    } else if (player1->getScore() > player2->getScore()) {
        std::cout << "Player 1 wins!" << std::endl;
    } else if (player2->getScore() > player1->getScore()) {
        std::cout << "Player 2 wins!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }
}