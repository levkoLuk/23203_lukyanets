#include "Tournament.h"
#include "strategy.h"
#include "StrategyFactory.h"
#include <iostream>

Tournament::Tournament(const std::vector<std::string>& strategyNames, int numDecks)
    : deck(numDecks) {
    for (const auto& name : strategyNames) {
        Strategy* strategy = Factory::createStrategy(name);
        players.push_back(new Player(strategy));
        scores[name] = 0;
    }
}

void Tournament::playMatches() {
    for (size_t i = 0; i < players.size(); ++i) {
        for (size_t j = i + 1; j < players.size(); ++j) {
            Game game(players[i], players[j], &deck);
            game.playRound();

            if (players[i]->getScore() > players[j]->getScore() && !players[i]->isBusted()) {
                scores[players[i]->getStrategyName()]++;
            } else if (players[j]->getScore() > players[i]->getScore() && !players[j]->isBusted()) {
                scores[players[j]->getStrategyName()]++;
            }
        }
    }
}

void Tournament::run() {
    playMatches();
    printResults();
}

void Tournament::printResults() const {
    std::cout << "Tournament Results:" << std::endl;
    for (const auto& [name, score] : scores) {
        std::cout << name << ": " << score << " wins" << std::endl;
    }
}