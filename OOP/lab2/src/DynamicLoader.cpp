#include "DynamicLoader.h"
#include <stdexcept>

void* DynamicLoader::loadLibrary(const std::string& path) {
    void* handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle) {
        throw std::runtime_error("Failed to load library: " + std::string(dlerror()));
    }
    return handle;
}

void DynamicLoader::closeLibrary(void* handle) {
    dlclose(handle);
}

DynamicLoader::StrategyCreator DynamicLoader::getSymbol(void* handle, const std::string& symbolName) {
    void* symbol = dlsym(handle, symbolName.c_str());
    if (!symbol) {
        throw std::runtime_error("Failed to load symbol: " + std::string(dlerror()));
    }
    return reinterpret_cast<StrategyCreator>(symbol);
}

DynamicLoader::StrategyCreator DynamicLoader::loadStrategy(const std::string& libraryPath, const std::string& strategyName) {
    void* handle = loadLibrary(libraryPath);
    std::string symbolName = "create" + strategyName;
    StrategyCreator creator = getSymbol(handle, symbolName);

    return [creator, handle]() {
        Strategy* strategy = creator();
        strategy->setLibraryHandle(handle); 
        return strategy;
    };
}