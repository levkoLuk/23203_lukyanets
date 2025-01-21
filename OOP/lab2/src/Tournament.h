#pragma once

#include <vector>
#include <string>
#include <map>
#include "player.h"
#include "GameEngine.h"

class Tournament {
public:
    Tournament(const std::vector<std::string>& strategyNames, int numDecks = 1);
    void run();
    void printResults() const;

private:
    std::vector<Player*> players;
    std::map<std::string, int> scores;
    Deck deck;

    void playMatches();
};
