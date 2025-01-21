#pragma once

#include "strategy.h"

class SimpleStrategy : public Strategy {
public:
    bool decide(const std::vector<Card>& hand) const override;
    void loadConfig(const std::string& configPath) override;
    std::string getName() const override { return "SimpleStrategy"; }
    static Strategy* create() { return new SimpleStrategy(); }

private:
    int hitThreshold = 17;
};
