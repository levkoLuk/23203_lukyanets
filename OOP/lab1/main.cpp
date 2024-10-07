#include "flatmap.h"
#include <iostream>
#include <stdexcept>

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
    size_t index = findIndex(k);
    if (index < data.size()) {
        data.erase(index);
        return true;
    }
    return false;
}

bool FlatMap::insert(const Key& k, const Value& v) {
    size_t index = findIndex(k);
    if (index < data.size()) {
        return false; // Key already exists
    }
    data.push_back({k, v});
    return true;
}

bool FlatMap::contains(const Key& k) const {
    return findIndex(k) < data.size();
}

Value& FlatMap::operator[](const Key& k) {
    size_t index = findIndex(k);
    if (index < data.size()) {
        return data[index].value;
    }
    // Insert default value if key does not exist
    data.push_back({k, Value{}});
    return data.back().value;
}

Value& FlatMap::at(const Key& k) {
    size_t index = findIndex(k);
    if (index >= data.size()) {
        throw std::runtime_error("Key not found");
    }
    return data[index].value;
}

const Value& FlatMap::at(const Key& k) const {
    size_t index = findIndex(k);
    if (index >= data.size()) {
        throw std::runtime_error("Key not found");
    }
    return data[index].value;
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
