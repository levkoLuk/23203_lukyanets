#pragma once

#include <vector>
#include <string>
#include "Card.h"

class Strategy {
public:
    virtual bool decide(const std::vector<Card>& hand) const = 0;
    virtual void loadConfig(const std::string& configPath) = 0;
    virtual std::string getName() const = 0;
    virtual ~Strategy() = default;
};
