#pragma once

#include <string>
#include <functional>
#include <dlfcn.h>
#include "strategy.h"

class DynamicLoader {
public:
    using StrategyCreator = std::function<Strategy*()>;

    static StrategyCreator loadStrategy(const std::string& libraryPath, const std::string& strategyName);

private:
    static void* loadLibrary(const std::string& path);
    static void closeLibrary(void* handle);
    static StrategyCreator getSymbol(void* handle, const std::string& symbolName);
};
