#pragma once

#include <string>
#include <stdexcept>
#include "vector.cpp"

typedef std::string Key;
struct Value {
    unsigned age;
    unsigned weight;
};

class FlatMap {
public:
    
    FlatMap();

    ~FlatMap();

    FlatMap(const FlatMap& b);

    FlatMap(FlatMap&& b) noexcept;

    void swap(FlatMap& b);

    FlatMap& operator=(const FlatMap& b);

    FlatMap& operator=(FlatMap&& b) noexcept;

    void clear();

    bool erase(const Key& k);

    bool insert(const Key& k, const Value& v);

    bool contains(const Key& k) const;
     
    Value& operator[](const Key& k);

    Value& at(const Key& k);

    const Value& at(const Key& k) const;

    size_t size() const;

    bool empty() const;

    friend bool operator==(const FlatMap& a, const FlatMap& b);

    friend bool operator!=(const FlatMap& a, const FlatMap& b);

private:
    Vector<std::pair<Key, Value>> data;
};
