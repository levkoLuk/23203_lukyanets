#include "StrategyFactory.h"
#include "strategy.h"
#include <stdexcept>

std::map<std::string, Factory::Creator>& Factory::getRegistry() {
    static std::map<std::string, Creator> registry;
    return registry;
}

Strategy* Factory::createStrategy(const std::string& name) {
    auto& registry = getRegistry();
    auto it = registry.find(name);
    if (it != registry.end()) {
        return it->second();
    }
    throw std::runtime_error("Unknown strategy: " + name);
}

void Factory::registerStrategy(const std::string& name, Creator creator) {
    getRegistry()[name] = creator;
}