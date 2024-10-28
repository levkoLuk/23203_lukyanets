#include "flatmap.h"
#include <algorithm>
#include <utility>

FlatMap::FlatMap() = default;

FlatMap::~FlatMap() = default;

FlatMap::FlatMap(const FlatMap& b) : data(b.data) {}

FlatMap::FlatMap(FlatMap&& b) noexcept : data(std::move(b.data)) {}

void FlatMap::swap(FlatMap& b) {
    data.swap(b.data);
}

FlatMap& FlatMap::operator=(const FlatMap& b) {
    if (this != &b) {
        data = b.data;
    }
    return *this;
}

FlatMap& FlatMap::operator=(FlatMap&& b) noexcept {
    if (this != &b) {
        data = std::move(b.data);
    }
    return *this;
}

void FlatMap::clear() {
    data.clear();
}

bool FlatMap::erase(const Key& k) {
    auto it = std::lower_bound(data.begin(), data.end(), std::make_pair(k, Value()), 
                               [](const auto& lhs, const auto& rhs) { return lhs.first < rhs.first; });
    if (it != data.end() && it->first == k) {
        data.erase(it);
        return true;
    }
    return false; 
}

// упорядоен масссив
bool FlatMap::insert(const Key& k, const Value& v) {
    auto it = std::lower_bound(data.begin(), data.end(), std::make_pair(k, Value()), 
                               [](const auto& lhs, const auto& rhs) { return lhs.first < rhs.first; });
    if (it != data.end() && it->first == k) {
        return false; 
    }
    data.insert(it, {k, v});
    return true;
}


bool FlatMap::contains(const Key& k) const {
    auto it = std::lower_bound(data.begin(), data.end(), std::make_pair(k, Value()), 
                               [](const auto& lhs, const auto& rhs) { return lhs.first < rhs.first; });
    return (it != data.end() && it->first == k);
}

Value& FlatMap::operator[](const Key& k) {
    auto it = std::lower_bound(data.begin(), data.end(), std::make_pair(k, Value()), 
                               [](const auto& lhs, const auto& rhs) { return lhs.first < rhs.first; });
    if (it != data.end() && it->first == k) {
        return it->second; 
    }
    data.insert(it, {k, Value()});
    return data.back().second;
}

Value& FlatMap::at(const Key& k) {
    auto it = std::lower_bound(data.begin(), data.end(), std::make_pair(k, Value()), 
                               [](const auto& lhs, const auto& rhs) { return lhs.first < rhs.first; });
    if (it != data.end() && it->first == k) {
        return it->second; 
    }
    throw std::runtime_error("Key not found");
}

const Value& FlatMap::at(const Key& k) const {
    auto it = std::lower_bound(data.begin(), data.end(), std::make_pair(k, Value()), 
                               [](const auto& lhs, const auto& rhs) { return lhs.first < rhs.first; });
    if (it != data.end() && it->first == k) {
        return it->second; 
    }
    throw std::runtime_error("Key not found");
}

size_t FlatMap::size() const {
    return data.size();
}

bool FlatMap::empty() const {
    return data.empty();
}

bool operator==(const FlatMap& a, const FlatMap& b) {
    return a.data == b.data;
}

bool operator!=(const FlatMap& a, const FlatMap& b) {
    return !(a == b);
}
