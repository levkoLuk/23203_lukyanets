#pragma once

#include "strategy.h"
#include <string>
#include <map>
#include <functional>
#include <memory>

class Factory {
public:
    using Creator = std::function<Strategy*()>;

    static Strategy* createStrategy(const std::string& name);
    static void registerStrategy(const std::string& name, Creator creator);

private:
    static std::map<std::string, Creator>& getRegistry();
};
