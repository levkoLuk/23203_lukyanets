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
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].first == k) {
            data.erase(i);
            return true;
        }
    }
    return false;
}

bool FlatMap::insert(const Key& k, const Value& v) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].first == k) {
            return false; // Key already exists
        }
    }
    data.push_back({k, v});
    return true;
}

bool FlatMap::contains(const Key& k) const {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].first == k) {
            return true;
        }
    }
    return false;
}

Value& FlatMap::operator[](const Key& k) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].first == k) {
            return data[i].second;
        }
    }
    // Insert default-constructed Value if key is not found
    data.push_back({k, Value()});
    return data.back().second;
}

Value& FlatMap::at(const Key& k) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].first == k) {
            return data[i].second;
        }
    }
    throw std::runtime_error("Key not found");
}

const Value& FlatMap::at(const Key& k) const {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].first == k) {
            return data[i].second;
        }
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
