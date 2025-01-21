#include "SimpleStrategy.h"
#include <fstream>
#include <sstream>

bool SimpleStrategy::decide(const std::vector<Card>& hand) const {
    int score = 0;
    for (const auto& card : hand) {
        score += card.getValue();
    }
    return score < hitThreshold; 

void SimpleStrategy::loadConfig(const std::string& configPath) {
    std::ifstream configFile(configPath);
    if (configFile.is_open()) {
        std::string line;
        while (std::getline(configFile, line)) {
            std::istringstream iss(line);
            std::string key;
            if (iss >> key) {
                if (key == "hitThreshold") {
                    iss >> hitThreshold;  
                }
            }
        }
    }
}